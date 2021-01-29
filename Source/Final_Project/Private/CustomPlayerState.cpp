// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomPlayerState.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "KeyCard.h"

ACustomPlayerState::ACustomPlayerState() 
{
	PlayerName = "Test";
}

void ACustomPlayerState::AddKeyCard(EKeyCardType keyCard)
{
	if (!HasKeyCard(keyCard)) {
		CollectedKeyCards.Add(keyCard);
	}
}

bool ACustomPlayerState::HasKeyCard(EKeyCardType keyCard)
{
	return CollectedKeyCards.Contains(keyCard);
}

void ACustomPlayerState::Save(float gameTime)
{
	UMySaveGame* save = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	save->Time = gameTime;


	UGameplayStatics::SaveGameToSlot(save, "CA Save Slot", 0);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, "GAME SAVED");
}
