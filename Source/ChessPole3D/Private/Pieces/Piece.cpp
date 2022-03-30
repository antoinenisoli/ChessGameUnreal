
#include "Pieces/Piece.h"

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
    ManageMaterial();
}

void APiece::Select()
{
    UMaterialInterface* material = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/selectedMat"));
    PieceMesh->SetMaterial(0, material);
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
<<<<<<< Updated upstream
=======

void APiece::SetNewTile(ABoardTile* newTile)
{
    myTile = newTile;
    FVector position = myTile->GetActorLocation();
    position.Z = GetActorLocation().Z;
    SetActorLocation(position);
    Unselect();
}

void APiece::ShowMovePattern()
{
    for (ABoardTile* tile : myBoard->tiles)
        tile->Light(false);

    TArray<FIntPoint> targetCoordinates = GetAvailableCells();
    for (ABoardTile* tile : myBoard->tiles)
        for (FIntPoint coord : targetCoordinates)
        {
            if (tile->coordinates == coord)
            {
                tile->ShowPattern(true);
            }
        }
}

TArray<FIntPoint> APiece::GetAvailableCells()
{
    TArray<FIntPoint> targetCoordinates;
    targetCoordinates.Add(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y + 1));

    return targetCoordinates;
}
>>>>>>> Stashed changes
