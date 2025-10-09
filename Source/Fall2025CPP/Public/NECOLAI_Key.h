// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "NECOLAI_Door.h"
#include "NECOLAI_Character.h"
#include "NECOLAI_Key.generated.h"

/**
 * 
 */
UCLASS()
class FALL2025CPP_API ANECOLAI_Key : public ATriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	ANECOLAI_Door* doorToOpen;

public:
	ANECOLAI_Key();

	UFUNCTION()
	bool IsPlayerCharacter(class AActor* ActorToCheck);
	void TryOpenDoor(class AActor* OverlappedActor, class AActor* OtherActor);
	void OpenDoor();
};
