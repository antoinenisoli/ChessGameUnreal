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

    if (IsWhite)
    {
        UMaterialInterface* material = LoadObject<UMaterialInterface>( this, TEXT("/Game/Materials/WhiteTile"));
        PieceMesh->SetMaterial(0, material);
    }
    else
    {
        UMaterialInterface* material = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/BlackTile"));
        PieceMesh->SetMaterial(0, material);
    }
}
