#include "Pieces/ChessPawn.h"

AChessPawn::AChessPawn()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Pawn"));
    PieceMesh->SetStaticMesh( staticMesh.Object );
}

TArray<FMove> AChessPawn::GetMoves()
{
    TArray<FMove> myMoves;
    if (myTeam == 0)
    {
        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y - 1), true, false));
        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y - 1), true, true));
        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y - 1), true, true));
    }
    else
    {
        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y + 1), true, false));
        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y + 1), true, true));
        myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y + 1), true, true));
    }

    return myMoves;
}
