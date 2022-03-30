
#include "Pieces/Piece.h"

APiece::APiece()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
    RootComponent->bVisualizeComponent = true;

    PieceMesh = CreateDefaultSubobject<UStaticMeshComponent>("PieceMesh");
    PieceMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void APiece::SetColor(bool iIsWhite)
{
    IsWhite = iIsWhite;
    ManageMaterial();
}

void APiece::Select()
{
    UMaterialInterface* material = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/selectedMat"));
    PieceMesh->SetMaterial(0, material);
    ShowMovePattern();
}

void APiece::Unselect()
{
    ManageMaterial();
}

void APiece::ManageMaterial()
{
    UMaterialInterface* mat = nullptr;
    if (IsWhite)
        mat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/WhiteTile"));
    else
        mat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/BlackTile"));

    PieceMesh->SetMaterial(0, mat);
}

void APiece::ShowMovePattern()
{
    for (ABoardTile* tile : myBoard->tiles)
        tile->Light(false);

    TArray<FVector2D> targetCoordinates = GetAvailableCells();
    for (ABoardTile* tile : myBoard->tiles)
        for (FVector2D coord : targetCoordinates)
        {
            if (tile->coordinates == coord)
            {
                UE_LOG(LogTemp, Display, TEXT("%s"), *tile->GetFName().ToString());
                tile->ShowPattern(true);
            }
        }
}

TArray<FVector2D> APiece::GetAvailableCells()
{
    TArray<FVector2D> targetCoordinates;
    targetCoordinates.Add(FVector2D(myTile->coordinates.X, myTile->coordinates.Y + 1));

    return targetCoordinates;
}
