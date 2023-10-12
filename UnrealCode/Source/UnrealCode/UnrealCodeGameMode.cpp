// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCodeGameMode.h"
#include "UnrealCodeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealCodeGameMode::AUnrealCodeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
