#pragma once

#include "CoreMinimal.h"
#include "Pieces/Piece.h"
#include "ChessRook.generated.h"

UCLASS()
class CHESSPOLE3D_API AChessRook : public APiece
{
	GENERATED_BODY()
	
public:
	AChessRook();
	TArray<FMove> GetMoves() override;
};
