// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pieces/Piece.h"
#include "ChessKnight.generated.h"

/**
 * 
 */
UCLASS()
class CHESSPOLE3D_API AChessKnight : public APiece
{
	GENERATED_BODY()
	
public:
	AChessKnight();
	TArray<FMove> GetMoves() override;
};
