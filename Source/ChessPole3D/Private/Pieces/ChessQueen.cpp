
#include "Pieces/ChessQueen.h"

AChessQueen::AChessQueen()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Queen"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessQueen::GetMoves()
{
    TArray<FMove> myMoves;
    myMoves.Append(LineMoves());
    myMoves.Append(DiagonalMoves());

    return myMoves;
}