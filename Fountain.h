// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class Unreal_0309 AFountain : public AActor //Actor를 상속 받은 분수 액터
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFountain();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override; // 게임이 시작할때 처음 불리는 함수 

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override; // 한프레임이 그려지는 동안 불리우는 함수 (초당 45~120번)

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Body; //스테틱 메시 컴포넌트 Body

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Water; //Static Mesh 컴포넌트 워터(물)

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    class UPointLightComponent* Light; // 라이팅 

    UPROPERTY(VisibleAnywhere)
    class UParticleSystemComponent* Splash; // 물튀기는 효과 

    UPROPERTY(EditAnywhere, Category = ID)
    int32 ID;
};
