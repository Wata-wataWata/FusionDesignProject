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

	/* UDP�f�[�^���͂����ۂɌĂ΂��R�[���o�b�N */
	void UdpReceivedCallback(const FArrayReaderPtr& data, const FIPv4Endpoint& ip);

public:
	/* UDP�҂��󂯃|�[�g�ԍ� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UDP")
		int32 Port = 5000;

	/* �|�[�g���J���Ď�M�҂��ɂ��܂� */
	UFUNCTION(BlueprintCallable, Category = "UDP")
		bool Connect();

	/* �|�[�g����Ď�M���I�����܂� */
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
