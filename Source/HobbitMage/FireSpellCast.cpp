// Fill out your copyright notice in the Description page of Project Settings.

#include "FireSpellCast.h"
#include "MagePawn.h"
#include "Engine/World.h"
#include "MagicMissile.h"
#include "GameFramework/ProjectileMovementComponent.h"

AFireSpellCast::AFireSpellCast(const FObjectInitializer &ObjInitializer) : Super(ObjInitializer)
{

}

void AFireSpellCast::CastSpell(AMagePawn* Mage, const FHitResult &HitResult)
{
	if (Mage)
	{
		FVector StaffVelocity = Mage->GetStaffVelocity();
		if (MissileClass != NULL)
		{
			UWorld* World = GetWorld();
			if (World)
			{
				FVector Orientation = StaffVelocity;
				Orientation.ToOrientationRotator();
				FTransform SpawnTransform;
				SpawnTransform.SetLocation(GetActorLocation());
				SpawnTransform.SetRotation(Orientation.ToOrientationQuat());
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = Mage;
				SpawnParams.Instigator = Mage;
				AMagicMissile* Missile = World->SpawnActor<AMagicMissile>(MissileClass, SpawnTransform, SpawnParams);
				if (Missile)
				{
					//Missile->MovementComponent->Velocity = StaffVelocity;
					UE_LOG(LogTemp, Warning, TEXT("Missile Speed: %f"), StaffVelocity.Size());
					Missile->MovementComponent->Velocity = StaffVelocity * 100.0F;
				}
			}
		}
	}
	Destroy();
}