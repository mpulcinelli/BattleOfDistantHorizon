// Fill out your copyright notice in the Description page of Project Settings.

#include "HomeGameMode.h"
#include "BattleOfDistantHoriz/Helpers/UserWidgetHelper.h"

void AHomeGameMode::InitGame(const FString &MapName, const FString &Options, FString &ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);

    auto EntradaWidget = NewObject<UUserWidgetHelper>(this);

    if (EntradaWidget)
        EntradaWidget->SetEntradaWidget(true);
}

void AHomeGameMode::StartToLeaveMap()
{
    Super::StartToLeaveMap();
    
    auto EntradaWidget = NewObject<UUserWidgetHelper>(this);

    if (EntradaWidget)
        EntradaWidget->SetEntradaWidget(false);
}
