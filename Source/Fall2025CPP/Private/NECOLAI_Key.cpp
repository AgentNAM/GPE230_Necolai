// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_Key.h"

ANECOLAI_Key::ANECOLAI_Key()
{
	OnActorBeginOverlap.AddDynamic(this, &ANECOLAI_Key::OnPickup);
}

void ANECOLAI_Key::OnPickup(AActor* OverlappedActor, AActor* OtherActor)
{
	// Destroy the door we want to open
	doorToOpen->Destroy();
	// Destroy this key
	this->Destroy();
}