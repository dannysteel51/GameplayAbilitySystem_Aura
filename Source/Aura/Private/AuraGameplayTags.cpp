// Copyright Dan Stull 


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 * Primary Attributes
	 */
	GameplayTags.Attributes_Primary_Strength =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Increases physical damage"));

	GameplayTags.Attributes_Primary_Intelligence =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Increases magical damage"));

	GameplayTags.Attributes_Primary_Resilience =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("Increases armor and armor penetration"));

	GameplayTags.Attributes_Primary_Vigor =
			UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Increases Health"));
	
	/*
	 * Secondary Attributes
	 */
	
	GameplayTags.Attributes_Secondary_Armor =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damages taken, improves block chance"));

	GameplayTags.Attributes_Secondary_ArmorPenetration =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Ignored a percentage of the targets armor, increases crit hit"));

	GameplayTags.Attributes_Secondary_BlockChance =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), FString("Chance to cut incoming damage in half"));

	GameplayTags.Attributes_Secondary_CriticalHitChance =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("Chance to double damage plus crit hit bonus"));
	
	GameplayTags.Attributes_Secondary_CriticalHitDamage =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("Bonus damage added when a crit hit is scored"));

	GameplayTags.Attributes_Secondary_CriticalHitResistance =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"), FString("Reduces crit hit damage of attacking enemies"));

	GameplayTags.Attributes_Secondary_HealthRegeneration =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"), FString("Amount of health regenerated per second"));

	GameplayTags.Attributes_Secondary_ManaRegeneration =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"), FString("Amount of mana regenerated per second"));
	
	GameplayTags.Attributes_Secondary_MaxHealth =
			UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Players Max Health"));
	
	GameplayTags.Attributes_Secondary_MaxMana =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Players Max Mana"));

	/*
	 * Input tags
	 */
	
	GameplayTags.InputTag_LMB =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"), FString("Input Tag for left mouse button"));

	GameplayTags.InputTag_RMB =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"), FString("Input Tag for right mouse button"));

	GameplayTags.InputTag_1 =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"), FString("Input Tag for 1 key"));
	
	GameplayTags.InputTag_2 =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"), FString("Input Tag for 2 key"));

	GameplayTags.InputTag_3 =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"), FString("Input Tag for 3 key"));

	GameplayTags.InputTag_4 =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"), FString("Input Tag for 4 key"));

	GameplayTags.Damage =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage"), FString("Damage"));

	/*
	 * Damage Types
	 */

	GameplayTags.Damage_Fire =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Fire"),FString("Fire Damage Type"));
	
	GameplayTags.Damage_Lightning =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Lightning"),FString("Lightning Damage Type"));
	
	GameplayTags.Damage_Arcane =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Arcane"),FString("Arcane Damage Type")
			);
	GameplayTags.Damage_Physical =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Physical"),FString("Physical Damage Type"));

	/*
	 * Resistances
	 */

	GameplayTags.Attributes_Resistance_Arcane =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Arcane"), FString("Reduces Arcane damage taken"));

	GameplayTags.Attributes_Resistance_Lightning =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Lightning"), FString("Reduces Lightning damage taken"));

	GameplayTags.Attributes_Resistance_Fire =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Fire"), FString("Reduces Fire damage taken"));

	GameplayTags.Attributes_Resistance_Physical =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Physical"), FString("Reduces Physical damage taken"));

	/*
	 * Map of Damage Types to Resistances
	 */
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistance_Arcane);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistance_Lightning);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistance_Physical);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistance_Fire);
	
	/*
	 * Effects
	 */
	
	GameplayTags.Effects_HitReact =
		UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effects.HitReact"), FString("Tag granted when hit reacting"));
}

