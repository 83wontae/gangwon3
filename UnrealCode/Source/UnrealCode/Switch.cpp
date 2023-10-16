// Fill out your copyright notice in the Description page of Project Settings.


#include "Switch.h"
#include "MoveLeftRight.h"
#include "MoveRect.h"
#include "Public/Tools/InterfacePlayObj.h"

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ASwitch::OnSwitchBeginOverlap);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ASwitch::OnSwitchEndOverlap);
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASwitch::OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Print String ���
	// -1 : ���� Ű ���� �ִ´� Ư���� ������ -1
	// 10.0f : ��� �ð�
	// FColor::Green : �ؽ�Ʈ ����
	// TEXT("BeginOverlap") : ����� �ؽ�Ʈ
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	// IsValid : �𸮾󿡼� ���� �ȿ� ��ä�� �����ϴ��� �ı������� �� Ȯ���ؼ� 
	// ���� �ȿ� ��ü�� ���������� ���� äũ�ϴ� ���
	// if (IsValid(leftright) == false)
	//	return;

	// leftright->IsPlay = true;

	//for (int i = 0; i < leftright.Num(); ++i)
	//{
	//	leftright[i]->IsPlay = true;// leftright ������ �迭 �̱⶧���� "->"�� ����ؼ� ����
	//}

	//for (AMoveLeftRight* pActor : leftright)
	//{
	//	pActor->IsPlay = true;
	//}

	//for (AMoveRect* pActor : rect)
	//{
	//	pActor->IsPlay = true;
	//}

	for (AActor* pActor : Actors)
	{
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);// ����� Interface Casting(����ȯ)
		if (InterfaceObj)
		{
			// Interface Casting(����ȯ) ������ Execute_(function name)���� Interface �Լ� ȣ��
			// Execute_(function name)�� ù��° �Ķ��Ÿ�� �Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ��Ÿ
			InterfaceObj->Execute_Code_DoPlay(pActor, true);
		}
	}
}

void ASwitch::OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//if (IsValid(leftright) == false)// IsValid : �𸮾󿡼� ��ü�� ��ȿ ���� äũ ���
	//	return;

	//leftright->IsPlay = false;

	//for (AMoveLeftRight* pActor : leftright)
	//{
	//	pActor->IsPlay = false;
	//}

	//for (AMoveRect* pActor : rect)
	//{
	//	pActor->IsPlay = false;
	//}

	for (AActor* pActor : Actors)
	{
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);// ����� Interface Casting(����ȯ)
		if (InterfaceObj)
		{
			// Interface Casting(����ȯ) ������ Execute_(function name)���� Interface �Լ� ȣ��
			// Execute_(function name)�� ù��° �Ķ��Ÿ�� �Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ��Ÿ
			InterfaceObj->Execute_Code_DoPlay(pActor, false);
		}
	}
}

