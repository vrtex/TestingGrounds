// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/Interface.h"
#include "PatrollingUnit.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class UPatrollingUnit : public UInterface
{
	GENERATED_UINTERFACE_BODY()


};

class TESTINGGROUNDS_API IPatrollingUnit
{
public:
	GENERATED_IINTERFACE_BODY()


	virtual TArray<AActor *> & GetPatrolPoints() = 0;

};
