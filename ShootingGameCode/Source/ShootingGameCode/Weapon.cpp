// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"// Replicated 처리에서 DOREPLIFETIME 기능을 가지고 있는 라이브러리
#include "GameFramework/SpringArmComponent.h"
#include "ShootingHUD.h"

// Sets default values
AWeapon::AWeapon():Ammo(30)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetCollisionProfileName("OverlapAllDynamic");

	bReplicates = true;
	SetReplicateMovement(true);

	SetRootComponent(WeaponMesh);
}

// GetLifetimeReplicatedProps : Replicated 변수의 코드를 연결하는 영역
void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeapon, m_pChar);
	DOREPLIFETIME(AWeapon, Ammo);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::EventTrigger_Implementation()
{
	if (IsValid(ShootMontage) == false)
		return;

	m_pChar->PlayAnimMontage(ShootMontage);
}

void AWeapon::EventShoot_Implementation()
{
	if (FireEffect == nullptr)
		return;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), FireEffect,
		WeaponMesh->GetSocketLocation("muzzle"),
		WeaponMesh->GetSocketRotation("muzzle"),
		FVector(0.2f, 0.2f, 0.2f));

	ACharacter* pPlayer0 = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (pPlayer0 != m_pChar)
		return;

	FVector vStart;
	FVector vEnd;
	CalcShootStartEndPos(vStart, vEnd);
	// 여기 아래 부터는 vStart, vEnd 값이 계산되서 들어가 있다.

	// GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, TEXT("(Client)ReqApplyDamage"));
	ReqApplyDamage(vStart, vEnd);
}

void AWeapon::ReqApplyDamage_Implementation(FVector vStart, FVector vEnd)
{
	// GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, TEXT("(Server)ReqApplyDamage"));
	UseAmmo();

	FCollisionObjectQueryParams collisionObjs;
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_PhysicsBody);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_Vehicle);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_Destructible);

	FCollisionQueryParams collisionQuery; // 컬리전 채크 추가 옵션
	collisionQuery.AddIgnoredActor(m_pChar); // 히트 채크시 무시할 액터 추가 

	FHitResult result;
	bool itHit = GetWorld()->LineTraceSingleByObjectType(result, vStart, vEnd, collisionObjs, collisionQuery);
	DrawDebugLine(GetWorld(), vStart, vEnd, FColor::Red, false, 5.0f);
	if (itHit == false)
		return;

	ACharacter* pHitChar = Cast<ACharacter>(result.GetActor());
	if (pHitChar == nullptr)// pHitChar가 nullptr 이라는 건 result.GetActor()가 캐릭터가 아니다.
		return;

	UGameplayStatics::ApplyDamage(pHitChar, 10.0f, m_pChar->GetController(), this, UDamageType::StaticClass());
}

void AWeapon::OnRep_Ammo()
{
	APlayerController* pPlayer = GetWorld()->GetFirstPlayerController();
	if (IsValid(pPlayer) == false)
		return;

	AShootingHUD* pHud = Cast<AShootingHUD>(pPlayer->GetHUD());
	if (IsValid(pHud) == false)
		return;

	pHud->OnUpdateMyAmmo(Ammo);
}

void AWeapon::CalcShootStartEndPos(FVector& vStart, FVector& vEnd)
{
	if (IsValid(m_pChar) == false)
		return;

	USpringArmComponent* pArm = Cast<USpringArmComponent>(m_pChar->GetComponentByClass(USpringArmComponent::StaticClass()));
	if (IsValid(pArm) == false)
		return;

	APlayerController* pPlayer = GetWorld()->GetFirstPlayerController();// Player index 0번
	FVector vCameraLoc = pPlayer->PlayerCameraManager->GetCameraLocation();
	FVector vCameraForward = pPlayer->PlayerCameraManager->GetActorForwardVector();

	vStart = (vCameraForward * (pArm->TargetArmLength + 100)) + vCameraLoc;
	vEnd = (vCameraForward * 10000) + vCameraLoc;
}

void AWeapon::UseAmmo()
{
	Ammo -= 1;
	Ammo = FMath::Clamp(Ammo, 0, 30);
	OnRep_Ammo();
}

