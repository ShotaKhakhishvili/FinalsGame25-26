// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldEventAction.h"
#include "WorldEventsGameInstanceSubsystem.h"

AActor* UWorldEventAction::SpawnActor(TSubclassOf<AActor> Class, const FTransform& Transform)
{
	UWorld* World = GetWorld();
	if (!World || !*Class)
		return nullptr;

	AActor* NewActor = World->SpawnActor<AActor>(Class, Transform);
	if (!NewActor)
		return nullptr;

	UE_LOG(LogTemp, Log, TEXT("Spawned Actor %s from WorldEventAction %s"), *NewActor->GetName(), *GetName());

	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UWorldEventsGameInstanceSubsystem* Subsys = GI->GetSubsystem<UWorldEventsGameInstanceSubsystem>())
		{
			Subsys->OnActorSpawned.Broadcast(NewActor);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Broadcasted OnActorSpawned for Actor %s"), *NewActor->GetName());

	return NewActor;
}

UWorld* UWorldEventAction::GetWorld() const
{
	return GetOuter() ? GetOuter()->GetWorld() : nullptr;
}

UWorldEventAction* UWorldEventAction::DuplicateRuntime(UWorldEventAction* Source, UObject* NewOuter)
{
	if (!Source || !NewOuter)
	{
		return nullptr;
	}
	return DuplicateObject<UWorldEventAction>(Source, NewOuter);
}