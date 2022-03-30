#pragma once
#include "CoreMinimal.h"
#include "Pieces/Piece.h"
#include "ChessBishop.generated.h"

UCLASS()
class CHESSPOLE3D_API AChessBishop : public APiece
{
	GENERATED_BODY()
	
public:
	AChessBishop();
	TArray<FMove> GetMoves() override;
};