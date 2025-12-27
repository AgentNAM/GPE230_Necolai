// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_Pickup.h"

// Sets default values
ANECOLAI_Pickup::ANECOLAI_Pickup()
{
	// Detect player overlap with trigger volume
	OnActorBeginOverlap.AddDynamic(this, &ANECOLAI_Pickup::OnPickup);
}

void ANECOLAI_Pickup::OnPickup(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if the overlapping actor is our player
	if (OtherActor->IsA(ANECOLAI_Character::StaticClass()))
	{
		// Create a variable pointing to the player
		ANECOLAI_Character* player = Cast<ANECOLAI_Character>(OtherActor);
		Apply(player); // Apply this pickup's effect to the player
		DestroySelf(); // Destroy this pickup
	}
}

void ANECOLAI_Pickup::Apply(ANECOLAI_Character* player)
{
	UE_LOG(LogTemp, Log, TEXT("Player collected default pickup."));
}

void ANECOLAI_Pickup::DestroySelf()
{
	// Destroy this pickup
	this->Destroy();
}