// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessQueen.h"

AChessQueen::AChessQueen()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Queen"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}