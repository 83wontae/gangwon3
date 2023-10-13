// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switch.generated.h"

UCLASS()
class UNREALCODE_API ASwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()// 바인딩 함수는 반드시 UFUNCTION으로 만들어야 됨
	void OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	// TObjectPtr 언리얼에서 AMoveLeftRight를 상속 받은 모든 클래스를 가리킬수 있는 변수
	// EditAnywhere : 인스턴스 편집가능(레벨 배치한 인스턴스에서 디테일 창으로 편집 가능하게 보여준다)
	// class : #include 클래스를 추가하지 않고 차후에 클래스가 있을거라고 컴파일 단계에서만 알려주는 키워드
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class AMoveLeftRight> leftright;
};
