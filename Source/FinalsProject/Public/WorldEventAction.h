#pragma once

#include "CoreMinimal.h"
#include "WorldEventsGameInstanceSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "WorldEventAction.generated.h"

UCLASS(Abstract, BlueprintType, EditInlineNew, DefaultToInstanced, Blueprintable)
class FINALSPROJECT_API UWorldEventAction : public UObject
{
  GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Event")
	FName DebugName;

	UFUNCTION(BlueprintCallable, Category = "WorldEvent")
	AActor* SpawnActor(TSubclassOf<AActor> Class, const FTransform& Transform);

	// Creates a runtime copy of an asset-owned action (copies all UPROPERTY values)
	UFUNCTION(BlueprintCallable, Category = "WorldEvent", meta = (DisplayName = "Duplicate Action (Runtime)"))
	static UWorldEventAction* DuplicateRuntime(UWorldEventAction* Source, UObject* NewOuter);

	virtual UWorld* GetWorld() const override;
};
