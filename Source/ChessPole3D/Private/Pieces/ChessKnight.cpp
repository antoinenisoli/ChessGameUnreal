// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessKnight.h"

AChessKnight::AChessKnight()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Knight"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}