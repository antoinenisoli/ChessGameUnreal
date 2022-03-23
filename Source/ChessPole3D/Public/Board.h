// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

UCLASS()
class CHESSPOLE3D_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	ABoard();

	void Init(int iSizeX, int iSizeY, int iAssetSize);

	void GenerateBoard();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SizeX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int SizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AssetSize;
};
