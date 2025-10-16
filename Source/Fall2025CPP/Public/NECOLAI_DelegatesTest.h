// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "NECOLAI_DelegatesTest.generated.h"

/**
 * 
 */
UCLASS()
class FALL2025CPP_API ANECOLAI_DelegatesTest : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ANECOLAI_DelegatesTest();

	UFUNCTION()
	void OnPickup(class AActor* OverlappedActor, class AActor* OtherActor);
};
