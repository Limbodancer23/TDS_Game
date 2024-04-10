// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyTDSGameMode.h"
#include "MyTDSPlayerController.h"
#include "MyTDSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyTDSGameMode::AMyTDSGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMyTDSPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Character/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/Character/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	} 
} 