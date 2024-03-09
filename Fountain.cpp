// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"
#include "Components/SceneComponent.h"

// Sets default values
AFountain::AFountain()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
    Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
    Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
    Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Splash"));

    RootComponent = Body;
    Water->SetupAttachment(Body);
    Light->SetupAttachment(Body);
    Splash->SetupAttachment(Body);

    Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
    Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
    Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}