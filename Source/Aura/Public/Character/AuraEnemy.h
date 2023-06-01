// Copyright Dan Stull 

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();

	/** Enemy Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** End Enemy Interface*/

	/** Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	virtual void Die() override;
	/** End Combat Interface*/

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSigniture OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSigniture OnMaxHealthChanged;
	
	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	UPROPERTY(BlueprintReadOnly, Category= Combat)
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category= Combat)
	float BaseWalkSpeed = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Combat)
	float LifeSpan = 5.f;

protected:
	virtual void BeginPlay() override;
	virtual void InitializeDefaultAttributes() const override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Character Class Default")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Character Class Default")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
