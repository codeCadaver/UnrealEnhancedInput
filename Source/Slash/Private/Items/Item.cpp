// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * Speed);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * Speed);
}

float AItem::SpinRate(float DeltaTime)
{
	return SpinSpeed * DeltaTime;
}


// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	/*float DeltaZ = Amplitude * FMath::Sin(RunningTime * Speed);

	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));*/


	//DRAW_SPHERE_SINGLEFRAME(GetActorLocation());
	//DRAW_VECTOR_SINGLEFRAME(GetActorLocation(), GetActorLocation() + (GetActorForwardVector() * 100.f));

	//FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	//DRAW_POINT_SINGLEFRAME(AvgVector);
}

