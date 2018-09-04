// Fill out your copyright notice in the Description page of Project Settings.

#include "FocusOnPlayer.h"

EBTNodeResult::Type UFocusOnPlayer::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{

	//APawn * PlayerPawn = OwnerComp.GetWorld()->GetFirstPlayerController()->GetPawn();
	//if(!PlayerPawn)
	//	return EBTNodeResult::Succeeded;

	//OwnerComp.GetAIOwner()->SetFocus(PlayerPawn);
	OwnerComp.GetAIOwner()->SetFocus(Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(PlayerPawnKey.SelectedKeyName)));
	//OwnerComp.GetBlackboardComponent()->SetValueAsObject(PlayerPawnKey.SelectedKeyName, PlayerPawn);

	return EBTNodeResult::Succeeded;
}
