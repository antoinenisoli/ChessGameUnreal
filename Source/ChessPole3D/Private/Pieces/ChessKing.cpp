// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessKing.h"

AChessKing::AChessKing()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/King"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessKing::GetMoves()
{
    TArray<FMove> myMoves;
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y), true, false));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y - 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y - 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y - 1), true, false));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X, myTile->coordinates.Y + 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y + 1), true, false));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y + 1), true, false));

    return myMoves;
}