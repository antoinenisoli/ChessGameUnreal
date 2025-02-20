#include "Board.h"
#include "BoardTile.h"

ABoard::ABoard()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
    RootComponent->bVisualizeComponent = true;
}

void ABoard::Init(int iSizeX, int iSizeY, int iAssetSize)
{
    SizeX = iSizeX;
    SizeY = iSizeY;
    AssetSize = iAssetSize;

    GenerateBoard();
}

void ABoard::GenerateBoard()
{
    for (int y = 0; y < SizeY; y++)
    {
        for (int x = 0; x < SizeX; x++)
        {
            ABoardTile* newTile = GetWorld()->SpawnActor<ABoardTile>();
            FTransform transform;
            transform.SetTranslation(FVector(x * AssetSize, y * AssetSize, 0));

            bool white = (x + y) % 2 != 0;
            FIntPoint coord = FIntPoint(x, y);
            newTile->Spawn(coord, transform, white);
            tiles.Add(newTile);
        }
    }
}

ABoardTile* ABoard::GetTileAt(int x, int y)
{
    if (!InGridBounds(x, y))
        return nullptr;

    for (ABoardTile* tile : tiles)
        if (tile->coordinates == FIntPoint(x, y))
            return tile;

    return nullptr;
}

bool ABoard::InGridBounds(int x, int y)
{
    if (x > SizeX)
        return false;
    if (x < 0)
        return false;

    if (y > SizeY)
        return false;
    if (y < 0)
        return false;

    return true;
}

