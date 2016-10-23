// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	auto blackboardComponent = OwnerComp.GetBlackboardComponent();

	if (!ensure(blackboardComponent)) { return EBTNodeResult::Failed; }

	auto index = blackboardComponent->GetValueAsInt(indexKey.SelectedKeyName);
	//UE_LOG(LogTemp,Warning,TEXT("Waypoint index: %i"), index)

	auto curThirdPersonAI = OwnerComp.GetAIOwner();
	if (!ensure(curThirdPersonAI)) { return EBTNodeResult::Failed; }
	
	auto aiPawn = curThirdPersonAI->GetPawn();

	patrolRoute = aiPawn->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(patrolRoute)) { return EBTNodeResult::Failed; }

	auto patrolPoints = patrolRoute->GetPatrolPoints();

	if (patrolPoints.Num() != 0) {

		blackboardComponent->SetValueAsObject(waypoint.SelectedKeyName, patrolPoints[index]);
		index += 1;
		int32 nextWaypointIndex = FMath::Fmod(index, patrolPoints.Num());
		blackboardComponent->SetValueAsInt(indexKey.SelectedKeyName, nextWaypointIndex);
	}

	//UE_LOG(LogTemp,Warning,TEXT("Waypoint index after increment: %i"), nextWaypointIndex)

	//UE_LOG(LogTemp, Warning, TEXT("number of patrol points : %i"), patrolPoints.Num())
	return EBTNodeResult::Succeeded;
}


