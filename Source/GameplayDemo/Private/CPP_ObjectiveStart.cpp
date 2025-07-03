// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ObjectiveStart.h"

#include "Blueprint/UserWidget.h"

void ACPP_ObjectiveStart::SetObjectiveData(const FObjective& NewObjectiveData)
{
	ObjectiveData = NewObjectiveData;
	CurrentTitleText = ObjectiveData.TitleText;
	CurrentContentText = ObjectiveData.ContentText;
}

// Sets default values
ACPP_ObjectiveStart::ACPP_ObjectiveStart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Default Scene Root
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	// Create the Objective Box Component
	ObjectiveBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ObjectiveBox"));

	// Set the size of the Objective Box
	ObjectiveBox->SetBoxExtent(ObjectiveBoxSize);
	// Set the Collision Profile Name and enable overlap events
	ObjectiveBox->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ObjectiveBox->SetGenerateOverlapEvents(true);
	
	// Set the Objective Box as the Root Component
	ObjectiveBox->SetupAttachment(DefaultSceneRoot);
	RootComponent = DefaultSceneRoot;

	//Set the default values for the Objective Data
	ObjectiveInProgress = false;
	ObjectiveBox->ComponentTags.Add({TagSetter});


	FObjective DefaultObjective;
	DefaultObjective.TitleText = FText::FromString("Default Objective Title");
	DefaultObjective.ContentText = FText::FromString("Default Objective Content");
	
	SetObjectiveData(DefaultObjective);
		

}

// Called when the game starts or when spawned
void ACPP_ObjectiveStart::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ACPP_ObjectiveStart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_ObjectiveStart::CompletedTask()
{
	
}

