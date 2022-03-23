// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/Piece.h"
/*
// Sets default values
APiece::APiece()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
    RootComponent->bVisualizeComponent = true;
}

void APiece::Init(const TCHAR* meshPath, const TCHAR* materialPath)
{
    UStaticMesh* mesh = LoadObject<UStaticMesh>(this, meshPath);

    MeshComponent = NewObject<UStaticMeshComponent>();
    MeshComponent->SetStaticMesh(mesh);
    MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    Material = LoadObject<UMaterialInterface>(this, materialPath);
}

// Called when the game starts or when spawned
void APiece::BeginPlay()
{
    Super::BeginPlay();
}*/


APiece::APiece()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
    RootComponent->bVisualizeComponent = true;

    PieceMesh = CreateDefaultSubobject<UStaticMeshComponent>("PieceMesh");
    PieceMesh->AttachToComponent( RootComponent, FAttachmentTransformRules::KeepRelativeTransform );
}

void APiece::SetColor(bool iIsWhite)
{
    IsWhite = iIsWhite;

    if (IsWhite)
    {
        UMaterialInterface* material = LoadObject<UMaterialInterface>( this, TEXT("/Game/StarterContent/Materials/M_Wood_Pine"));
        PieceMesh->SetMaterial(0, material);
    }
    else
    {
        UMaterialInterface* material = LoadObject<UMaterialInterface>(this, TEXT("/Game/StarterContent/Materials/M_Wood_Walnut"));
        PieceMesh->SetMaterial(0, material);
    }
}
