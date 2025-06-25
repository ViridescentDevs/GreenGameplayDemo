// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayDemoGameMode.h"
#include "GameplayDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameplayDemoGameMode::AGameplayDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
