
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

    FVector2D nextCoord = myTile->coordinates;
    nextCoord.Y += 1;

    for (ABoardTile* tile : myBoard->tiles)
    {
        if (tile->coordinates == nextCoord)
        {
            UE_LOG(LogTemp, Display, TEXT("%S"), tile->GetFName().ToString());
            tile->Light(true);
        }
    }
}
