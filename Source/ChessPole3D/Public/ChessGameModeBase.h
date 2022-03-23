// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	virtual void BeginPlay();

	void SetupBoard();

	void AddPawn( int iX, int iY, bool iIsWhite );

	FTransform GetPieceTransform( int iX, int iY, int iRotationDegrees );

public:
	UPROPERTY()
	ABoard* Board;
};
