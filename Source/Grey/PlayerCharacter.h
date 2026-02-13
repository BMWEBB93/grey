
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"

#include "InputAction.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"

#include "PlayerCharacter.generated.h"




UCLASS()
class GREY_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	

public:
	APlayerCharacter();

protected:
    virtual void BeginPlay() override;

    // Mapping context
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputMappingContext* DefaultMappingContext;  

    // Input actions
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* LookAction;


    // Animation variables
    UPROPERTY(BlueprintReadOnly, Category = "Animation")
    float lookPitch;

    UPROPERTY(BlueprintReadOnly, Category = "Animation")
    float movementDirection;



	// Camera boom (spring arm)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    class USpringArmComponent* CameraBoom;

    // Follow camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    class UCameraComponent* FollowCamera;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Input Actions
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
};
