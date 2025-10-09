// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_Key.h"

ANECOLAI_Key::ANECOLAI_Key()
{
}

bool ANECOLAI_Key::IsPlayerCharacter(AActor* ActorToCheck)
{
	// TODO: Make this check if the object passed in is the player character, if so, then return true
	if (ActorToCheck->IsA(ANECOLAI_Character::StaticClass()))
		return true;
	else
		return false;
}

void ANECOLAI_Key::TryOpenDoor(AActor* OverlappedActor, AActor* OtherActor)
{
	if (IsPlayerCharacter(OtherActor))
	{
		OpenDoor();
	}
}

void ANECOLAI_Key::OpenDoor()
{
	// Destroy the door we are supposed to open
	doorToOpen->Destroy();

	// Destroy the key (so it looks like we picked it up)
	this->Destroy();
}