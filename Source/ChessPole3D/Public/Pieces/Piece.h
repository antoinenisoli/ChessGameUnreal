#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Board.h"
#include "Move.h"
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
    void SetNewTile(ABoardTile* newTile);
    void ShowMovePattern();
    virtual TArray<FMove> GetMoves();

    TArray<FMove> DiagonalMoves();
    TArray<FMove> LineMoves();

public:
    int myTeam;
    TArray<FMove> moves;

    UPROPERTY()
        ABoard* myBoard;

    UPROPERTY()
        ABoardTile* myTile;

    UPROPERTY()
        UStaticMeshComponent* PieceMesh;

    UPROPERTY()
        bool IsWhite;
};