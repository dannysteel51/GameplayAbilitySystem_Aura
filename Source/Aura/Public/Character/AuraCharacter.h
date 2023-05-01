// Copyright Dan Stull 

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Player/AuraPlayerState.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	
	virtual void PossessedBy(AController* NewController) override; //Setting controller and Init Actor Ability Info
	virtual void OnRep_PlayerState() override; //Setting player state and Init Actor Ability Info

	/** CombatInterface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */

private:
	virtual void InitAbilityActorInfo() override;
};
