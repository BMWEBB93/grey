// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Subsystems/WorldSubsystem.h"
#include "WorldWeatherSystem.generated.h"

/**
 * 
 */
UCLASS()
class GREY_API UWorldWeatherSystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual TStatId GetStatId() const override;

	// Time variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeOfDay");
	float Hours = 0.f;

	// Player Reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player");
	APlayerCharacter *Player;

	// Weather 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snow")
	UNiagaraSystem* Snow;

	UPROPERTY()
	UNiagaraComponent* SnowComp;


	

};
