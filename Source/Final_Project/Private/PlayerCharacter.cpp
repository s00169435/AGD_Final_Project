// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "KeyCard.h"
#include "LockedDoor.h"
#include "CustomPlayerState.h"
#include "Interactable.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ACustomPlayerState* playerState = Cast<ACustomPlayerState>(GetPlayerState());

	if (OtherActor->IsA(AKeyCard::StaticClass()) && playerState) {
		AKeyCard* hitKeyCard = Cast<AKeyCard>(OtherActor);
		playerState->AddKeyCard(hitKeyCard->CardType);
		hitKeyCard->Destroy();
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
}

void APlayerCharacter::Interact()
{
	FVector location;
	FRotator rotation;

	Controller->GetPlayerViewPoint(location, rotation);
	FHitResult hitResult;
	FCollisionQueryParams query;

	UWorld* world = GetWorld();

	if (world)
	{
		if (world->LineTraceSingleByChannel(hitResult, location, (rotation.Vector() * MaxDistance) + location, ECollisionChannel::ECC_Visibility, query)) {
			if (hitResult.Actor->GetClass()->ImplementsInterface(UInteractable::StaticClass())) {
				IInteractable* door = Cast<IInteractable>(hitResult.Actor);
				door->OnInteract_Implementation();
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Hit Interactable"));
			}
		}
	}
}

