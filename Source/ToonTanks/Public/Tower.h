// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void HandleDestruction() override;

protected:
	virtual void BeginPlay() override;

private:
	class ATank* Tank;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange{500};

	FTimerHandle FireRateTimerHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRate{2.f};

	void CheckFireCondition();
	bool IsTargetInFireRange() const;
};
