// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_DelegatesTest.h"

ANECOLAI_DelegatesTest::ANECOLAI_DelegatesTest()
{
	OnActorBeginOverlap.AddDynamic(this, &ANECOLAI_DelegatesTest::OnPickup);
}

void ANECOLAI_DelegatesTest::OnPickup(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapping with other actor"));
	this->Destroy();
}
