#pragma once

#include "Pieces/Piece.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardTile.generated.h"

UCLASS()
class CHESSPOLE3D_API ABoardTile : public AActor
{
	GENERATED_BODY()
	
public:	
	ABoardTile();
	void Spawn(FTransform transform, bool white);
	void PlacePiece(APiece* piece);
	FVector coordinates;
	bool occupied;
	APiece* myPiece;

	UPROPERTY()
		UStaticMeshComponent* TileMesh;
};
