// Copyright Dan Stull 


#include "AbilitySystem/Abilities/AuraSummonAbility.h"

#include "Kismet/KismetSystemLibrary.h"

TArray<FVector> UAuraSummonAbility::GetSpawnLocations()
{
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	const float DeltaSpread = SpawnSpread / (NumMinionsToSpawn);
	
	const FVector LeftOfSpread = Forward.RotateAngleAxis(-SpawnSpread / 2.f, FVector::UpVector);
	TArray<FVector> SpawnLocations;
	for (int32 i = 0; i < NumMinionsToSpawn; i++)
	{
		const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i, FVector::UpVector);
		const FVector ChosenSpawnLocation = FMath::FRandRange(MinDistance, MaxDistance) * Direction + Location;
		SpawnLocations.Add(ChosenSpawnLocation);
		
		DrawDebugSphere(GetWorld(), ChosenSpawnLocation, 18.f, 12.f, FColor::Cyan, false, 3.f);
		UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), Location, Location + Direction * MaxDistance,  5.f, FLinearColor::Green, 5.f, 1.f);
		DrawDebugSphere(GetWorld(), Location + Direction * MinDistance, 5.f, 12.f, FColor::Red, false, 3.f);
		DrawDebugSphere(GetWorld(), Location + Direction * MaxDistance, 5.f, 12.f, FColor::Red, false, 3.f);
	}
	return SpawnLocations;
}
