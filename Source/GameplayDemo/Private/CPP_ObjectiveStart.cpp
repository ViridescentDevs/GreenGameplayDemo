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
	ObjectiveData = DefaultObjective;


	ConstructorHelpers::FClassFinder<UUserWidget> WBP_Objective_Ref(TEXT("Content/UI/WBP_Objective")) 
	{
		TSubclassOf<UUserWidget> WBPClass;
		if (WBP_Objective_Ref.Succeeded())
		{
			WBP_Objective_C = WBP_Objective_Ref.Class;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("WBP_Objective_C not found!"));
			WBP_Objective_C = nullptr;
		}
	};
	
		

}

// Called when the game starts or when spawned
void ACPP_ObjectiveStart::BeginPlay()
{
	Super::BeginPlay();
	SetObjectiveData(ObjectiveData);

	CreateWidget( GetWorld(), WBP_Objective_C)->AddToViewport();
	
}

// Called every frame
void ACPP_ObjectiveStart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_ObjectiveStart::CompletedTask()
{
	
}

