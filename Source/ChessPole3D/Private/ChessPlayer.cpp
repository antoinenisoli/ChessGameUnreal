#include "ChessPlayer.h"
#include "Camera/CameraComponent.h"

AChessPlayer::AChessPlayer()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultRootComponent");
	RootComponent->bVisualizeComponent = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("PlayerPointOfView");
	Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AChessPlayer::Init(bool isWhite, int iSizeX, int iSizeY, int iAssetSize)
{
	int rotation = 0;
	if (!isWhite)
		rotation = 180;

	FVector vector = FVector((iSizeX * iAssetSize) / 2 - (iAssetSize / 2), (iSizeY * iAssetSize) / 2 - (iAssetSize / 2), FMath::Max(iSizeX, iSizeY) * iAssetSize);
	FRotator rotator = FRotator(-90, -90, rotation);
	FTransform transform = FTransform(rotator, vector);
	RootComponent->AddWorldTransform(transform);
}