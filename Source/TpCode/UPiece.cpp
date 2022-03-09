// Fill out your copyright notice in the Description page of Project Settings.


#include "UPiece.h"

// Sets default values
AUPiece::AUPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUPiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

