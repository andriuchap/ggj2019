// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicMissile.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMagicMissile::AMagicMissile(const FObjectInitializer &ObjInitializer)
{
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;
	SphereCollision->SetCollisionProfileName("OverlapAllDynamic");
	SphereCollision->SetGenerateOverlapEvents(true);

	MissileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MissileMesh"));
	MissileMesh->SetupAttachment(RootComponent);
	MissileMesh->SetCollisionProfileName(FName("NoCollision"));

	MissileParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MissileParticles"));
	MissileParticles->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;
	MovementComponent->bIsHomingProjectile = true;
	MovementComponent->HomingAccelerationMagnitude = 1000.0F;
}

// Called when the game starts or when spawned
void AMagicMissile::BeginPlay()
{
	Super::BeginPlay();
}