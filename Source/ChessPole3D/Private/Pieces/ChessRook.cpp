// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessRook.h"

AChessRook::AChessRook()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Rook"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessRook::GetMoves()
{
    TArray<FMove> myMoves;
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y - 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y - 1), true, true));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y - 1), true, true));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y + 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y + 1), true, true));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y + 1), true, true));

    return myMoves;
}