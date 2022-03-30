
#include "BoardTile.h"

ABoardTile::ABoardTile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
	RootComponent->bVisualizeComponent = true;

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>("TileMesh");
	TileMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABoardTile::Spawn(FVector2D coord, FTransform transform, bool white)
{
	coordinates = coord;
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

	defaultMat = TileMesh->GetMaterial(0);
}

void ABoardTile::PlacePiece(APiece* piece)
{
	occupied = piece != nullptr;
	myPiece = piece;
}

void ABoardTile::Light(bool b)
{
	UMaterialInterface* mat = nullptr;
	if (b)
		mat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/HighLightedTile"));
	else
		mat = defaultMat;

	TileMesh->SetMaterial(0, mat);
}
