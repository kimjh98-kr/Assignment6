// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class NO_6PROJECT_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPlatform();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	// 매 프레임 회전 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	FRotator RotationSpeed;

	// Sin 함수를 사용해 스케일 변화를 적용할지 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	bool bUseSinScale;

	// Sin 주기 (초당 파동 수)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	float ScaleFrequency;

	// 스케일 변동 폭 (진폭)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	float ScaleAmplitude;

	// 게임 시작 시 저장되는 기본 스케일
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scale|SinWave")
	FVector InitialScale;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
