// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldWeatherSystem.h"

void UWorldWeatherSystem::Tick(float DeltaTime)
{
    Seconds += DeltaTime * TimeRate;

    if (Seconds > 60.f)
    {
        Seconds -= 60.f;
        Minutes++;

        if (Minutes > 60)
        {
            Minutes -= 60;
            Hours++;
        }
    }

    if (SunLight)
    {
        float SunAngle = (Hours + Minutes / 60.f) * 15.f;
        // 360° / 24 hours = 15° per hour

        FRotator NewRotation = FRotator(SunAngle - 270.f, 0.f, 0.f);
        SunLight->SetActorRotation(NewRotation);
    }

    if (GEngine)
    {
        FString TimeString = FString::Printf(
            TEXT("Time: %02d:%02d:%05.2f"),
            Hours,
            Minutes,
            Seconds
        );

        GEngine->AddOnScreenDebugMessage(
            1,              // Key (same key updates same line)
            0.f,            // 0 = persistent until updated
            FColor::Green,  // Color
            TimeString
        );
    }
    
}

TStatId UWorldWeatherSystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UWorldTimeSubsystem, STATGROUP_Tickables);
}