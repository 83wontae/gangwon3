// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingPlayerState.h"
#include "Net/UnrealNetwork.h"// Replicated ó������ DOREPLIFETIME ����� ������ �ִ� ���̺귯��

AShootingPlayerState::AShootingPlayerState():m_CurHp(100)
{
}

// GetLifetimeReplicatedProps : Replicated ������ �ڵ带 �����ϴ� ����
void AShootingPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AShootingPlayerState, m_CurHp);
}

void AShootingPlayerState::AddDamage(float Damage)
{
	m_CurHp = m_CurHp - Damage;
	OnRep_CurHp();
}

void AShootingPlayerState::OnRep_CurHp()
{
	GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, 
		FString::Printf(TEXT("OnRep_CurHp CurHp=%f"), m_CurHp));

	if (Event_Dele_UpdateHp.IsBound())
		Event_Dele_UpdateHp.Broadcast(m_CurHp, 100);
}
