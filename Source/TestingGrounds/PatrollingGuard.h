// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingUnit.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter, public IPatrollingUnit
{
	GENERATED_BODY()
	
	
public:
	APatrollingGuard();


	void BeginPlay() override;
public:

	TArray<AActor *> * GetPatrolPoints() override;

	UPROPERTY(EditInstanceOnly, Category = "PatrolRoute" )
		TArray<AActor *> PatrolPoints;
	
};
