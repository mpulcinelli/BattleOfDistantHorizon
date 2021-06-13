#include "BattleOfDistantHoriz/Pickups/FuelPickUp.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Components/RectLightComponent.h"

AFuelPickUp::AFuelPickUp(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PICK_UP(TEXT("/Game/Geometry/Meshes/BatteryPickup/BatteryPickUp"));

    TopLigh = CreateDefaultSubobject<URectLightComponent>(TEXT("TopLigh"))

    TopLigh->SetupAttachment(RootComponent);
    TopLigh->SetRelativeLocation(FVector(0.000000,0.000000,880.000000));
    TopLigh->SetIntensity(100000.0);
    TopLigh->SetLightColor(FLinearColor::Red);
    TopLigh->


    if (SM_PICK_UP.Object != nullptr)
    {
        PickUpMesh->SetStaticMesh(SM_PICK_UP.Object);
    }
}
