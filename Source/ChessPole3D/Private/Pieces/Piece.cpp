
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

TArray<FMove> APiece::DiagonalMoves()
{
    TArray<FMove> myMoves;
    for (int i = 0; i < myBoard->SizeX; i++)
    {
        if (i == 0)
            continue;

        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + i, myTile->coordinates.Y + i), true, false));
        ABoardTile* nextTile = myBoard->GetTileAt(myTile->coordinates.X + i, myTile->coordinates.Y + i);
        if (nextTile && nextTile->occupied)
            break;
    }

    for (int i = 0; i < myBoard->SizeX; i++)
    {
        if (i == 0)
            continue;

        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - i, myTile->coordinates.Y - i), true, false));
        ABoardTile* nextTile = myBoard->GetTileAt(myTile->coordinates.X - i, myTile->coordinates.Y - i);
        if (nextTile && nextTile->occupied)
            break;
    }

    for (int i = 0; i < myBoard->SizeX; i++)
    {
        if (i == 0)
            continue;

        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + i, myTile->coordinates.Y - i), true, false));
        ABoardTile* nextTile = myBoard->GetTileAt(myTile->coordinates.X + i, myTile->coordinates.Y - i);
        if (nextTile && nextTile->occupied)
            break;
    }

    for (int i = 0; i < myBoard->SizeX; i++)
    {
        if (i == 0)
            continue;

        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - i, myTile->coordinates.Y + i), true, false));
        ABoardTile* nextTile = myBoard->GetTileAt(myTile->coordinates.X - i, myTile->coordinates.Y + i);
        if (nextTile && nextTile->occupied)
            break;
    }

    return myMoves;
}

TArray<FMove> APiece::LineMoves()
{
    TArray<FMove> myMoves;

    for (int x = -myBoard->SizeX; x < myBoard->SizeX; x++)
    {
        if (x == 0)
            continue;

        ABoardTile* nextTile = myBoard->GetTileAt(myTile->coordinates.X + x, myTile->coordinates.Y);
        if (nextTile && nextTile->occupied)
            break;

        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + x, myTile->coordinates.Y), true, false));
    }

    for (int y = -myBoard->SizeY; y < myBoard->SizeY; y++)
    {
        if (y == 0)
            continue;

        ABoardTile* nextTile = myBoard->GetTileAt(myTile->coordinates.X, myTile->coordinates.Y + y);
        if (nextTile && nextTile->occupied)
            break;

        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y + y), true, false));
    }

    return myMoves;
}