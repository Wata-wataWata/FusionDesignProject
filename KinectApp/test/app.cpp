#include "app.h"
#include "util.h"
#include "json11.hpp"

#include <thread>
#include <chrono>
#include <iostream>

#include <ppl.h>
#include <string>

// Constructor
Kinect::Kinect()
    :udp0("192.168.37.17", 5000)
{
    // Initialize
    initialize();
}

// Destructor
Kinect::~Kinect()
{
    // Finalize
    finalize();
}

// Processing
void Kinect::run()
{

    std::cout << std::endl << std::endl;
    // Main Loop
    while (true) {
        // Update Data
        update();

        // Draw Data
        draw();

        // Show Data
        show();
        
        updateMainPlayer();

        std::cout << "\033[1A\033[3K\r" << "mainPlayer: " << mainPlayer <<
            "\tPlayerPos: " << playerPos << std::endl <<
            "\033[2K" << "FootLine: " << footLine <<
            "\tplayerSpeed:" << playerSpeed << "\tisJumping:" << (playerIsJumping ? "TRUE" : "FALSE");

        // Send Data
        // udp0.SendHello();
        // jsonでデータ成型
        json11::Json json = json11::Json::object({
            {"playerPos", playerPos},
            {"isJumping", playerIsJumping},
            {"playerSpeed", playerSpeed}
            });
        udp0.SendString(json.dump());

        // Key Check
        const int key = cv::waitKey(10);
        if (key == VK_ESCAPE) {
            break;
        }
        if (key == 'r') {
            resetMainPlayer();
        }
        if (key == 's') {
            setFootLine();
        }
    }   
}

// Initialize
void Kinect::initialize()
{
    cv::setUseOptimized(true);

    // Initialize Sensor
    initializeSensor();

    // Initialize Color
    initializeColor();

    // Initialize Body
    initializeBody();

    // Wait a Few Seconds until begins to Retrieve Data from Sensor ( about 2000-[ms] )
    std::this_thread::sleep_for(std::chrono::seconds(2));


}

// Initialize Sensor
inline void Kinect::initializeSensor()
{
    // Open Sensor
    ERROR_CHECK(GetDefaultKinectSensor(&kinect));

    ERROR_CHECK(kinect->Open());

    // Check Open
    BOOLEAN isOpen = FALSE;
    ERROR_CHECK(kinect->get_IsOpen(&isOpen));
    if (!isOpen) {
        throw std::runtime_error("failed IKinectSensor::get_IsOpen( &isOpen )");
    }

    // Retrieve Coordinate Mapper
    ERROR_CHECK(kinect->get_CoordinateMapper(&coordinateMapper));
}

// Initialize Color
inline void Kinect::initializeColor()
{
    // Open Color Reader
    ComPtr<IColorFrameSource> colorFrameSource;
    ERROR_CHECK(kinect->get_ColorFrameSource(&colorFrameSource));
    ERROR_CHECK(colorFrameSource->OpenReader(&colorFrameReader));

    // Retrieve Color Description
    ComPtr<IFrameDescription> colorFrameDescription;
    ERROR_CHECK(colorFrameSource->CreateFrameDescription(ColorImageFormat::ColorImageFormat_Bgra, &colorFrameDescription));
    ERROR_CHECK(colorFrameDescription->get_Width(&colorWidth)); // 1920
    ERROR_CHECK(colorFrameDescription->get_Height(&colorHeight)); // 1080
    ERROR_CHECK(colorFrameDescription->get_BytesPerPixel(&colorBytesPerPixel)); // 4

    // Allocation Color Buffer
    colorBuffer.resize(colorWidth * colorHeight * colorBytesPerPixel);
}

// Initialize Body
inline void Kinect::initializeBody()
{
    // Open Body Reader
    ComPtr<IBodyFrameSource> bodyFrameSource;
    ERROR_CHECK(kinect->get_BodyFrameSource(&bodyFrameSource));
    ERROR_CHECK(bodyFrameSource->OpenReader(&bodyFrameReader));

    // Initialize Body Buffer
    Concurrency::parallel_for_each(bodies.begin(), bodies.end(), [](IBody*& body) {
        SafeRelease(body);
        });

    // Color Table for Visualization
    colors[0] = cv::Vec3b(255, 0, 0); // Blue
    colors[1] = cv::Vec3b(0, 255, 0); // Green
    colors[2] = cv::Vec3b(0, 0, 255); // Red
    colors[3] = cv::Vec3b(255, 255, 0); // Cyan
    colors[4] = cv::Vec3b(255, 0, 255); // Magenta
    colors[5] = cv::Vec3b(0, 255, 255); // Yellow
}

