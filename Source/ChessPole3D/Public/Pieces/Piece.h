// Fill out your copyright notice in the Description page of Project Settings.
/*

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piece.generated.h"

UCLASS(abstract)
class CHESSPOLE3D_API APiece : public AActor
{
    GENERATED_BODY()

public:
    APiece();

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite);
    UMaterialInterface* Material;

    void Init(const TCHAR* meshPath, const TCHAR* materialPath);

protected:
    virtual void BeginPlay() override;
};*/


/* ---------------------------------------------------------------------- */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piece.generated.h"

UCLASS(Abstract)
class CHESSPOLE3D_API APiece : public AActor
{
    GENERATED_BODY()

public: 
    APiece();

public:
    void SetColor( bool iIsWhite );

public:
    UPROPERTY()
    UStaticMeshComponent* PieceMesh;

    UPROPERTY()
    bool IsWhite;
};