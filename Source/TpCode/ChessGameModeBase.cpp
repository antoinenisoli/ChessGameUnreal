// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessGameModeBase.h"

void AChessGameModeBase::BeginPlay()
{
	Board = GetWorld()->SpawnActor<ABoard>();
	UStaticMesh* whiteTileMesh = LoadObject<UStaticMesh>(Board, TEXT("/Game/Meshes/WhileTileMesh"));
	UStaticMesh* blackTileMesh = LoadObject<UStaticMesh>(Board, TEXT("/Game/Meshes/blackTileMesh"));
	Board->Init(FIntPoint(8, 8), 100, whiteTileMesh, blackTileMesh);
}