// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);

	RotationSpeed = FRotator(0.f, 45.f, 0.f);
	bUseSinScale = false;
	ScaleFrequency = 1.f;
	ScaleAmplitude = 0.2f;
}

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	InitialScale = GetActorScale3D();

	
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationSpeed * DeltaTime);

	// Sin 함수를 이용한 스케일 변화
	if (bUseSinScale)
	{
		const float Time = GetWorld()->GetTimeSeconds();
		const float SineValue = FMath::Sin(Time * 2.f * PI * ScaleFrequency);
		const float ScaleFactor = 1.f + (ScaleAmplitude * SineValue);
		SetActorScale3D(InitialScale * ScaleFactor);
	}
}

