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
	currentHealth = maxHealth; // Initialize currentHealth
}

float ANECOLAI_Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// If the player is not already dead
	if (!isDead)
	{
		// Subtract incoming damage
		currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("Player took %f damage. %f health remaining."), DamageAmount, currentHealth);

		// Check if player has died
		if (currentHealth <= 0)
		{
			Die();
		}

		return DamageAmount;
	}
	// If the player is already dead
	else
	{
		return 0;
	}
}

void ANECOLAI_Character::Die()
{
	isDead = true;
	currentHealth = 0;
	// Prevent player from moving
	moveSpeed = 0;
	turnSpeed = 0;

	GetMesh()->PlayAnimation(deathAnim, false);

	// ToDo: Trigger game over state and prompt player to restart level
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
	PlayerInputComponent->BindAction(TEXT("Stun"), IE_Pressed, this, &ANECOLAI_Character::DoStun);
}

void ANECOLAI_Character::MoveForward(float moveVal)
{
	AddMovementInput(GetActorForwardVector(), moveVal * moveSpeed);
}

void ANECOLAI_Character::MoveRight(float moveVal)
{
	AddMovementInput(GetActorRightVector(), moveVal * moveSpeed);
}

void ANECOLAI_Character::Rotate(float turnVal)
{
	AddControllerYawInput(turnVal * turnSpeed);
}

void ANECOLAI_Character::DoJump()
{
	// Find character jump function
	Jump();
}

void ANECOLAI_Character::DoStun()
{
	// Get all the NECOLAI_Characters within a certain radius of this character
	// Call the stun event on those characters - that event will set an "isStunned" on their blackboard and set a timer
	//		isStunned is their first decision option, so they always do it first
	//		When the timer ends, it will set isStunned back to false

}

void ANECOLAI_Character::ActivateStunParticleSystem()
{
	// Spawn a particle system and play it once
	if (stunSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(stunSystem, AttachComp, NAME_None, FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player attempted to use stun ability, but no template particle was found."));
	}
}