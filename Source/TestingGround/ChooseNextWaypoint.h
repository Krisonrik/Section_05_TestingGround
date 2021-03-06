// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

class UPatrolRouteComponent;
/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector indexKey;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector waypoint;

private:

	UPatrolRouteComponent* patrolRoute = nullptr;
};
