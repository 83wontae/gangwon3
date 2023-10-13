// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveRect.generated.h"

UENUM(BlueprintType)// 언리얼 ENUM을 블루프린트에서도 사용가능하도록 선언 
enum class EN_MoveTypeCode : uint8
{
	// MoveRight(c++에서 사용하는 이름), UMETA 옵션중 DisplayName = "Right"는 블루프린트에서 보여질 이름
	MoveRight UMETA(DisplayName = "Right"),
	// MoveUp(c++에서 사용하는 이름), UMETA 옵션중 DisplayName = "Up"는 블루프린트에서 보여질 이름
	MoveUp UMETA(DisplayName = "Up"),
	// MoveLeft(c++에서 사용하는 이름), UMETA 옵션중 DisplayName = "Left"는 블루프린트에서 보여질 이름
	MoveLeft UMETA(DisplayName = "Left"),
	// MoveDown(c++에서 사용하는 이름), UMETA 옵션중 DisplayName = "Down"는 블루프린트에서 보여질 이름
	MoveDown UMETA(DisplayName = "Down"),
};


UCLASS()
class UNREALCODE_API AMoveRect : public AActor
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	EN_MoveTypeCode MoveType;
	float fLocX;
	float fLocZ;
};
