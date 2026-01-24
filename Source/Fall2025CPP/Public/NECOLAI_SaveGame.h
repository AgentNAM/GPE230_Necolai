// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "NECOLAI_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FALL2025CPP_API UNECOLAI_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UNECOLAI_SaveGame();

	UPROPERTY(BlueprintReadWrite)
	int furthestCompletedLevel;

	UPROPERTY(BlueprintReadWrite)
	float masterVolumeSetting;

	UPROPERTY(BlueprintReadWrite)
	float musicVolumeSetting;

	UPROPERTY(BlueprintReadWrite)
	float sfxVolumeSetting;
};
