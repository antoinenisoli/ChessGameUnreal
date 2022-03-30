
#include "Pieces/Piece.h"

APiece::APiece()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
    RootComponent->bVisualizeComponent = true;

    PieceMesh = CreateDefaultSubobject<UStaticMeshComponent>("PieceMesh");
    PieceMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void APiece::SetNewTile(ABoardTile* newTile)
{
    if (myTile)
        myTile->PlacePiece(nullptr);

    myTile = newTile;
    FVector position = myTile->GetActorLocation();
    position.Z = GetActorLocation().Z;
    SetActorLocation(position);
    Unselect();
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
        mat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/WhitePawn"));
    else
        mat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/BlackPawn"));

    PieceMesh->SetMaterial(0, mat);
}

void APiece::ShowMovePattern()
{
    for (ABoardTile* tile : myBoard->tiles)
        tile->Light(false, "");

    moves = GetMoves();
    for (ABoardTile* tile : myBoard->tiles)
        for (FMove move : moves)
        {
            if (tile->coordinates == move.Offset)
            {
                if (move.CanOnlyKill)
                    tile->Light(true, "Kill");
                else
                    tile->Light(true, "Light");
            }
        }
}

TArray<FMove> APiece::GetMoves()
{
    return TArray<FMove>();
}
