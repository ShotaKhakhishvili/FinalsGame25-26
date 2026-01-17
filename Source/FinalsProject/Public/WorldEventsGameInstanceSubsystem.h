// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WorldEventsGameInstanceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWEActorSpawned, AActor*, SpawnedActor);

UCLASS(BlueprintType, Blueprintable)
class FINALSPROJECT_API UWorldEventsGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "WorldEvents")
	FOnWEActorSpawned OnActorSpawned;
};
