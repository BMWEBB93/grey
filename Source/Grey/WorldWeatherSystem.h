// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	virtual TStatId GetStatId() const override;

	// Time variables
	float Seconds; 
	int32 Minutes;
	int32 Hours = 12.f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeRate");
	float TimeRate = 60.f;

};
