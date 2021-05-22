// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserWidgetHelper.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEOFDISTANTHORIZ_API UUserWidgetHelper : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION()
	void SetEntradaWidget(bool hide);

	UFUNCTION()
	void SetPlayerHudWidget(bool hide);

private:

	/**
	 * Entrada Widget
	*/
	UFUNCTION()
	void ShowEntrada();

	UFUNCTION()
	void HideEntrada();
	
	UFUNCTION()
	void ShowPlayerHud();

	UFUNCTION()
	void HidePlayerHud();

};
