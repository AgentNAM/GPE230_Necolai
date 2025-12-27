// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NECOLAI_Pickup.h"
#include "NECOLAI_HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class FALL2025CPP_API ANECOLAI_HealthPickup : public ANECOLAI_Pickup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float healthToAdd;

protected:
	void Apply(ANECOLAI_Character* player);
};
