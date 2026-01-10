// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NECOLAI_Pickup.h"
#include "NECOLAI_Gate.h"
#include "NECOLAI_KeyPickup.generated.h"

/**
 * 
 */
UCLASS()
class FALL2025CPP_API ANECOLAI_KeyPickup : public ANECOLAI_Pickup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	ANECOLAI_Gate* gateToOpen;

protected:
	void Apply(ANECOLAI_Character* player);
	
};
