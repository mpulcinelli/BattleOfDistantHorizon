// Fill out your copyright notice in the Description page of Project Settings.

#include "HomeGameMode.h"
#include "BattleOfDistantHoriz/Helpers/UserWidgetHelper.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void AHomeGameMode::InitGame(const FString &MapName, const FString &Options, FString &ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);
}

void AHomeGameMode::StartToLeaveMap()
{
    Super::StartToLeaveMap();

    auto EntradaWidget = NewObject<UUserWidgetHelper>(this);

    if (EntradaWidget)
        EntradaWidget->SetEntradaWidget(EDisplayWidget::HideWidget);
}

void AHomeGameMode::StartPlay()
{
    Super::StartPlay();

    auto EntradaWidget = NewObject<UUserWidgetHelper>(this);

    if (EntradaWidget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Entrei no Entrada Widget"));
        EntradaWidget->SetEntradaWidget(EDisplayWidget::ShowWidget);
    }
    UE_LOG(LogTemp, Warning, TEXT("Chegue no final de startplay"));
}
