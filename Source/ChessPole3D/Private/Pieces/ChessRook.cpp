
#include "Pieces/ChessRook.h"

AChessRook::AChessRook()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Rook"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessRook::GetMoves()
{
    return LineMoves();
}