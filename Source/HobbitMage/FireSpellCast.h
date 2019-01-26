// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpellCast.h"
#include "FireSpellCast.generated.h"

/**
 * 
 */
UCLASS()
class HOBBITMAGE_API AFireSpellCast : public ASpellCast
{
	GENERATED_BODY()
public:
	AFireSpellCast(const FObjectInitializer &ObjInitializer);

public:

	UPROPERTY(EditAnywhere, Category = "Spell Cast")
	TSubclassOf<class AMagicMissile> MissileClass;

protected:

	virtual void CastSpell(AMagePawn* Mage, const FHitResult &HitResult) override;
};
