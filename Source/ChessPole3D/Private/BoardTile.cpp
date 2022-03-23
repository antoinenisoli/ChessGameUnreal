
#include "BoardTile.h"

ABoardTile::ABoardTile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
	RootComponent->bVisualizeComponent = true;

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>("TileMesh");
	TileMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABoardTile::Spawn(FTransform transform, bool white)
{
	this->SetActorTransform(transform);

	if (!white)
	{
		UStaticMesh* whiteTileMesh = LoadObject<UStaticMesh>(this, TEXT("/Game/Meshes/WhiteTile"));
		TileMesh->SetStaticMesh(whiteTileMesh);
	}
	else
	{
		UStaticMesh* blackTileMesh = LoadObject<UStaticMesh>(this, TEXT("/Game/Meshes/BlackTile"));
		TileMesh->SetStaticMesh(blackTileMesh);
	}
}

void ABoardTile::PlacePiece(APiece* piece)
{
	occupied = piece != nullptr;
	myPiece = piece;
}
