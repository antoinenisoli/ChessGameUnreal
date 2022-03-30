#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.h"
#include "Piece.generated.h"

class ABoardTile;

UCLASS(Abstract)
class CHESSPOLE3D_API APiece : public AActor
{
    GENERATED_BODY()

public: 
    APiece();

public:
    void SetColor(bool iIsWhite);
    void Select();
    void Unselect();
    void ManageMaterial();
    void ShowMovePattern();
    virtual TArray<FIntPoint> GetAvailableCells();

public:
    int myTeam;

    UPROPERTY()
        ABoard* myBoard;

    UPROPERTY()
        ABoardTile* myTile;

    UPROPERTY()
        UStaticMeshComponent* PieceMesh;

    UPROPERTY()
        bool IsWhite;
};