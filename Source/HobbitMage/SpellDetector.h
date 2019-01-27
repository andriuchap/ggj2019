// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
static struct  HOBBITMAGE_API FSpellDetector
{

public:
	static bool DetectCircle(const TArray<FVector> &Positions, float AcceptanceThreshold, float RadiusVariation, FVector &OutAverageLoc, float &CircleRadius);

	static bool DetectShallNotPass(const TArray<FVector> &Positions, FVector HeadLocation, float StaffHalfHeight);
};