// Finalize
void Kinect::finalize()
{
    cv::destroyAllWindows();

    // Release Body Buffer
    Concurrency::parallel_for_each(bodies.begin(), bodies.end(), [](IBody*& body) {
        SafeRelease(body);
        });

    // Close Sensor
    if (kinect != nullptr) {
        kinect->Close();
    }
}

// Update Data
void Kinect::update()
{
    // Update Color
    updateColor();

    // Update Body
    updateBody();
}

// Update Color
inline void Kinect::updateColor()
{
    // Retrieve Color Frame
    ComPtr<IColorFrame> colorFrame;
    const HRESULT ret = colorFrameReader->AcquireLatestFrame(&colorFrame);
    if (FAILED(ret)) {
        return;
    }

    // Convert Format ( YUY2 -> BGRA )
    ERROR_CHECK(colorFrame->CopyConvertedFrameDataToArray(static_cast<UINT>(colorBuffer.size()), &colorBuffer[0], ColorImageFormat::ColorImageFormat_Bgra));
}

// Update Body
inline void Kinect::updateBody()
{
    // Retrieve Body Frame
    ComPtr<IBodyFrame> bodyFrame;
    const HRESULT ret = bodyFrameReader->AcquireLatestFrame(&bodyFrame);
    if (FAILED(ret)) {
        return;
    }

    // Release Previous Bodies
    Concurrency::parallel_for_each(bodies.begin(), bodies.end(), [](IBody*& body) {
        SafeRelease(body);
        });

    // Retrieve Body Data
    ERROR_CHECK(bodyFrame->GetAndRefreshBodyData(static_cast<UINT>(bodies.size()), &bodies[0]));
}

// Draw Data
void Kinect::draw()
{
    // Draw Color
    drawColor();

    // Draw Body
    drawBody();
}

// Draw Color
inline void Kinect::drawColor()
{
    // Create cv::Mat from Color Buffer
    colorMat = cv::Mat(colorHeight, colorWidth, CV_8UC4, &colorBuffer[0]);
}

// Draw Body
inline void Kinect::drawBody()
{
    // Draw Body Data to Color Data
    Concurrency::parallel_for(0, BODY_COUNT, [&](const int count) {
        const ComPtr<IBody> body = bodies[count];
        if (body == nullptr) {
            return;
        }

        // Check Body Tracked
        BOOLEAN tracked = FALSE;
        ERROR_CHECK(body->get_IsTracked(&tracked));
        if (!tracked) {
            return;
        }
        if (mainPlayer < 0) {
            mainPlayer = count;
        }

        // Retrieve Joints
        std::array<Joint, JointType::JointType_Count> joints;
        ERROR_CHECK(body->GetJoints(static_cast<UINT>(joints.size()), &joints[0]));

        Concurrency::parallel_for_each(joints.begin(), joints.end(), [&](const Joint& joint) {
            // Check Joint Tracked
            if (joint.TrackingState == TrackingState::TrackingState_NotTracked) {
                return;
            }

            // Draw Joint Position
            drawEllipse(colorMat, joint, 5, colors[count]);

            /*
            if (count == mainPlayer) {

                // ケツの位置を探したい
                if (joint.JointType == JointType::JointType_SpineBase) {
                    ColorSpacePoint colorSpacePoint = { 0 };
                    coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
                    // std::cout << "SpineBase ---> x:" << colorSpacePoint.X << "\ty:" << colorSpacePoint.Y << std::endl;
                    playerPos = colorSpacePoint.X / colorWidth;

                }

                // 右足
                if (joint.JointType == JointType::JointType_FootRight) {
                    ColorSpacePoint colorSpacePoint = { 0 };
                    coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
                    // std::cout << "FootRight ---> x:" << colorSpacePoint.X << "\ty:" << colorSpacePoint.Y << std::endl;
                }

                // 左足
                if (joint.JointType == JointType::JointType_FootLeft) {
                    ColorSpacePoint colorSpacePoint = { 0 };
                    coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
                    // std::cout << "Footleft ---> x:" << colorSpacePoint.X << "\ty:" << colorSpacePoint.Y << std::endl;
                }
            }
            */




            // Draw Left Hand State
            if (joint.JointType == JointType::JointType_HandLeft) {
                HandState handState;
                TrackingConfidence handConfidence;
                ERROR_CHECK(body->get_HandLeftState(&handState));
                ERROR_CHECK(body->get_HandLeftConfidence(&handConfidence));

                drawHandState(colorMat, joint, handState, handConfidence);
            }

            // Draw Right Hand State
            if (joint.JointType == JointType::JointType_HandRight) {
                HandState handState;
                TrackingConfidence handConfidence;
                ERROR_CHECK(body->get_HandRightState(&handState));
                ERROR_CHECK(body->get_HandRightConfidence(&handConfidence));

                drawHandState(colorMat, joint, handState, handConfidence);
            }
            });

        /*
        // Retrieve Joint Orientations
        std::array<JointOrientation, JointType::JointType_Count> orientations;
        ERROR_CHECK( body->GetJointOrientations( JointType::JointType_Count, &orientations[0] ) );
        */

        /*
        // Retrieve Amount of Body Lean
        PointF amount;
        ERROR_CHECK( body->get_Lean( &amount ) );
        */
        });
}

