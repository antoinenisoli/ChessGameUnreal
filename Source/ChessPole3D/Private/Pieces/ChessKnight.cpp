
#include "Pieces/ChessKnight.h"

AChessKnight::AChessKnight()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Knight"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessKnight::GetMoves()
{
    TArray<FMove> myMoves;
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 2, myTile->coordinates.Y + 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 2, myTile->coordinates.Y - 1), true, false));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y + 2), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y + 2), true, false));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 2, myTile->coordinates.Y + 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 2, myTile->coordinates.Y - 1), true, false));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y - 2), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y - 2), true, false));

    return myMoves;
}