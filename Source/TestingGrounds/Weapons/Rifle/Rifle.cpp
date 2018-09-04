// Fill out your copyright notice in the Description page of Project Settings.

#include "Rifle.h"


// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("Mesh"));
	Mesh->SetCastShadow(false);
	SetRootComponent(Mesh);

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(FName("Muzzle Point"));
	MuzzlePoint->SetupAttachment(Mesh);
	MuzzlePoint->SetRelativeLocation(FVector(0.f, 58.f, 10.f));
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ARifle::Fire()
{
	if(ProjectileClass != nullptr)
		SpawnProjectile();
	else
		return false;

	if(FireSound != nullptr)
		PlayFireSound();
	return true;

}

void ARifle::SpawnProjectile()
{
	UWorld* const World = GetWorld();
	if(!World)
		return;

	const FRotator SpawnRotation = MuzzlePoint->GetComponentRotation();
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	const FVector SpawnLocation = ((MuzzlePoint != nullptr) ? MuzzlePoint->GetComponentLocation() : GetActorLocation());

	//Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// spawn the projectile at the muzzle
	World->SpawnActor<ARifleProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
}

void ARifle::PlayFireSound()
{
	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
}