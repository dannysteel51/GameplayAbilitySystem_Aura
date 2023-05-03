// Copyright Dan Stull 

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *  Aura Gameplay Tags
 *
 *  A Singleton containing native Gameplay Tags for Aura
 */

struct FAuraGameplayTags
{
public:
    static const FAuraGameplayTags& Get() {return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;

protected:

private:
	static FAuraGameplayTags GameplayTags;
};
