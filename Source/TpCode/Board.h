// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

UCLASS()
class TPCODE_API ABoard : public AActor
{
    GENERATED_BODY()

public:
    ABoard();

    void Init(FIntPoint size, int assetSize, UStaticMesh* whiteMesh, UStaticMesh* blackMesh);

    void GenerateBoard();


    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    FIntPoint Size;

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    int AssetSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    UInstancedStaticMeshComponent* WhiteTileInstanced;

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    UInstancedStaticMeshComponent* BlackTileInstanced;

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    UStaticMesh* WhiteTileMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    UStaticMesh* BlackTileMesh;
};
