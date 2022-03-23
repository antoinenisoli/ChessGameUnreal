#pragma once
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"

#include "Pieces/Piece.h"
#include "BoardTile.h"
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
	void Init();

public:
	APiece* selectedPiece;
	ABoardTile* lastTile;
	UStaticMesh* mesh;
	UPROPERTY()
		AStaticMeshActor* highlightCube;
};
