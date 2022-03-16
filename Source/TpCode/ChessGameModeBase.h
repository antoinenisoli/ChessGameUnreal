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
class TPCODE_API AChessGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void BeginPlay();

public:

    UPROPERTY()
        ABoard* Board;
	
};
