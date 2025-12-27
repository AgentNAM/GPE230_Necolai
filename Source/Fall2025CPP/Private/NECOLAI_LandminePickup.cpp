// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_LandminePickup.h"
#include "Kismet/GameplayStatics.h"

void ANECOLAI_LandminePickup::Apply(ANECOLAI_Character* player)
{
	UE_LOG(LogTemp, Log, TEXT("Player collected landmine pickup."));
	UGameplayStatics::ApplyDamage(player, damageAmount, nullptr, this, DamageType);
	//(*player).TakeDamage(damageAmount);
}