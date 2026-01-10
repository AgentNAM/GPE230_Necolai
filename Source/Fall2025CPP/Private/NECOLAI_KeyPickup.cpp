// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_KeyPickup.h"

void ANECOLAI_KeyPickup::Apply(ANECOLAI_Character* player)
{
	UE_LOG(LogTemp, Log, TEXT("Player collected key pickup."));

	// Destroy the gate we want to open
	gateToOpen->Destroy();
}