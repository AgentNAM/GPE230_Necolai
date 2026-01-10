// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_HealthPickup.h"

void ANECOLAI_HealthPickup::Apply(ANECOLAI_Character* player)
{
	UE_LOG(LogTemp, Log, TEXT("Player collected health pickup."));

	(*player).Heal(healthToAdd);
}