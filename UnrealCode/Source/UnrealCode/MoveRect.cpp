// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRect.h"

// Sets default values
AMoveRect::AMoveRect(): m_MoveType(EN_MoveTypeCode::MoveRight), m_fLocX(0), m_fLocZ(0), m_IsPlay(false)
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

	if (m_IsPlay == false)
		return;

	switch (m_MoveType)
	{
	case EN_MoveTypeCode::MoveRight:
		m_fLocX += 1.0f;
		StaticMesh->SetRelativeLocation(FVector(m_fLocX, 0, m_fLocZ));
		if (m_fLocX >= 100) m_MoveType = EN_MoveTypeCode::MoveUp;
		break;
	case EN_MoveTypeCode::MoveUp:
		m_fLocZ += 1.0f;
		StaticMesh->SetRelativeLocation(FVector(m_fLocX, 0, m_fLocZ));
		if (m_fLocZ >= 100) m_MoveType = EN_MoveTypeCode::MoveLeft;
		break;
	case EN_MoveTypeCode::MoveLeft:
		m_fLocX -= 1.0f;
		StaticMesh->SetRelativeLocation(FVector(m_fLocX, 0, m_fLocZ));
		if (m_fLocX <= 0) m_MoveType = EN_MoveTypeCode::MoveDown;
		break;
	case EN_MoveTypeCode::MoveDown:
		m_fLocZ -= 1.0f;
		StaticMesh->SetRelativeLocation(FVector(m_fLocX, 0, m_fLocZ));
		if (m_fLocZ <= 0)	m_MoveType = EN_MoveTypeCode::MoveRight;
		break;
	}
}

void AMoveRect::Code_DoPlay_Implementation(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

