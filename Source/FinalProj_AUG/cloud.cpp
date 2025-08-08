#include "Elevator.h"
#include "Components/SceneComponent.h"

AElevator::AElevator()
{
    PrimaryActorTick.bCanEverTick = true;

    // ����Ĭ�ϸ����
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    // ���������
    CloudComp = CreateDefaultSubobject<USceneComponent>(TEXT("CloudComp"));
    CloudComp->SetupAttachment(RootComponent);
}

void AElevator::BeginPlay()
{
    Super::BeginPlay();

    // ��¼�Ƶĳ�ʼ����λ��
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

    // �����ƶ�
    CurrentLocation.Z -= CloudSpeed * DeltaTime;

    // �ؾ�˲��
    if (CloudStartLocation.Z - CurrentLocation.Z >= LoopDistance)
    {
        CurrentLocation = CloudStartLocation;
    }

    // ����λ�ã�����ռ䣩
    CloudComp->SetWorldLocation(CurrentLocation, false, nullptr, ETeleportType::TeleportPhysics);
}
