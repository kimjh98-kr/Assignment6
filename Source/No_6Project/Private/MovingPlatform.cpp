// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Math/UnrealMathUtility.h"
// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);

	MoveSpeed = 100.0f;
	MaxRange = 300.0f;
	MoveDirection = 1;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재 X 위치와 이동할 거리 계산
	const float CurrentX = GetActorLocation().X;
	const float DeltaMovement = MoveSpeed * DeltaTime * MoveDirection;
	float NewX = CurrentX + DeltaMovement;

	// 시작 위치로부터 X축 기준 거리 계산
	const float DistanceFromStart = FMath::Abs(NewX - StartLocation.X);
	if (DistanceFromStart > MaxRange)
	{
		// 초과된 거리 보정: 초과분 만큼 빼고, 이동 방향 반전
		const float Overshoot = DistanceFromStart - MaxRange;
		NewX -= Overshoot * MoveDirection;
		MoveDirection *= -1;
	}

	// Y, Z 좌표는 그대로 유지하며 X 좌표 업데이트
	FVector NewLocation = GetActorLocation();
	NewLocation.X = NewX;
	SetActorLocation(NewLocation);
}

