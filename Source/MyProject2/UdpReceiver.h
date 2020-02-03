// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sockets.h"
#include "Networking.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UdpReceiver.generated.h"

UCLASS()
class MYPROJECT2_API AUdpReceiver : public AActor
{
	GENERATED_BODY()

	FSocket *m_Socket;
	FUdpSocketReceiver *m_Receiver;

	/* UDPデータが届いた際に呼ばれるコールバック */
	void UdpReceivedCallback(const FArrayReaderPtr& data, const FIPv4Endpoint& ip);

public:
	/* UDP待ち受けポート番号 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UDP")
		int32 Port = 5000;

	/* ポートを開いて受信待ちにします */
	UFUNCTION(BlueprintCallable, Category = "UDP")
		bool Connect();

	/* ポートを閉じて受信を終了します */
	UFUNCTION(BlueprintCallable, Category = "UDP")
		void Close();

	UFUNCTION(BlueprintCallable, Category = "Get parameter")
		float GetSpeed();

	UFUNCTION(BlueprintCallable, Category = "Get parameter")
		bool GetIsJumping();

	UFUNCTION(BlueprintCallable, Category = "Get parameter")
		float GetPos();

	// Sets default values for this actor's properties
	AUdpReceiver();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float playerPos = 0;
	float playerSpeed = 0;
	bool playerIsJumping = false;


};
