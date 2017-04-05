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
	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UStaticMeshComponent* BarrelFromBP)
{
	Barrel = BarrelFromBP;
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

	InputComponent->BindAction("Forward", IE_Pressed, this, &ATank::MoveForward);

	InputComponent->BindAction("Reverse", IE_Pressed, this, &ATank::MoveReverse);
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	Turret->AddRelativeRotation(FRotator(0.f, Speed, 0.f));
}

void ATank::TiltTurret(float Speed)
{
	if (!Barrel) { return; }
	Barrel->AddRelativeRotation(FRotator(Speed, 0.f, 0.f));
}

void ATank::MoveForward()
{
	UE_LOG(LogTemp, Warning, TEXT("Move Forward called"));
}

void ATank::MoveReverse()
{
	UE_LOG(LogTemp, Warning, TEXT("Reverse called"));
}

