// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessKing.h"

AChessKing::AChessKing()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/King"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}