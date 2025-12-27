// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NECOLAI_Pickup.h"
#include "NECOLAI_LandminePickup.generated.h"

/**
 * 
 */
UCLASS()
class FALL2025CPP_API ANECOLAI_LandminePickup : public ANECOLAI_Pickup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float damageAmount;

protected:
	void Apply(ANECOLAI_Character* player);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageType> DamageType;
};
