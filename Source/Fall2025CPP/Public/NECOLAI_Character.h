// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "NECOLAI_Character.generated.h"

UCLASS()
class FALL2025CPP_API ANECOLAI_Character : public ACharacter
{
	GENERATED_BODY()

private:
	// Private variables
	UPROPERTY(EditAnywhere)
	float moveSpeed;
	UPROPERTY(EditAnywhere)
	float turnSpeed;

	// The animation to play when the player dies
	UPROPERTY(EditAnywhere)
	UAnimSequence* deathAnim;

	// Is this player dead and ready to restart the level?
	bool isDead = false;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* stunSystem;

	UFUNCTION(BlueprintCallable)
	void ActivateStunParticleSystem();

public:
	// Sets default values for this character's properties
	ANECOLAI_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual void Die();
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	/// <summary>
	/// The maximum and starting health for this character
	/// </summary>
	float maxHealth;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float moveVal);
	void MoveRight(float moveVal);
	void Rotate(float turnVal);
	void DoJump();
	void DoStun();

protected:
	/// <summary>
	/// The current health of this character
	/// </summary>
	float currentHealth;
public:
	UFUNCTION()
	float Heal(float healthToAdd);
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth();
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> _gameOverScreenTemplate;
	UUserWidget* _gameOverScreenInstance;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> _victoryScreenTemplate;
	UUserWidget* _victoryScreenInstance;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> _pauseMenuScreenTemplate;
	UUserWidget* _pauseMenuScreenInstance;
protected:
	/// <summary>
	/// The controller that manages this character
	/// </summary>
	APlayerController* _controller;
protected:
	virtual void OpenGameOverScreen();
	virtual void PauseGameplay(bool bIsPaused);
	virtual void ShowMouseCursor();
public:
	virtual void OpenVictoryScreen();

	FTimerHandle GameOverTimerHandle;

	virtual void ShowPauseMenu();
};
