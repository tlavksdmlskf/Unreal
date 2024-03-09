// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class Unreal_0309 AFountain : public AActor //Actor�� ��� ���� �м� ����
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFountain();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override; // ������ �����Ҷ� ó�� �Ҹ��� �Լ� 

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override; // ���������� �׷����� ���� �Ҹ���� �Լ� (�ʴ� 45~120��)

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Body; //����ƽ �޽� ������Ʈ Body

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Water; //Static Mesh ������Ʈ ����(��)

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    class UPointLightComponent* Light; // ������ 

    UPROPERTY(VisibleAnywhere)
    class UParticleSystemComponent* Splash; // ��Ƣ��� ȿ�� 

    UPROPERTY(EditAnywhere, Category = ID)
    int32 ID;
};
