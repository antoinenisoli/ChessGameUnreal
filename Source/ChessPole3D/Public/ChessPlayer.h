// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ChessPlayer.generated.h"

UCLASS()
class CHESSPOLE3D_API AChessPlayer : public APawn
{
	GENERATED_BODY()

public:
	AChessPlayer();
	void Init(bool isWhite, int iSizeX, int iSizeY, int iAssetSize);

UPROPERTY()
	UCameraComponent* Camera;
};
