// Fill out your copyright notice in the Description page of Project Settings.


#include "UdpReceiver.h"
#include "UnrealString.h"
#include "json11.hpp"

// Sets default values
AUdpReceiver::AUdpReceiver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUdpReceiver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUdpReceiver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/* ポートを開き受信開始 */
bool AUdpReceiver::Connect()
{
	if (m_Socket == NULL) {
		m_Socket = FUdpSocketBuilder(TEXT("Mocap UDP socket"))
			.BoundToPort(this->Port)
			.Build();
	}

	if (m_Socket != NULL) {
		/* UDP受信を開始 */
		m_Receiver = new FUdpSocketReceiver(m_Socket, FTimespan(0, 0, 1), TEXT("UDP receiver"));
		m_Receiver->OnDataReceived().BindUObject(this, &AUdpReceiver::UdpReceivedCallback);
		m_Receiver->Start();

		// 接続成功
		UE_LOG(LogTemp, Log, TEXT("Connected to UDP port %d"), this->Port);
		return true;
	}

	// 接続失敗
	UE_LOG(LogTemp, Warning, TEXT("Could not open UDP port %d"), this->Port);
	return false;
}

/*  受信を終了してポートを閉じる */
void AUdpReceiver::Close()
{
	if (m_Receiver != NULL) {
		m_Receiver->Stop();
		m_Receiver->Exit();
		delete m_Receiver;
		m_Receiver = NULL;
	}

	if (m_Socket != NULL) {
		m_Socket->Close();
		delete m_Socket;
		m_Socket = NULL;
	}
}

FString BytesToStringFixed(const uint8 *In, int32 Count)
{
	FString Broken = BytesToString(In, Count);
	FString Fixed;

	for (int i = 0; i < Broken.Len(); i++)
	{
		const TCHAR c = Broken[i] - 1;
		Fixed.AppendChar(c);
	}

	return Fixed;
}

/*  UDPでデータが届いた際のコールバック */
void AUdpReceiver::UdpReceivedCallback(const FArrayReaderPtr& data, const FIPv4Endpoint&)
{
	uint32 receivedSize = data->GetAllocatedSize();

	FString DataStr = BytesToStringFixed(data->GetData(), data->Num());

	std::string err;
	auto json = json11::Json::parse(TCHAR_TO_UTF8(*DataStr), err);
	playerIsJumping = json["isJumping"].bool_value();
	playerSpeed = json["playerSpeed"].number_value();
	playerPos = json["playerPos"].number_value();
	UE_LOG(LogTemp, Log, TEXT("playerSpeed:%f,\tplayerPos:%f,\tplayerisJumping:%s"), playerSpeed, playerPos, playerIsJumping ? "1":"2")

	UE_LOG(LogTemp, Log, TEXT("%d bytes received!\tmessage:%s"), receivedSize, *DataStr);
}

float AUdpReceiver::GetSpeed() {
	return playerSpeed;
}

float AUdpReceiver::GetPos() {
	return playerPos;
}

bool AUdpReceiver::GetIsJumping() {
	return playerIsJumping;
}