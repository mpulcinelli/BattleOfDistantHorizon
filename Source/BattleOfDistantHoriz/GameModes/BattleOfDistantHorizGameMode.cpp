// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleOfDistantHorizGameMode.h"
#include "BattleOfDistantHoriz/Characters/BattleOfDistantHorizPawn.h"
#include "BattleOfDistantHoriz/Characters/SpaceShipPawn.h"

ABattleOfDistantHorizGameMode::ABattleOfDistantHorizGameMode()
{
	// set default pawn class to our flying pawn
	// DefaultPawnClass = ABattleOfDistantHorizPawn::StaticClass();
	DefaultPawnClass = ASpaceShipPawn::StaticClass();
}
