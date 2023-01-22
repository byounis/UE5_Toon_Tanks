// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;

	bool Alive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed{100.f};
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed{100.f};

	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;
	
};


