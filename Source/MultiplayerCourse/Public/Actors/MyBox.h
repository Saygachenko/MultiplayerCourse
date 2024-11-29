﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBox.generated.h"

UCLASS()
class MULTIPLAYERCOURSE_API AMyBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyBox();

protected:
	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 ReplicatedVar = 100;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
