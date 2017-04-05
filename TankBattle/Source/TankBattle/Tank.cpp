// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	InputComponent->BindAction("Turret_Right", IE_Pressed, this, &ATank::RotateTurret);

	InputComponent->BindAction("Turret_Left", IE_Pressed, this, &ATank::RotateTurret);

	InputComponent->BindAction("Forward", IE_Pressed, this, &ATank::MoveForward);

	InputComponent->BindAction("Reverse", IE_Pressed, this, &ATank::MoveReverse);
}

void ATank::RotateTurret()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateTurret called"));
	//SetActorRelativeRotation
	//UChildActorComponent
}

void ATank::MoveForward()
{
	UE_LOG(LogTemp, Warning, TEXT("Move Forward called"));
}

void ATank::MoveReverse()
{
	UE_LOG(LogTemp, Warning, TEXT("Reverse called"));
}