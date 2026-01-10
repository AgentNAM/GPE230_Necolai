// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_Door.h"

void ANECOLAI_Door::OpenSelf()
{
	SetActorEnableCollision(false);
	this->Destroy();
}