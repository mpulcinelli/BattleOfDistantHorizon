// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleOfDistantHoriz/Pickups/PickUpBase.h"
#include "FuelPickUp.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEOFDISTANTHORIZ_API AFuelPickUp : public APickUpBase
{
	GENERATED_BODY()

public:

	AFuelPickUp(const FObjectInitializer& ObjectInitializer);
	

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class URectLightComponent *TopLigh;
	
};
