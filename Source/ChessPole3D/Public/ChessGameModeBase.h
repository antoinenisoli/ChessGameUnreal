// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ChessPlayer.h"
#include "ChessController.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Board.h"
#include "ChessGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHESSPOLE3D_API AChessGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AChessGameModeBase();
	virtual void BeginPlay();

	void SetupBoard();

	template<typename T>
	void AddPiece(int iX, int iY, bool iIsWhite);

	FTransform GetPieceTransform(int iX, int iY, int iRotationDegrees);
	AChessController* ChessController;
	AChessPlayer* PlayerOne;
	AChessPlayer* PlayerTwo;

public:
	UPROPERTY()
	ABoard* Board;
};
