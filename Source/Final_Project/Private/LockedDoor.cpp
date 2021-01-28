// Fill out your copyright notice in the Description page of Project Settings.

#include "LockedDoor.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"
#include "KeyCard.h"
#include "CustomPlayerState.h"

// Sets default values
ALockedDoor::ALockedDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneCompRoot"));
	RootComponent = SceneComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	StaticMeshComp->SetupAttachment(SceneComp);
}

// Called when the game starts or when spawned
void ALockedDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALockedDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALockedDoor::OnInteract_Implementation()
{
	UWorld* world = GetWorld();

	if (world) {
		APlayerController* controller = UGameplayStatics::GetPlayerController(world, 0);
		ACustomPlayerState* playerState = Cast<ACustomPlayerState>(controller->PlayerState);

		if (playerState->HasKeyCard(RequiredType)) {
			OpenDoor();
		} 
	}
}

void ALockedDoor::OpenDoor_Implementation()
{
}

