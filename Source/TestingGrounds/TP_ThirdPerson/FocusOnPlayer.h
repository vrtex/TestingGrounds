// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Engine/World.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "GameFramework/Pawn.h"
#include "Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "FocusOnPlayer.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UFocusOnPlayer : public UBTTaskNode
{
	GENERATED_BODY()

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


protected:
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector PlayerPawnKey;
	
};
