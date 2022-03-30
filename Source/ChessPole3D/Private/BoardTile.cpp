
#include "BoardTile.h"

ABoardTile::ABoardTile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
	RootComponent->bVisualizeComponent = true;

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>("TileMesh");
	TileMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABoardTile::Spawn(FIntPoint coord, FTransform transform, bool white)
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
	movePatternMat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/MovePatternTile"));
	killMat = LoadObject<UMaterialInterface>(this, TEXT("/Game/Materials/KillTile"));
}

void ABoardTile::PlacePiece(APiece* piece)
{
	occupied = piece != nullptr;
	myPiece = piece;
}

void ABoardTile::Light(bool b, FString color)
{
	UMaterialInterface* mat = nullptr;
	if (!b)
		mat = defaultMat;
	else
	{
		if (color == "Light")
			mat = movePatternMat;
		else if (color == "Kill")
			mat = killMat;
	}

	TileMesh->SetMaterial(0, mat);
}
