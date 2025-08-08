#include "Elevator.h"
#include "Components/SceneComponent.h"

AElevator::AElevator()
{
    PrimaryActorTick.bCanEverTick = true;

    // 创建默认根组件
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    // 创建云组件
    CloudComp = CreateDefaultSubobject<USceneComponent>(TEXT("CloudComp"));
    CloudComp->SetupAttachment(RootComponent);
}

void AElevator::BeginPlay()
{
    Super::BeginPlay();

    // 记录云的初始世界位置
    if (CloudComp)
    {
        CloudStartLocation = CloudComp->GetComponentLocation();
    }
}

void AElevator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!CloudComp) return;

    FVector CurrentLocation = CloudComp->GetComponentLocation();

    // 向下移动
    CurrentLocation.Z -= CloudSpeed * DeltaTime;

    // 回卷瞬移
    if (CloudStartLocation.Z - CurrentLocation.Z >= LoopDistance)
    {
        CurrentLocation = CloudStartLocation;
    }

    // 设置位置（世界空间）
    CloudComp->SetWorldLocation(CurrentLocation, false, nullptr, ETeleportType::TeleportPhysics);
}
