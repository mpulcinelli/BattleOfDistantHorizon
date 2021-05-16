// Fill out your copyright notice in the Description page of Project Settings.

#include "TunnelGenerator.h"
#include "TunnelUnit.h"


// Sets default values
ATunnelGenerator::ATunnelGenerator()
{
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent *RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = RootComp;
	LocationToSpawn = FVector(0, 0, 0);
}

void ATunnelGenerator::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(CreateUnitTimerHandle, this, &ATunnelGenerator::CreateUnit, 1.5f, true, 0);
}

void ATunnelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATunnelGenerator::CreateUnit()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (LocationToSpawn.X == 0.0)
	{
		GetWorld()->SpawnActor<ATunnelUnit>(LocationToSpawn, RotationToSpawn, SpawnInfo);
		LocationToSpawn.X = 4800.0;
	}
	else
	{
		GetWorld()->SpawnActor<ATunnelUnit>(LocationToSpawn, RotationToSpawn, SpawnInfo);
		LocationToSpawn.X += 4800.0;
	}
}
