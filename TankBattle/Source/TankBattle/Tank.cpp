// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATank::SetTurretChildActor(UStaticMeshComponent* TurretFromBP)
{
	if (!TurretFromBP) { return; }
	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UStaticMeshComponent* BarrelFromBP)
{
	if (!BarrelFromBP) { return; }
	Barrel = BarrelFromBP;
}

void ATank::SetPlayerActor(UStaticMeshComponent* BodyFromBP)
{
	if (!BodyFromBP) { return; }
	Body = BodyFromBP;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
	InputComponent->BindAxis("Tilt_Turret", this, &ATank::TiltTurret);

	InputComponent->BindAxis("Move_Player", this, &ATank::MoveTank);
	InputComponent->BindAxis("Rotate_Player", this, &ATank::RotateTank);
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
	Turret->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));
}

void ATank::TiltTurret(float Speed)
{
	if (!Barrel) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
	Barrel->AddRelativeRotation(FRotator(Rotation, 0.f, 0.f));
}

void ATank::MoveTank(float Speed)
{
	if (!Body) { return; }
	float Distance = GetWorld()->DeltaTimeSeconds * Speed * MovementSpeed;
	Body->AddRelativeLocation(Body->GetForwardVector() * Distance);
}

void ATank::RotateTank(float Speed)
{
	if (!Body) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
	Body->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));
}

