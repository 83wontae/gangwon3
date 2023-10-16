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
	// Print String 기능
	// -1 : 에러 키 값을 넣는다 특별히 없으면 -1
	// 10.0f : 출력 시간
	// FColor::Green : 텍스트 색상
	// TEXT("BeginOverlap") : 출력할 텍스트
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	// IsValid : 언리얼에서 가로 안에 객채가 존재하는지 파괴중인지 등 확인해서 
	// 가로 안에 객체가 정상적이지 여부 채크하는 기능
	// if (IsValid(leftright) == false)
	//	return;

	// leftright->IsPlay = true;

	//for (int i = 0; i < leftright.Num(); ++i)
	//{
	//	leftright[i]->IsPlay = true;// leftright 포인터 배열 이기때문에 "->"를 사용해서 참조
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
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);// 상속한 Interface Casting(형변환)
		if (InterfaceObj)
		{
			// Interface Casting(형변환) 성공후 Execute_(function name)으로 Interface 함수 호출
			// Execute_(function name)에 첫번째 파라메타는 함수 호출 대상 객체, 이후는 함수 파라메타
			InterfaceObj->Execute_Code_DoPlay(pActor, true);
		}
	}
}

void ASwitch::OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//if (IsValid(leftright) == false)// IsValid : 언리얼에서 객체의 유효 여부 채크 기능
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
		IInterfacePlayObj* InterfaceObj = Cast<IInterfacePlayObj>(pActor);// 상속한 Interface Casting(형변환)
		if (InterfaceObj)
		{
			// Interface Casting(형변환) 성공후 Execute_(function name)으로 Interface 함수 호출
			// Execute_(function name)에 첫번째 파라메타는 함수 호출 대상 객체, 이후는 함수 파라메타
			InterfaceObj->Execute_Code_DoPlay(pActor, false);
		}
	}
}

