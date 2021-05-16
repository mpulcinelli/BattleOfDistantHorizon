// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleOfDistantHorizGameMode.h"
#include "BattleOfDistantHorizPawn.h"
#include "SpaceShipPawn.h"

ABattleOfDistantHorizGameMode::ABattleOfDistantHorizGameMode()
{
	// set default pawn class to our flying pawn
	// DefaultPawnClass = ABattleOfDistantHorizPawn::StaticClass();
	DefaultPawnClass = ASpaceShipPawn::StaticClass();
}
