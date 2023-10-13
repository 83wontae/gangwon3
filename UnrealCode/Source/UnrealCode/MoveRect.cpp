// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRect.h"

// Sets default values
AMoveRect::AMoveRect(): MoveType(EN_MoveTypeCode::MoveRight), fLocX(0), fLocZ(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AMoveRect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveRect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (MoveType)
	{
	case EN_MoveTypeCode::MoveRight:
		fLocX += 1.0f;
		StaticMesh->SetRelativeLocation(FVector(fLocX, 0, fLocZ));
		if (fLocX >= 100) MoveType = EN_MoveTypeCode::MoveUp;
		break;
	case EN_MoveTypeCode::MoveUp:
		fLocZ += 1.0f;
		StaticMesh->SetRelativeLocation(FVector(fLocX, 0, fLocZ));
		if (fLocZ >= 100) MoveType = EN_MoveTypeCode::MoveLeft;
		break;
	case EN_MoveTypeCode::MoveLeft:
		fLocX -= 1.0f;
		StaticMesh->SetRelativeLocation(FVector(fLocX, 0, fLocZ));
		if (fLocX <= 0) MoveType = EN_MoveTypeCode::MoveDown;
		break;
	case EN_MoveTypeCode::MoveDown:
		fLocZ -= 1.0f;
		StaticMesh->SetRelativeLocation(FVector(fLocX, 0, fLocZ));
		if (fLocZ <= 0)	MoveType = EN_MoveTypeCode::MoveRight;
		break;
	}
}

