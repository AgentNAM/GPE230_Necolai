// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NECOLAI_Gate.generated.h"

UCLASS()
class FALL2025CPP_API ANECOLAI_Gate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANECOLAI_Gate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