// Draw Ellipse
inline void Kinect::drawEllipse(cv::Mat& image, const Joint& joint, const int radius, const cv::Vec3b& color, const int thickness)
{
    if (image.empty()) {
        return;
    }

    // Convert Coordinate System and Draw Joint
    ColorSpacePoint colorSpacePoint;
    ERROR_CHECK(coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint));
    const int x = static_cast<int>(colorSpacePoint.X + 0.5f);
    const int y = static_cast<int>(colorSpacePoint.Y + 0.5f);
    if ((0 <= x) && (x < image.cols) && (0 <= y) && (y < image.rows)) {
        cv::circle(image, cv::Point(x, y), radius, static_cast<cv::Scalar>(color), thickness, cv::LINE_AA);
    }
}

// Draw Hand State
inline void Kinect::drawHandState(cv::Mat& image, const Joint& joint, HandState handState, TrackingConfidence handConfidence)
{
    if (image.empty()) {
        return;
    }

    // Check Tracking Confidence
    if (handConfidence != TrackingConfidence::TrackingConfidence_High) {
        return;
    }

    // Draw Hand State 
    const int radius = 75;
    const cv::Vec3b blue = cv::Vec3b(128, 0, 0), green = cv::Vec3b(0, 128, 0), red = cv::Vec3b(0, 0, 128);
    switch (handState) {
        // Open
    case HandState::HandState_Open:
        drawEllipse(image, joint, radius, green, 5);
        break;
        // Close
    case HandState::HandState_Closed:
        drawEllipse(image, joint, radius, red, 5);
        break;
        // Lasso
    case HandState::HandState_Lasso:
        drawEllipse(image, joint, radius, blue, 5);
        break;
    default:
        break;
    }
}

// Show Data
void Kinect::show()
{
    // Show Body
    showBody();
}

// Show Body
inline void Kinect::showBody()
{
    if (colorMat.empty()) {
        return;
    }

    // Resize Image
    cv::Mat resizeMat;
    const double scale = 0.5;
    cv::resize(colorMat, resizeMat, cv::Size(), scale, scale);

    // Show Image
    cv::imshow("Body", resizeMat);
}

