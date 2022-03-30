// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessBishop.h"

AChessBishop::AChessBishop()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Bishop"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

TArray<FMove> AChessBishop::GetMoves()
{
    return DiagonalMoves();
}