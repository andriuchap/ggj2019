// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellDetector.h"

bool FSpellDetector::DetectCircle(const TArray<FVector> &Positions, float AcceptanceThreshold, float RadiusVariation, FVector &OutAverageLoc, float &IsCircle)
{
	FVector AverageLocation = FVector::ZeroVector;
	float AverageDistance = 0.0F;
	IsCircle = 0.0F;

	if (Positions.Num() != 0)
	{

		//Attempt to see where the center of the circle is
		for (int i = 0; i < Positions.Num(); i++)
		{
			AverageLocation += Positions[i];
		}

		AverageLocation /= Positions.Num();

		// Attempt to get the point distances to the circle
		TArray<float> Distances;
		for (int i = 0; i < Positions.Num(); i++)
		{
			float Distance = FVector::Distance(AverageLocation, Positions[i]);
			Distances.Add(Distance);
			AverageDistance += Distance;
		}
		AverageDistance /= Positions.Num();

		// We have a minimum radius of a circle set
		if (AverageDistance >= 15.0F)
		{
			int Counter = 0;
			for (int i = 0; i < Distances.Num(); i++)
			{
				float LowBound = AverageDistance * (1 - RadiusVariation);
				float HighBound = AverageDistance * (1 + RadiusVariation);

				if (Distances[i] > LowBound && Distances[i] < HighBound)
				{
					Counter++;
				}
			}
			IsCircle = (float)Counter / (float)Distances.Num();
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("Avg Loc: %s, Avg Dist: %f, Is circle: %f"), *AverageLocation.ToString(), AverageDistance, IsCircle);

	OutAverageLoc = AverageLocation;

	return IsCircle >= AcceptanceThreshold;
}

bool FSpellDetector::DetectShallNotPass(const TArray<FVector>& Positions, FVector HeadLocation, float StaffHalfHeight)
{
	float HeightThreshold = HeadLocation.Z + StaffHalfHeight;
	float StaffHeight = 0.0F;
	if (Positions.Num() > 0)
	{
		for (int i = 0; i < Positions.Num(); i++)
		{
			StaffHeight += Positions[i].Z;
		}

		StaffHeight /= Positions.Num();
	}

	return StaffHeight >= HeightThreshold;
}
