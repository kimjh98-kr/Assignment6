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

	// �� ������ ȸ�� �ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	FRotator RotationSpeed;

	// Sin �Լ��� ����� ������ ��ȭ�� �������� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	bool bUseSinScale;

	// Sin �ֱ� (�ʴ� �ĵ� ��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	float ScaleFrequency;

	// ������ ���� �� (����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	float ScaleAmplitude;

	// ���� ���� �� ����Ǵ� �⺻ ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scale|SinWave")
	FVector InitialScale;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
