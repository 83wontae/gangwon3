// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ShootingGameCodeCharacter.generated.h"


UCLASS(config=Game)
class AShootingGameCodeCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Test Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* TestAction;

	/** Test Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ReloadAction;

	/** Shoot Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ShootAction;

public:
	AShootingGameCodeCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			
	/** Called for Test input */
	void Test(const FInputActionValue& Value);

	/** Called for Test input */
	void Reload(const FInputActionValue& Value);

	/** Called for Test input */
	void Shoot(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

public:
	// https://docs.unrealengine.com/4.27/ko/InteractiveExperiences/Networking/Actors/RPCs/
	// Server : �������� ����
	// Reliable : �ŷڼ�
	UFUNCTION(Server, Reliable)
	void ReqTestMsg();

	// NetMulticast : ��ο��� ����
	UFUNCTION(NetMulticast, Reliable)
	void ResTestMsg();

	// Client : �������� Ŭ���̾�Ʈ���� ����
	UFUNCTION(Client, Reliable)
	void ResTestMsgToOwner();

	// Server : �������� ����
	// Reliable : �ŷڼ�
	UFUNCTION(Server, Reliable)
	void ReqReload();

	// NetMulticast : ��ο��� ����
	UFUNCTION(NetMulticast, Reliable)
	void ResReload();

	// Server : �������� ����
	// Reliable : �ŷڼ�
	UFUNCTION(Server, Reliable)
	void ReqShoot();

	// NetMulticast : ��ο��� ����
	UFUNCTION(NetMulticast, Reliable)
	void ResShoot();

public:
	UFUNCTION(BlueprintCallable)
	void TestWeaponSpawn(TSubclassOf<class AWeapon> WeaponClass);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* ShootMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* ReloadMontage;

	UPROPERTY(Replicated)
	FRotator m_LookAtRotation;

	UFUNCTION(BlueprintPure)
	FRotator GetLookAtRotation() { return m_LookAtRotation; };
};

