// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerCourse/Public/Actors/MyBox.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AMyBox::AMyBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMyBox::BeginPlay()
{
	Super::BeginPlay();

	SetReplicates(true);
}

void AMyBox::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyBox, ReplicatedVar)
}

void AMyBox::OnRep_ReplicatedVar()
{
	if (HasAuthority())
	{
		FVector NewActorLocation = GetActorLocation() + FVector(0.0f, 0.0f, 100.0f);
		SetActorLocation(NewActorLocation);
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Server: OnRep_ReplicatedVar"));
	}
	else
	{
		const uint32 ClientID = GPlayInEditorID;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Client %i: OnRep_ReplicatedVar"), ClientID));
	}
}

