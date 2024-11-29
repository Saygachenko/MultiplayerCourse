// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerCourse/Public/Levels/MultiplayerCourseGameMode.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerCourseGameMode::AMultiplayerCourseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMultiplayerCourseGameMode::HostLANGame()
{
	GetWorld()->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void AMultiplayerCourseGameMode::JoinLANGame()
{
	APlayerController* FirstPlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if (FirstPlayerController)
	{
		FirstPlayerController->ClientTravel("192.168.0.208", TRAVEL_Absolute);
	}
}