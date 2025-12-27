// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "NECOLAI_Character.h"
#include "NECOLAI_Pickup.generated.h"

UCLASS()
class FALL2025CPP_API ANECOLAI_Pickup : public ATriggerBox
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANECOLAI_Pickup();

	UFUNCTION()
	void OnPickup(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	UFUNCTION()
	virtual void Apply(ANECOLAI_Character* player);
	void DestroySelf();
};
