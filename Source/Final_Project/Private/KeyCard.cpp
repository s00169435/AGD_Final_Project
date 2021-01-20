// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyCard.h"
#include "Components/SphereComponent.h"

// Sets default values
AKeyCard::AKeyCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneCompRoot"));
	RootComponent = SceneComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyCardMesh"));
	StaticMeshComp->SetupAttachment(SceneComp);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("KeyCardSphere"));
	SphereComp->InitSphereRadius(100.0f);
	SphereComp->SetGenerateOverlapEvents(true);
	SphereComp->ShapeColor = FColor::Red;
	SphereComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AKeyCard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKeyCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

