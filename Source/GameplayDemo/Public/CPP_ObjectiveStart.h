// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "CPP_ObjectiveStart.generated.h"

USTRUCT()

struct FObjective
{
	GENERATED_BODY()

	public:
	/** Current Task Title Text */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Objective Data")
	FText ObjectiveTitleText;

	/** Current Task Content Text */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Objective Data", meta=(MultiLine="true"))
	FText ObjectiveContentText;
	
};

UCLASS()

class GAMEPLAYDEMO_API ACPP_ObjectiveStart : public AActor
{
	GENERATED_BODY()


public:
	/** Name of the Collision Bounds */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Tasks")
	TObjectPtr<UBoxComponent> ObjectiveBox;

	/**Object Pointer to the SceneRoot */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Tasks")
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	/** Size of the Cube when spawned, default as 50^3 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Tasks")
	FVector ObjectiveBoxSize = FVector(50.0f, 50.0f, 50.0f);

	/** Data for the Objective */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Tasks")
	FObjective ObjectiveData;
	
	/** Is a Task currently in Progress? */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Tasks", meta=(MultiLine="true"))
	bool ObjectiveInProgress;

	/** Widget pointer to the Objective Blueprint */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Tasks", meta=(EditInline="true", BindWidget))
	UUserWidget* WBP_Objective_C;

	/** Sets the Tag to whatever the variable's name is */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Tasks", meta=(ExposeOnSpawn="true"))
	FName TagSetter;
	
	/** Queue that holds all the tasks */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Tasks", meta=(ExposeOnSpawn="true"))
	TQueue<ObjectiveData> TaskQueue;


	// Sets default values for this actor's properties
	ACPP_ObjectiveStart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
