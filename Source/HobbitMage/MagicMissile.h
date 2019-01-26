// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MagicMissile.generated.h"

UCLASS()
class HOBBITMAGE_API AMagicMissile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicMissile(const FObjectInitializer &ObjInitializer);

public:

	UPROPERTY(VisibleAnywhere, Category = "Magic Missile")
	class UStaticMeshComponent* MissileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Magic Missile")
	class UParticleSystemComponent* MissileParticles;

	UPROPERTY(VisibleAnywhere, Category = "Magic Missile")
	class USphereComponent* SphereCollision;

	UPROPERTY(VisibleAnywhere, Category = "Magic Missile")
	class UProjectileMovementComponent* MovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

};
