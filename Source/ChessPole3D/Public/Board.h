#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardTile.h"
#include "Board.generated.h"

UCLASS()
class CHESSPOLE3D_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	ABoard();

	void Init(int iSizeX, int iSizeY, int iAssetSize);
	void GenerateBoard();
	ABoardTile* GetTileAt(int x, int y);
	bool InGridBounds(int x, int y);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SizeX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AssetSize;

	TArray<ABoardTile*> tiles;
};
