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
    void SetColor(bool iIsWhite);
    void Select();
    void Unselect();
    void ManageMaterial();

public:
    UPROPERTY()
        UStaticMeshComponent* PieceMesh;

    UPROPERTY()
        bool IsWhite;
};