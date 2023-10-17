// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public/Tools/InterfacePlayObj.h"
#include "MoveRect.generated.h"

UENUM(BlueprintType)// �𸮾� ENUM�� �������Ʈ������ ��밡���ϵ��� ���� 
enum class EN_MoveTypeCode : uint8
{
	// MoveRight(c++���� ����ϴ� �̸�), UMETA �ɼ��� DisplayName = "Right"�� �������Ʈ���� ������ �̸�
	MoveRight UMETA(DisplayName = "Right"),
	// MoveUp(c++���� ����ϴ� �̸�), UMETA �ɼ��� DisplayName = "Up"�� �������Ʈ���� ������ �̸�
	MoveUp UMETA(DisplayName = "Up"),
	// MoveLeft(c++���� ����ϴ� �̸�), UMETA �ɼ��� DisplayName = "Left"�� �������Ʈ���� ������ �̸�
	MoveLeft UMETA(DisplayName = "Left"),
	// MoveDown(c++���� ����ϴ� �̸�), UMETA �ɼ��� DisplayName = "Down"�� �������Ʈ���� ������ �̸�
	MoveDown UMETA(DisplayName = "Down"),
};


UCLASS()
class UNREALCODE_API AMoveRect : public AActor, public IInterfacePlayObj
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveRect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool IsPlay);// �������Ʈ ȣ��� �Լ��� ����

	virtual void Code_DoPlay_Implementation(bool IsPlay) override;// c++���� ����� �Լ�

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	EN_MoveTypeCode m_MoveType;
	float m_fLocX;
	float m_fLocZ;
	bool m_IsPlay;
};
