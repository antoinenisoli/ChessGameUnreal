// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessKnight.h"

AChessKnight::AChessKnight()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Knight"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessKnight::GetMoves()
{
    TArray<FMove> myMoves;
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 2, myTile->coordinates.Y + 1), true, true));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 2, myTile->coordinates.Y - 1), true, true));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y + 2), true, true));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y + 2), true, true));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 2, myTile->coordinates.Y + 1), true, true));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 2, myTile->coordinates.Y - 1), true, true));

    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X + 1, myTile->coordinates.Y - 2), true, true));
    myMoves.Add(FMove(FIntPoint(myTile->coordinates.X - 1, myTile->coordinates.Y - 2), true, true));

    return myMoves;
}