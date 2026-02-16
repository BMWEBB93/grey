// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldWeatherSystem.h"

void UWorldWeatherSystem::Tick(float DeltaTime)
{
  

    
}

void UWorldWeatherSystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    if (Snow && Player)
    {
	        SnowComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
            Snow,
            Player->GetRootComponent(),
            NAME_None,                 // Attach point name
            FVector::ZeroVector,
            FRotator::ZeroRotator,
            EAttachLocation::KeepRelativeOffset,
            true                       // Auto destroy when finished
        );


    }
}

TStatId UWorldWeatherSystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UWorldTimeSubsystem, STATGROUP_Tickables);
}