#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class YOURPROJECTNAME_API AElevator : public AActor
{
    GENERATED_BODY()

public:
    AElevator();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    // 云组件（在编辑器里绑定）
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
    USceneComponent* CloudComp;

    // 云移动速度 (cm/s)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
    float CloudSpeed = 200.0f;

    // 循环距离
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
    float LoopDistance = 2000.0f;

private:
    FVector CloudStartLocation;
};
