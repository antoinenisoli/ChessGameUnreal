// Fill out your copyright notice in the Description page of Project Settings.


#include "Pieces/ChessPawn.h"

AChessPawn::AChessPawn()
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/Pawn"));
    PieceMesh->SetStaticMesh( staticMesh.Object );
}
