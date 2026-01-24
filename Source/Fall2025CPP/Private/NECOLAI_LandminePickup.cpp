// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_LandminePickup.h"
#include "Kismet/GameplayStatics.h"

void ANECOLAI_LandminePickup::Apply(ANECOLAI_Character* player)
{
	if (player->CanBeDamaged()) {
		UE_LOG(LogTemp, Log, TEXT("Player collected landmine pickup."));
		UGameplayStatics::ApplyDamage(player, damageAmount, nullptr, this, DamageType);
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Enemy collected landmine pickup."));
		(*player).HandleLandmine();
	}
}