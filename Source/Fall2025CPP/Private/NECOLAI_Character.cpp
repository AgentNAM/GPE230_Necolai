// Fill out your copyright notice in the Description page of Project Settings.


#include "NECOLAI_Character.h"

// Sets default values
ANECOLAI_Character::ANECOLAI_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANECOLAI_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANECOLAI_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANECOLAI_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ANECOLAI_Character::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &ANECOLAI_Character::Rotate);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ANECOLAI_Character::DoJump);
}

void ANECOLAI_Character::MoveForward(float moveVal)
{
	AddMovementInput(GetActorForwardVector(), moveVal);
}

void ANECOLAI_Character::MoveRight(float moveVal)
{
	AddMovementInput(GetActorRightVector(), moveVal);
}

void ANECOLAI_Character::Rotate(float turnVal)
{
	AddControllerYawInput(turnVal);
}

void ANECOLAI_Character::DoJump()
{
	// Find character jump function
	Jump();
}

