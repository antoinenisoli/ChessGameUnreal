#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardTile.generated.h"

class APiece;

UCLASS()
class CHESSPOLE3D_API ABoardTile : public AActor
{
	GENERATED_BODY()
	
public:	
	ABoardTile();
	void Spawn(FVector2D coord, FTransform transform, bool white);
	void PlacePiece(APiece* piece);
	void Light(bool b);
	void ShowPattern(bool b);

public:
	bool occupied;
	APiece* myPiece;
	FVector2D coordinates;

	UPROPERTY()
		UStaticMeshComponent* TileMesh;

private:
	UPROPERTY()
		UMaterialInterface* defaultMat;
	UPROPERTY()
		UMaterialInterface* lightMat;
	UPROPERTY()
		UMaterialInterface* movePatternMat;
};