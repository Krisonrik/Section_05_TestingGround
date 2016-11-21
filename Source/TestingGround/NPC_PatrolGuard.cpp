// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "NPC_PatrolGuard.h"


// Sets default values
ANPC_PatrolGuard::ANPC_PatrolGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
		TP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	TP_Gun->SetOnlyOwnerSee(false);			// only the owning player will see this mesh
	TP_Gun->bCastDynamicShadow = false;
	TP_Gun->CastShadow = true;
	//VR_Gun->SetupAttachment(R_MotionController);
	TP_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	TP_Gun->SetupAttachment(RootComponent);

	*/
}

// Called when the game starts or when spawned
void ANPC_PatrolGuard::BeginPlay()
{
	Super::BeginPlay();
	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	//TP_Gun->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

}

// Called every frame
void ANPC_PatrolGuard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input


