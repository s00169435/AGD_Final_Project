// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeyCard.h"
#include "GameFramework/PlayerState.h"
#include "CustomPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_PROJECT_API ACustomPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ACustomPlayerState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<EKeyCardType> CollectedKeyCards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerName;

	void AddKeyCard(EKeyCardType keyCard);
	bool HasKeyCard(EKeyCardType keyCard);
};
