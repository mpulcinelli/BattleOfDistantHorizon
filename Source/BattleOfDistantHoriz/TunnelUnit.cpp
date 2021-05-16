#include "TunnelUnit.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "SpaceShipPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "StarPickUp.h"
#include "Components/PointLightComponent.h"


// Sets default values
ATunnelUnit::ATunnelUnit()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent *RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	TunnelUnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TunnelUnitMesh"));
	EndTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("EndTrigger"));
	AreaToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("AreaToSpawn"));
	PoitLight01 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PoitLight01"));
	PoitLight02 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PoitLight02"));
	PoitLight03 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PoitLight03"));
	PoitLight04 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PoitLight04"));
	PoitLight05 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PoitLight05"));	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_TUNNEL_UNIT_OPEN(TEXT("/Game/Geometry/Meshes/SM_Tunnel_Open_4800"));

	RootComponent = RootComp;

	TunnelUnitMesh->SetupAttachment(RootComp);
	EndTrigger->SetupAttachment(RootComp);
	AreaToSpawn->SetupAttachment(RootComp);

	TunnelUnitMesh->SetCollisionProfileName(FName("BlockAll"));

	PoitLight01->SetupAttachment(RootComp);
	PoitLight02->SetupAttachment(RootComp);
	PoitLight03->SetupAttachment(RootComp);
	PoitLight04->SetupAttachment(RootComp);
	PoitLight05->SetupAttachment(RootComp);

	PoitLight01->SetRelativeLocation(FVector(-1230.000000,2270.0,0.000000));
	PoitLight02->SetRelativeLocation(FVector(1230.000000,2270.0,0.000000));
	PoitLight03->SetRelativeLocation(FVector(1230.000000,-2270.0,0.000000));
	PoitLight04->SetRelativeLocation(FVector(-1230.000000,-2270.0,0.000000));
	PoitLight05->SetRelativeLocation(FVector(0.000000,10.000000,2170.000000));

	PoitLight01->SetIntensity(100000.0);
	PoitLight02->SetIntensity(100000.0);
	PoitLight03->SetIntensity(100000.0);
	PoitLight04->SetIntensity(100000.0);
	PoitLight05->SetIntensity(100000.0);	

	PoitLight01->SetAttenuationRadius(16000.0);
	PoitLight02->SetAttenuationRadius(16000.0);
	PoitLight03->SetAttenuationRadius(16000.0);
	PoitLight04->SetAttenuationRadius(16000.0);
	PoitLight05->SetAttenuationRadius(16000.0);

	PoitLight01->SetSourceRadius(2300.0);
	PoitLight02->SetSourceRadius(2300.0);
	PoitLight03->SetSourceRadius(2300.0);
	PoitLight04->SetSourceRadius(2300.0);
	PoitLight05->SetSourceRadius(2300.0);

	PoitLight01->SetSoftSourceRadius(1500.0);
	PoitLight02->SetSoftSourceRadius(1500.0);
	PoitLight03->SetSoftSourceRadius(1500.0);
	PoitLight04->SetSoftSourceRadius(1500.0);
	PoitLight05->SetSoftSourceRadius(1500.0);

	PoitLight01->SetSourceLength(2000.0);
	PoitLight02->SetSourceLength(2000.0);
	PoitLight03->SetSourceLength(2000.0);
	PoitLight04->SetSourceLength(2000.0);
	PoitLight05->SetSourceLength(2000.0);

	PoitLight01->SetMobility(EComponentMobility::Stationary);
	PoitLight02->SetMobility(EComponentMobility::Stationary);
	PoitLight03->SetMobility(EComponentMobility::Stationary);
	PoitLight04->SetMobility(EComponentMobility::Stationary);
	PoitLight05->SetMobility(EComponentMobility::Stationary);

	EndTrigger->SetRelativeLocation(FVector(2338.0f, 0.0f, 0.0f));
	EndTrigger->SetRelativeScale3D(FVector(10.0f, 70.0f, 70.0f));
	EndTrigger->SetGenerateOverlapEvents(true);
	EndTrigger->SetCollisionProfileName(FName("BoxEndTriggerProfile"));

	AreaToSpawn->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	AreaToSpawn->SetRelativeScale3D(FVector(70.0f, 70.0f, 70.0f));
	AreaToSpawn->SetGenerateOverlapEvents(true);
	AreaToSpawn->SetCollisionProfileName(FName("BoxSpawnProfile"));

	if (SM_TUNNEL_UNIT_OPEN.Object != nullptr)
	{
		TunnelUnitMesh->SetStaticMesh(SM_TUNNEL_UNIT_OPEN.Object);
	}
}

void ATunnelUnit::BeginPlay()
{
	Super::BeginPlay();

	EndTrigger->OnComponentBeginOverlap.AddDynamic(this, &ATunnelUnit::EndTriggerBeginOverlap);
	FVector RandPoint;

	GetRandomPointIn3DBoxSpace(RandPoint, AreaToSpawn);

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	FRotator RotationToSpawn;

	auto start = GetWorld()->SpawnActor<AStarPickUp>(RandPoint, RotationToSpawn, SpawnInfo);

	if (start != nullptr)
	{
		ListOfCreatedActors.Add(start);

		start->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *RandPoint.ToString());
}

void ATunnelUnit::BeginDestroy()
{
	Super::BeginDestroy();
}

void ATunnelUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATunnelUnit::EndTriggerBeginOverlap(class UPrimitiveComponent *OverlappedComp, class AActor *Other, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	auto isPlayer = Cast<ASpaceShipPawn>(Other);

	if (isPlayer != nullptr)
	{
		// Destroi o túnel.
		SetLifeSpan(0.5);
		for (auto &itm : ListOfCreatedActors)
		{
			// Destroi os objetos criados pelo Túnel.
			itm->SetLifeSpan(0.5);
		}
	}
}

void ATunnelUnit::GetRandomPointIn3DBoxSpace(FVector &RandomPoint, UBoxComponent *BoundingBox)
{
	RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(BoundingBox->Bounds.Origin, BoundingBox->Bounds.BoxExtent);
}