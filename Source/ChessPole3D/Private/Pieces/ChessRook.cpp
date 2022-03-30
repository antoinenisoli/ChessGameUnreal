// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessRook.h"

AChessRook::AChessRook()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Rook"));
    PieceMesh->SetStaticMesh(staticMesh.Object);
}

void AChessRook::ShowMovePattern()
{

}
