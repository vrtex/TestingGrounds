// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"




EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	
	UBlackboardComponent * BlackboardComp = OwnerComp.GetBlackboardComponent();
	if(!BlackboardComp)
		return EBTNodeResult::Failed;

	// check if guard needs new waypoint (true: has waypoint, no need to get next)
	if(BlackboardComp->GetValueAsBool(ControlKey.SelectedKeyName))
		return EBTNodeResult::Succeeded;


	AAIController * AIComp = OwnerComp.GetAIOwner();
	if(!AIComp)
		return EBTNodeResult::Failed;
	APawn * ControlledPawn = AIComp->GetPawn();
	if(!Cast<IPatrollingUnit>(ControlledPawn))
		return EBTNodeResult::Failed;
	IPatrollingUnit * Guard = Cast<IPatrollingUnit>(ControlledPawn);
	if(!(ControlledPawn && Guard))
		return EBTNodeResult::Failed;


	TArray<AActor *> & PatrolPoints (Guard->GetPatrolPoints());
	if(!(&PatrolPoints))
		return EBTNodeResult::Failed;
	if(PatrolPoints.Num() == 0)
		return EBTNodeResult::Succeeded;

	int32 CurrentIndex = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackboardComp->SetValueAsObject(
		Waypoint.SelectedKeyName,
		(PatrolPoints)[CurrentIndex]
	);
	int32 NextIndex = ++CurrentIndex % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	BlackboardComp->SetValueAsObject(
		NextWaypoint.SelectedKeyName,
		(PatrolPoints)[NextIndex]
	);

	// Set guard has next waypoint flag. To be reset after reaching waypoint
	BlackboardComp->SetValueAsBool(ControlKey.SelectedKeyName, true);

	return EBTNodeResult::Succeeded;
}
