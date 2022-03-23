#pragma once
#include "Pieces/Piece.h"
#include "BoardTile.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessController.generated.h"

UCLASS()
class CHESSPOLE3D_API AChessController : public APlayerController
{
	GENERATED_BODY()

public:
	AChessController();
	virtual void SetupInputComponent() override;

	void LeftClick();
	void RightClick();

public:
	APiece* selectedPiece;
	ABoardTile* lastTile;
};
