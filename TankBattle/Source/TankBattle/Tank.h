// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetTurretChildActor(UStaticMeshComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetBarrelChildActor(UStaticMeshComponent* BarrelFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
		void SetPlayerActor(UStaticMeshComponent* BodyFromBP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void RotateTurret(float Speed);
	void TiltTurret(float Speed);

	void MoveTank(float Speed);
	void RotateTank(float Speed);

	UStaticMeshComponent* Turret = nullptr;
	UStaticMeshComponent* Barrel = nullptr;
	UStaticMeshComponent* Body = nullptr;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 1200.f;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 120.f;
	
};
