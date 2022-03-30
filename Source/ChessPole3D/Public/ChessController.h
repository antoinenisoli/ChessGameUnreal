#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ChessPlayer.h"
#include "Pieces/Piece.h"
#include "BoardTile.h"
#include "Board.h"
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
	void Tick(float DeltaTime);
	void HighLightTile(ABoardTile* tile);
	void UnLightTile();
	void Init(ABoard* _board);
	void CheckTiles();
	AChessPlayer* GetCurrentPlayer();

	DECLARE_DELEGATE(FOnTurnEndDelegate);
	FOnTurnEndDelegate& OnTurnEndDelegate();

private:
	FOnTurnEndDelegate TurnEndDeletegate;

public:
	ABoard* board;
	APiece* selectedPiece;
	ABoardTile* highlightTile;
	ABoardTile* lastTile;
	UStaticMesh* mesh;
};
