// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyCard.h"
#include "Interactable.h"
#include "LockedDoor.generated.h"

UCLASS()
class FINAL_PROJECT_API ALockedDoor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALockedDoor();

	UPROPERTY(EditAnywhere)
		USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EKeyCardType RequiredType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnInteract_Implementation() override;

	UFUNCTION(BlueprintNativeEvent)
		void OpenDoor();

};
