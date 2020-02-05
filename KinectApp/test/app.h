#pragma once

#include "MyUdp.h"

#include <Windows.h>
#include <Kinect.h>
#include <opencv2/opencv.hpp>
#include <string>

#include <vector>
#include <array>

#include <wrl/client.h>
using namespace Microsoft::WRL;

class Kinect
{
public:
	Kinect();
	~Kinect();

	void run();

private:
	//センサー キネクトのインターフェース
	ComPtr<IKinectSensor> kinect;

	// コーディネートマッパー(?)
	ComPtr<ICoordinateMapper> coordinateMapper;

    // Reader
    ComPtr<IColorFrameReader> colorFrameReader;
    ComPtr<IBodyFrameReader> bodyFrameReader;

    // Color Buffer
    std::vector<BYTE> colorBuffer;
    int colorWidth;
    int colorHeight;
    unsigned int colorBytesPerPixel;
    cv::Mat colorMat;

    // Body Buffer
    std::array<IBody*, BODY_COUNT> bodies = { nullptr };
    std::array<cv::Vec3b, BODY_COUNT> colors;

    // プレイヤーの位置 0～1
    float playerPos = 0;
    int mainPlayer = -1;

    float footLine = 0;
    float jumpLine = 0;
    float playerSpeed = 0;
    float speedInc = 0.15;
    float speedDec = 0.01;
    float playerHeight = 0;

    bool playerIsJumping = FALSE;
    bool isGroundRight = FALSE;
    bool isGroundLeft = FALSE;

    MyUdp udp0;

private:
    void initialize();

    inline void initializeSensor();

    inline void initializeColor();

    inline void initializeBody();

    void finalize();

    void update();

    inline void updateBody();

    inline void updateColor();

    void draw();

    // Draw Color
    inline void drawColor();

    // Draw Body
    inline void drawBody();

    // Draw Circle
    inline void drawEllipse(cv::Mat& image, const Joint& joint, const int radius, const cv::Vec3b& color, const int thickness = -1);

    // Draw Hand State
    inline void drawHandState(cv::Mat& image, const Joint& joint, HandState handState, TrackingConfidence handConfidence);

    // Show Data
    void show();

    // Show Body
    inline void showBody();

    // 足の初期位置をセット ジャンプラインもセット
    void setFootLine();

    // メインプレイヤーを-1にセット
    void resetMainPlayer();

    // メインプレイヤーはジャンプ中か？
    inline bool isJumping();

    inline void updateMainPlayer();

};
