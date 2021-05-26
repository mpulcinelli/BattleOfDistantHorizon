// Fill out your copyright notice in the Description page of Project Settings.

#include "UserWidgetHelper.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "BattleOfDistantHoriz/Widgets/HomeWidget.h"
#include "BattleOfDistantHoriz/Widgets/HUDWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void UUserWidgetHelper::ShowEntrada()
{
    FSoftClassPath WBP_ENTRADA(TEXT("WidgetBlueprint'/Game/UI/WBP_ENTRADA.WBP_ENTRADA_C'"));

    if (UClass *WbpEntradaClass = WBP_ENTRADA.TryLoadClass<UHomeWidget>())
    {

        UWorld *W = GetWorld();

        if (!ensure(W != nullptr))
            return;

        APlayerController *PC = W->GetFirstPlayerController();

        if (!ensure(PC != nullptr))
            return;

        UUserWidget *EntradaWidget = CreateWidget<UUserWidget>(PC, WbpEntradaClass);

        if (!ensure(EntradaWidget != nullptr))
            return;

        EntradaWidget->AddToViewport();
        FInputModeUIOnly InputUI;
        InputUI.SetWidgetToFocus(EntradaWidget->TakeWidget());
        InputUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        PC->SetInputMode(InputUI);
        PC->bShowMouseCursor = true;
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

void UUserWidgetHelper::SetEntradaWidget(EDisplayWidget DisplayOption)
{
    if (DisplayOption == EDisplayWidget::HideWidget)

    {
        HideEntrada();
        UE_LOG(LogTemp, Warning, TEXT("Entrei no hide"));
    }
    else
    {
        ShowEntrada();
        UE_LOG(LogTemp, Warning, TEXT("Entrei no Show"));
    }
}

void UUserWidgetHelper::SetPlayerHudWidget(EDisplayWidget DisplayOption)
{
    if (DisplayOption == EDisplayWidget::HideWidget)
        HidePlayerHud();
    else
        ShowPlayerHud();
}
