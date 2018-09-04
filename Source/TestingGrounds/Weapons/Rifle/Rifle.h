// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapons/Rifle/RifleProjectile.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Rifle.generated.h"

UCLASS()
class TESTINGGROUNDS_API ARifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// returns true if managed to fire
	bool Fire();
	

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		USkeletalMeshComponent * Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		USceneComponent * MuzzlePoint = nullptr;

protected:
	UPROPERTY(EditAnywhere, Category = "Firing")
		TSubclassOf<ARifleProjectile> ProjectileClass;


	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase * FireSound = nullptr;

private:

	void SpawnProjectile();

	void PlayFireSound();

};
