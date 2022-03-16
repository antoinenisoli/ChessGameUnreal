// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

// Sets default values
ABoard::ABoard()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
    RootComponent->bVisualizeComponent = true;

    WhiteTileInstanced = CreateDefaultSubobject<UInstancedStaticMeshComponent>("WhiteTile");
    BlackTileInstanced = CreateDefaultSubobject<UInstancedStaticMeshComponent>("BlackTile");

    WhiteTileInstanced->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    BlackTileInstanced->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABoard::Init(FIntPoint size, int assetSize, UStaticMesh* whiteTileMesh, UStaticMesh* blackTileMesh)
{
    Size = size;
    AssetSize = assetSize;
    WhiteTileMesh = whiteTileMesh;
    BlackTileMesh = blackTileMesh;

    WhiteTileInstanced->SetStaticMesh(WhiteTileMesh);
    BlackTileInstanced->SetStaticMesh(BlackTileMesh);

    GenerateBoard();
}

void ABoard::GenerateBoard()
{
    WhiteTileInstanced->ClearInstances();
    BlackTileInstanced->ClearInstances();

    for (int y = 0; y < Size.Y; y++)
    {
        for (int x = 0; x < Size.X; x++)
        {
            FTransform transform;
            transform.SetTranslation(FVector(x * AssetSize, y * AssetSize, 0));

            if ((x + y) % 2 == 0)
                BlackTileInstanced->AddInstance(transform);
            else
                WhiteTileInstanced->AddInstance(transform);
        }
    }
}

