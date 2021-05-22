// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidgetHelper.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "BattleOfDistantHoriz/Widgets/HomeWidget.h"
#include "BattleOfDistantHoriz/Widgets/HUDWidget.h"

void UUserWidgetHelper::ShowEntrada()
{
    FStringClassReference WBP_ENTRADA(TEXT("WidgetBlueprint'/Game/UI/WBP_ENTRADA.WBP_ENTRADA'"));

    if (UClass *WbpEntradaClass = WBP_ENTRADA.TryLoadClass<UUserWidget>())
    {
        auto PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

        if (PC)
        {
            UUserWidget *EntradaWidget = CreateWidget<UUserWidget>(PC, WbpEntradaClass);
            if (EntradaWidget)
            {
                EntradaWidget->AddToViewport();
            }
        }
    }
}

void UUserWidgetHelper::HideEntrada()
{
    TArray<UUserWidget *> FoundWidgets;

    UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UHomeWidget::StaticClass());

    for (auto &&item : FoundWidgets)
    {
        item->RemoveFromViewport();
    }
}

void UUserWidgetHelper::ShowPlayerHud()
{
    FStringClassReference WBP_HUD(TEXT("WidgetBlueprint'/Game/UI/WBP_HUD.WBP_HUD'"));

    if (UClass *WbpHudClass = WBP_HUD.TryLoadClass<UUserWidget>())
    {
        auto PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

        if (PC)
        {
            UUserWidget *HudWidget = CreateWidget<UUserWidget>(PC, WbpHudClass);
            if (HudWidget)
            {
                HudWidget->AddToViewport();
            }
        }
    }
}

void UUserWidgetHelper::HidePlayerHud()
{
    TArray<UUserWidget *> FoundWidgets;

    UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UHUDWidget::StaticClass());

    for (auto &&item : FoundWidgets)
    {
        item->RemoveFromViewport();
    }
}

void UUserWidgetHelper::SetEntradaWidget(bool hide)
{
    if (hide)
        HideEntrada();
    else
        ShowEntrada();
}

void UUserWidgetHelper::SetPlayerHudWidget(bool hide)
{
    if (hide)
        ShowPlayerHud();
    else
        HidePlayerHud();

}
