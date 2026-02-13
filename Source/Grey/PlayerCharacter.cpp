// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


APlayerCharacter::APlayerCharacter()
{
	// Tick every frame
	PrimaryActorTick.bCanEverTick = true;

    // Camera boom
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(GetMesh(),TEXT("HeadSocket"));
    CameraBoom->TargetArmLength = -40.f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->SetRelativeLocation(FVector::ZeroVector);

   

    // Camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);
    FollowCamera->bUsePawnControlRotation = false;

}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    // setup input mapping context
    if (APlayerController* playerController = Cast<APlayerController>(Controller))
    {	    
        if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
        {
            subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
	
   
}

void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // get movement direction for animation
    FVector Velocity = GetVelocity();
    FVector Forward = GetActorForwardVector();

    float ForwardDot = FVector::DotProduct(Forward, Velocity);
    float RightDot = FVector::DotProduct(GetActorRightVector(), Velocity);

    movementDirection = FMath::Atan2(RightDot, ForwardDot) * (180.f / PI);

}



void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    // Set up action bindings
    if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        enhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
        enhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
    }
}


void APlayerCharacter::Move(const FInputActionValue& Value)
{
    const FVector2D MoveAxis = Value.Get<FVector2D>();


    const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);

    AddMovementInput(FRotationMatrix(YawRot).GetUnitAxis(EAxis::X), MoveAxis.Y);
    AddMovementInput(FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y), MoveAxis.X);
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxis = Value.Get<FVector2D>();

    AddControllerYawInput(LookAxis.X);
    AddControllerPitchInput(-LookAxis.Y);
}

