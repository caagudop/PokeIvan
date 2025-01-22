// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class EMonType : uint8
{
		Normal = 0 UMETA(DisplayName = "Normal"),
		Fire = 1 UMETA(DisplayName = "Fire"),
		Water = 2 UMETA(DisplayName = "Water"),
		Electric = 3  UMETA(DisplayName = "Electric"),
		Grass  = 4 UMETA(DisplayName = "Grass"),
		Ice = 5 UMETA(DisplayName = "Ice"),
		Fighting  = 6 UMETA(DisplayName = "Fighting"),
		Poison = 7  UMETA(DisplayName = "Poison"),
		Ground = 8 UMETA(DisplayName = "Ground"),
		Flying  = 9 UMETA(DisplayName = "Flying"),
		Psychic = 10  UMETA(DisplayName = "Psychic"),
		Bug = 11  UMETA(DisplayName = "Bug"),
		Rock = 12 UMETA(DisplayName = "Rock"),
		Ghost = 13 UMETA(DisplayName = "Ghost"),
		Dragon = 14 UMETA(DisplayName = "Dragon"),
		Dark = 15 UMETA(DisplayName = "Dark"),
		Steel = 16 UMETA(DisplayName = "Steel"),
		Fairy = 17 UMETA(DisplayName = "Fairy")

	// Attacking	Normal	Fire	Water	Electric	Grass	Ice	Fighting	Poison	Ground	Flying	Psychic	Bug	Rock	Ghost	Dragon	Dark	Steel	Fairy
	// Normal	1	1	1	1	1	1	1	1	1	1	1	1	0.5	0	1	1	0.5	1
	// Fire	1	0.5	0.5	1	2	2	1	1	1	1	1	2	0.5	1	0.5	1	2	1
	// Water	1	2	0.5	1	0.5	1	1	1	2	1	1	1	2	1	0.5	1	1	1
	// Electric	1	1	2	0.5	0.5	1	1	1	0	2	1	1	1	1	0.5	1	1	1
	// Grass	1	0.5	2	1	0.5	1	1	0.5	2	0.5	1	0.5	2	1	0.5	1	0.5	1
	// Ice	1	0.5	0.5	1	2	0.5	1	1	2	2	1	1	1	1	2	1	0.5	1
	// Fighting	2	1	1	1	1	2	1	0.5	1	0.5	0.5	0.5	2	0	1	2	2	0.5
	// Poison	1	1	1	1	2	1	1	0.5	0.5	1	1	1	0.5	0.5	1	1	0	2
	// Ground	1	2	1	2	0.5	1	1	2	1	0	1	0.5	2	1	1	1	2	1
	// Flying	1	1	1	0.5	2	1	2	1	1	1	1	2	0.5	1	1	1	0.5	1
	// Psychic	1	1	1	1	1	1	2	2	1	1	0.5	1	1	1	1	0	0.5	1
	// Bug	1	0.5	1	1	2	1	0.5	0.5	1	0.5	2	1	1	0.5	1	2	0.5	0.5
	// Rock	1	2	1	1	1	2	0.5	1	0.5	2	1	2	1	1	1	1	0.5	1
	// Ghost	0	1	1	1	1	1	1	1	1	1	2	1	1	2	1	0.5	1	1
	// Dragon	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	1	0.5	0
	// Dark	1	1	1	1	1	1	0.5	1	1	1	2	1	1	2	1	0.5	1	0.5
	// Steel	1	0.5	0.5	0.5	1	2	1	1	1	1	1	1	2	1	1	1	0.5	2
	// Fairy	1	0.5	1	1	1	1	2	0.5	1	1	1	1	1	1	2	2	0.5	1
};


USTRUCT(BlueprintType)

struct  FMonStatistics : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
public:
	
	// Number,Name,Form,Type 1,Type 2,HP,Attack,Defense,Sp.Attack,Sp.Defense,Speed
	// 001,Bulbasaur,,Grass,Poison,45,49,49,65,65,45

	FMonStatistics()
	{
		MondexNumber = 0;
		MonName = FName();
		MonForm =  FName();
		MonFType = EMonType::Normal;
		MonSType = EMonType::Normal;
		HpBase = 0;
		AttackBase = 0;
		DefenseBase = 0;
		SpAttackBase = 0;
		SpDefenseBase = 0;
		VelocityBase = 0;
	}

	FMonStatistics(int32 MondexNumberP, FName MonNameP, FName MonFormP, EMonType MonFTypeP, EMonType MonSTypeP, int32 VelocityBaseP, int32 HpBaseP, int32 AttackBaseP, int32 DefenseBaseP, int32 SpAttackBaseP, int32 SpDefenseBaseP)
	{
		MondexNumber = MondexNumberP;
		MonName = MonNameP;
		MonForm = MonFormP ;
		MonFType = MonFTypeP;
		MonSType = MonSTypeP;
		HpBase = HpBaseP;
		AttackBase = AttackBaseP;
		DefenseBase = DefenseBaseP;
		SpAttackBase = SpAttackBaseP;
		SpDefenseBase = SpDefenseBaseP;
		VelocityBase = VelocityBaseP;
	}
	
	/** Mondex number */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 MondexNumber;

	/** Mon name */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	FName MonName;
	
	/** Mon Form - Alola, Mega, etc */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	FName MonForm;

	/** First Mon Type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	EMonType MonFType;
	
	/** Secondary Mon type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	EMonType MonSType;
	
	/** Mon BAse Value HP */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 HpBase;

	/** Mon BAse Value Attack */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 AttackBase;

	/** Mon Base Value Defense */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 DefenseBase;

	/** Mon BAse Value SpAttack */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 SpAttackBase;

	/** Mon Base Value SpDefense */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 SpDefenseBase;

	/** Mon Base Value Velocity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MonStats)
	int32 VelocityBase;

};