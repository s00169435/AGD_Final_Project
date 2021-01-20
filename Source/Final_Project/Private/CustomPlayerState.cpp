// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerState.h"
#include "KeyCard.h"

ACustomPlayerState::ACustomPlayerState() {

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