void Kinect::setFootLine() {
    if (mainPlayer == -1)
    {
        return;
    }
    const ComPtr<IBody> body = bodies[mainPlayer];
    if (body == nullptr) {
        return;
    }

    // Retrieve Joints
    std::array<Joint, JointType::JointType_Count> joints;
    ERROR_CHECK(body->GetJoints(static_cast<UINT>(joints.size()), &joints[0]));

    float foot_left = -1;
    float foot_right = -1;
    float knee_left = -1;
    float knee_right = -1;
    float head = -1;

    Concurrency::parallel_for_each(joints.begin(), joints.end(), [&](const Joint& joint) {
        // Check Joint Tracked
        if (joint.TrackingState == TrackingState::TrackingState_NotTracked) {
            return;
        }

        if (joint.JointType == JointType::JointType_Head) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            head = colorSpacePoint.Y;
        }

        // 左足
        if (joint.JointType == JointType::JointType_FootLeft) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            foot_left = colorSpacePoint.Y;
        }
        // 右足
        if (joint.JointType == JointType::JointType_FootRight) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            foot_right = colorSpacePoint.Y;
        }
        // 左ひざ
        if (joint.JointType == JointType::JointType_KneeLeft) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            knee_left = colorSpacePoint.Y;
        }
        // 右ひざ
        if (joint.JointType == JointType::JointType_KneeLeft) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            knee_right = colorSpacePoint.Y;
        }
        });
    if (foot_left >= 0 && foot_right >= 0) {
        footLine = (foot_left + foot_right) / 2;
    }
    if (footLine > 0) {
        jumpLine = (foot_left + foot_right + knee_left + knee_right) / 4;
    }
    if (head != -1 and footLine != -1) {
        playerHeight = footLine - head;
    }
    return;

}

void Kinect::resetMainPlayer() {
    mainPlayer = -1;
}

bool Kinect::isJumping() {
    if (mainPlayer == -1)
    {
        return FALSE;
    }
    const ComPtr<IBody> body = bodies[mainPlayer];
    if (body == nullptr) {
        return FALSE;
    }

    // Retrieve Joints
    std::array<Joint, JointType::JointType_Count> joints;
    ERROR_CHECK(body->GetJoints(static_cast<UINT>(joints.size()), &joints[0]));

    float knee_left = -1;
    float knee_right = -1;

    Concurrency::parallel_for_each(joints.begin(), joints.end(), [&](const Joint& joint) {
        // Check Joint Tracked
        if (joint.TrackingState == TrackingState::TrackingState_NotTracked) {
            return;
        }

        if (joint.JointType == JointType::JointType_FootLeft) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            knee_left = colorSpacePoint.Y;
        }
        if (joint.JointType == JointType::JointType_FootRight) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            knee_right = colorSpacePoint.Y;
        }
        });
    if (knee_right < jumpLine && knee_left < jumpLine) {
        return TRUE;
    }
    else {
        return FALSE;
    }



}

void Kinect::updateMainPlayer() {
    if (mainPlayer == -1)
    {
        return;
    }
    const ComPtr<IBody> body = bodies[mainPlayer];
    if (body == nullptr) {
        return;
    }
    if (!playerIsJumping) {
        playerSpeed -= speedDec;
        if (playerSpeed < 0) {
            playerSpeed = 0;
        }
    }


    // Retrieve Joints
    std::array<Joint, JointType::JointType_Count> joints;
    ERROR_CHECK(body->GetJoints(static_cast<UINT>(joints.size()), &joints[0]));

    float foot_left = -1;
    float foot_right = -1;

    Concurrency::parallel_for_each(joints.begin(), joints.end(), [&](const Joint& joint) {
        // Check Joint Tracked
        if (joint.TrackingState == TrackingState::TrackingState_NotTracked) {
            return;
        }

        // ケツの位置を探したい
        if (joint.JointType == JointType::JointType_SpineBase) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            playerPos = colorSpacePoint.X / colorWidth;

        }

        if (joint.JointType == JointType::JointType_FootLeft) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            foot_left = colorSpacePoint.Y;
        }
        if (joint.JointType == JointType::JointType_FootRight) {
            ColorSpacePoint colorSpacePoint = { 0 };
            coordinateMapper->MapCameraPointToColorSpace(joint.Position, &colorSpacePoint);
            foot_right = colorSpacePoint.Y;
        }
        });
    if (foot_right < jumpLine && foot_left < jumpLine) {
        playerIsJumping = TRUE;
    }
    else {
        playerIsJumping = FALSE;
    }

    float groundLine = footLine - playerHeight * 0.1;

    if (foot_right > groundLine) {
        if (!isGroundRight) {
            playerSpeed += speedInc;
            if (playerSpeed >= 1) {
                playerSpeed = 1;
            }
        }
        isGroundRight = TRUE;
    }
    else {
        isGroundRight = FALSE;
    }
    if (foot_left > groundLine) {
        if (!isGroundLeft) {
            playerSpeed += speedInc;
            if (playerSpeed >= 1) {
                playerSpeed = 1;
            }
        }
        isGroundLeft = TRUE;
    }
    else {
        isGroundLeft = FALSE;
    }
}