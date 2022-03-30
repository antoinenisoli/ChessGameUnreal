// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pieces/Piece.h"
#include "ChessQueen.generated.h"

/**
 * 
 */
UCLASS()
class CHESSPOLE3D_API AChessQueen : public APiece
{
	GENERATED_BODY()
	
public:
	AChessQueen();
	TArray<FMove> GetMoves() override;
};
