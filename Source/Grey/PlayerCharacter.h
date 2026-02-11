
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"
#include "InputActionValue.h"


UCLASS()
class GREY_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	

public:
	APlayerCharacter();

protected:
    virtual void BeginPlay() override;

    // Input handlers
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);


	// Camera boom (spring arm)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    class USpringArmComponent* CameraBoom;

    // Follow camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    class UCameraComponent* FollowCamera;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
