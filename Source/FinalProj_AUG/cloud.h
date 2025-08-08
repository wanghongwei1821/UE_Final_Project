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
    // ��������ڱ༭����󶨣�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
    USceneComponent* CloudComp;

    // ���ƶ��ٶ� (cm/s)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
    float CloudSpeed = 200.0f;

    // ѭ������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
    float LoopDistance = 2000.0f;

private:
    FVector CloudStartLocation;
};
