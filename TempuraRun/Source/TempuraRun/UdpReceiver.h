// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sockets.h"
#include "Networking.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UdpReceiver.generated.h"

UCLASS()
class TEMPURARUN_API AUdpReceiver : public AActor
{
	GENERATED_BODY()

		FSocket* m_Socket;
	FUdpSocketReceiver* m_Receiver;

	/* UDP繝・・繧ｿ縺悟ｱ翫＞縺滄圀縺ｫ蜻ｼ縺ｰ繧後ｋ繧ｳ繝ｼ繝ｫ繝舌ャ繧ｯ */
	void UdpReceivedCallback(const FArrayReaderPtr& data, const FIPv4Endpoint& ip);

public:
	/* UDP蠕・■蜿励￠繝昴・繝育分蜿ｷ */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UDP")
		int32 Port = 5000;

	/* 繝昴・繝医ｒ髢九＞縺ｦ蜿嶺ｿ｡蠕・■縺ｫ縺励∪縺・*/
	UFUNCTION(BlueprintCallable, Category = "UDP")
		bool Connect();

	/* 繝昴・繝医ｒ髢峨§縺ｦ蜿嶺ｿ｡繧堤ｵゆｺ・＠縺ｾ縺・*/
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
