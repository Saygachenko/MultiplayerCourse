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
	UPROPERTY(ReplicatedUsing = OnRep_ReplicatedVar, BlueprintReadWrite)
	int32 ReplicatedVar = 100;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* ParticleEffect;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UParticleSystemComponent* SpawnedEmitter = nullptr;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION(BlueprintCallable)
	void OnRep_ReplicatedVar();

	UFUNCTION(BlueprintCallable)
	void ChangeVariable();

	UFUNCTION(BlueprintCallable)
	void AuthorityDebugMessage();

	UFUNCTION(BlueprintCallable)
	void VariableEffect();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void NetMulticastRPCFunction();
};
