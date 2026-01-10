// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_VictoryPickup.h"

void ANECOLAI_VictoryPickup::Apply(ANECOLAI_Character* player)
{
	(*player).OpenVictoryScreen();
}