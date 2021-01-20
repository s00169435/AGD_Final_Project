// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyCard.generated.h"

class USphereComponent;

UENUM(BlueprintType)
enum class EKeyCardType : uint8 {
	Red,
	Green,
	Blue
};
UCLASS()
class FINAL_PROJECT_API AKeyCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyCard();

	UPROPERTY(EditAnywhere)
		USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere)
		USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EKeyCardType CardType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLinearColor Color;

protected:
	// Called when the game starts or when spawned
	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
