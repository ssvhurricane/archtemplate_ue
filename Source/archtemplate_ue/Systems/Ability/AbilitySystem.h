// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/DataTable.h"
#include "AbilitySystem.generated.h"

UENUM(BlueprintType)
enum class EActionModifier : uint8
{
	None,
	Shift,
	Ctrl,
	Alt,
	Cmd,
	Power
};

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	None,
	AttackAbility,
	MovementInSpaceAbility,
	SaveAbility,
	SpecificAbility,
	BuffAbility,
	DeBuffAbility
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None,
	Hands,
	Bow,
	Sword,
	Shield,
	Axe,
};


USTRUCT(BlueprintType)
struct FAbilitySettings : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	FName Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	FName AbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	EAbilityType AbilityType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	float Icon; // TODO: ref Texture.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySettings)
	EActionModifier ActionModifier;
};

/**
 * 
 */
UCLASS()
class ARCHTEMPLATE_UE_API UAbilitySystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AbilitySystemProperty)
	class UDataTable* DataTable;

    // Begin USubsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    // End USubsystem

    UFUNCTION(BlueprintCallable, Category = AbilitySystemMethods)
    void IncrementResourceStat();
private:
    // All my variables

	FAbilitySettings AbilitySettings;
	
};
