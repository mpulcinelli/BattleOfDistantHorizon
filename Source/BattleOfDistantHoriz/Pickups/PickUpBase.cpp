
#include "PickUpBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"



// Sets default values
APickUpBase::APickUpBase(const FObjectInitializer& ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent *RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpMesh"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_PICK_UP(TEXT("/Game/Geometry/Meshes/PickUpMesh"));


	RootComponent = RootComp;
	PickUpMesh->SetupAttachment(RootComp);

	if(SM_PICK_UP.Object!=nullptr){
		PickUpMesh->SetStaticMesh(SM_PICK_UP.Object);
	}

}

// Called when the game starts or when spawned
void APickUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

