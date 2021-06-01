#include "BattleOfDistantHoriz/Pickups/FuelPickUp.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AFuelPickUp::AFuelPickUp(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PICK_UP(TEXT("/Game/Geometry/Meshes/FuelPickupMesh"));

    if (SM_PICK_UP.Object != nullptr)
    {
        PickUpMesh->SetStaticMesh(SM_PICK_UP.Object);
    }
}
