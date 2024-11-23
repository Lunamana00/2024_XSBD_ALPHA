// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FractTypes.generated.h"

class UNiagaraSystem;
class UAnimMontage;
class UParticleSystem;
class USoundBase;

// 원소 종류
UENUM(BlueprintType)
enum class EFractElementType : uint8
{
    None UMETA(DisplayName = "None"),
    Fire UMETA(DisplayName = "Fire"),
    Water UMETA(DisplayName = "Water"),
    Earth UMETA(DisplayName = "Earth"),
    Wind UMETA(DisplayName = "Wind"),
    Player UMETA(DisplayName = "Player")
};

// 공격 범위 타입
UENUM(BlueprintType)
enum class EFractAttackRange : uint8
{
    Melee UMETA(DisplayName = "Melee"),
    Ranged UMETA(DisplayName = "Ranged")
};

// 스킬인지 기본 공격인지
UENUM(BlueprintType)
enum class EFractAttackType : uint8
{
    Normal UMETA(DisplayName = "Normal"),
    Skill UMETA(DisplayName = "Skill")
};

// 캐릭터 스테이트
UENUM(BlueprintType)
enum class EFractCharacterState : uint8
{
    ECS_Idle UMETA(DisplayName = "Idle"),
    ECS_Attacking UMETA(DisplayName = "Attacking"),
    ECS_Dodging UMETA(DisplayName = "Dodging"),
    ECS_Hit UMETA(DisplayName = "Hit"),
};

UENUM(BlueprintType)
enum class EFractAttackState : uint8
{
    EAS_RangedAttacking UMETA(DisplayName = "RangedAttacking"),
    EAS_MeleeAttacking UMETA(DisplayName = "MeleeAttacking"),
    EAS_UsingFireGroundSkill UMETA(DisplayName = "Using Fire Ground Skill"),
    EAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
};

// 기본 공격 구조체
USTRUCT(BlueprintType)
struct FFractAttack
{
    GENERATED_BODY()

    // 기본 속성
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DamageMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EFractAttackRange Range = EFractAttackRange::Melee;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EFractAttackType AttackType = EFractAttackType::Normal;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EFractElementType Element = EFractElementType::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsFlyingAttack = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TArray<UAnimMontage*> AttackMontages;
    
};

// 스킬 구조체
USTRUCT(BlueprintType)
struct FFractSkill
{
    GENERATED_BODY()

    // 기본 정보
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Info")
    FText SkillName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Info")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Info")
    bool bIsFlyingSkill = false;

    // 데미지 관련
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float BaseDamage = 50.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float DamageRadius = 200.0f;  

    // 투사체 관련
    // UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    // TSubclassOf<AFractProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    float ProjectileSpeed = 2000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    int32 ProjectileCount = 1;  // 다중 발사 가능

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
    float ProjectileSpread = 0.0f;  // 다중 발사시 퍼지는 각도

    // 원소 속성
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Element")
    EFractElementType Element = EFractElementType::None;

    // 쿨다운
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldown")
    float Cooldown = 5.0f;

    // 비주얼/사운드
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    UAnimMontage* SkillMontage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    UNiagaraSystem* CastEffectSystem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
    USoundBase* CastSound;
};
