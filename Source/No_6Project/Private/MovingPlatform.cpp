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

	// ���� X ��ġ�� �̵��� �Ÿ� ���
	const float CurrentX = GetActorLocation().X;
	const float DeltaMovement = MoveSpeed * DeltaTime * MoveDirection;
	float NewX = CurrentX + DeltaMovement;

	// ���� ��ġ�κ��� X�� ���� �Ÿ� ���
	const float DistanceFromStart = FMath::Abs(NewX - StartLocation.X);
	if (DistanceFromStart > MaxRange)
	{
		// �ʰ��� �Ÿ� ����: �ʰ��� ��ŭ ����, �̵� ���� ����
		const float Overshoot = DistanceFromStart - MaxRange;
		NewX -= Overshoot * MoveDirection;
		MoveDirection *= -1;
	}

	// Y, Z ��ǥ�� �״�� �����ϸ� X ��ǥ ������Ʈ
	FVector NewLocation = GetActorLocation();
	NewLocation.X = NewX;
	SetActorLocation(NewLocation);
}

