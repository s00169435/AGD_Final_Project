// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController() {
	SetGenericTeamId(FGenericTeamId(1));
}

void AEnemyAIController::PrintTeamID() {
	FGenericTeamId teamID = GetGenericTeamId();

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, FString::FromInt(teamID.GetId()));
}

