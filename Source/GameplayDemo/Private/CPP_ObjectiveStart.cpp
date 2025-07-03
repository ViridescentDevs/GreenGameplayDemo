// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ObjectiveStart.h"

#include "Blueprint/UserWidget.h"

// Sets default values
ACPP_ObjectiveStart::ACPP_ObjectiveStart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	ObjectiveBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ObjectiveBox"));
	ObjectiveBox->SetBoxExtent(ObjectiveBoxSize);
	ObjectiveBox->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ObjectiveBox->SetGenerateOverlapEvents(true);
	ObjectiveBox->SetupAttachment(DefaultSceneRoot);
	RootComponent = DefaultSceneRoot;
	ObjectiveInProgress = false;
	ObjectiveBox->ComponentTags.Add({TagSetter});
	

}

// Called when the game starts or when spawned
void ACPP_ObjectiveStart::BeginPlay()
{
	Super::BeginPlay();
	
	if (WBP_Objective_C)
	{
		UUserWidget* ObjectiveWidget = CreateWidget<UUserWidget>(GetWorld(), WBP_Objective_C);
		if (ObjectiveWidget)
		{
			ObjectiveWidget->AddToViewport();
			ObjectiveWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create Objective Widget!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WBP_Objective_C is not set!"));
	}
	
}

// Called every frame
void ACPP_ObjectiveStart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

