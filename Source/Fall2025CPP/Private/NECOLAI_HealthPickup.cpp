// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_HealthPickup.h"

void ANECOLAI_HealthPickup::Apply(ANECOLAI_Character* player)
{
	UE_LOG(LogTemp, Log, TEXT("Player collected health pickup."));
	// UE_LOG(LogTemp, Display, TEXT("Restored health"));
	// player.Heal(healthToAdd);

	// ANECOLAI_Character playerVal = *player;
	(*player).Heal(healthToAdd);
}