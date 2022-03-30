
#include "ChessController.h"

AChessController::AChessController()
{
	bShowMouseCursor = true;
	selectedPiece = nullptr;

	ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Meshes/HighlightMesh"));
	mesh = staticMesh.Object;
}

void AChessController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AChessController::LeftClick);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &AChessController::RightClick);
}

void AChessController::Init()
{
	highlightCube = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass());
	highlightCube->SetMobility(EComponentMobility::Movable);
	highlightCube->SetActorScale3D(FVector(1, 1, 0.2));

	UStaticMeshComponent* MeshComponent = highlightCube->GetStaticMeshComponent();
	if (MeshComponent)
		MeshComponent->SetStaticMesh(mesh);
}

void AChessController::LeftClick()
{
	FHitResult TraceResult(ForceInit);
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
	AActor* actor = TraceResult.GetActor();

	if (selectedPiece)
	{
		selectedPiece->Unselect();
		selectedPiece = nullptr;
	}

	if (actor && actor->IsA(APiece::StaticClass()))
	{
		selectedPiece = Cast<APiece>(actor);
		selectedPiece->Select();
		UE_LOG(LogTemp, Display, TEXT("%s"), *selectedPiece->GetFName().ToString());
	}
}

void AChessController::RightClick()
{
	if (selectedPiece)
	{
		FHitResult TraceResult(ForceInit);
		GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
		AActor* actor = TraceResult.GetActor();

		if (actor && actor->IsA(ABoardTile::StaticClass()))
		{
			ABoardTile* tile = Cast<ABoardTile>(actor);
			if (!tile->occupied)
			{
				UE_LOG(LogTemp, Display, TEXT("%s"), *tile->GetFName().ToString());

				FVector position = tile->GetActorLocation();
				position.Z = selectedPiece->GetActorLocation().Z;

				selectedPiece->SetActorLocation(position);
				tile->PlacePiece(selectedPiece);
				selectedPiece->Unselect();
				selectedPiece = nullptr;
			}
		}
	}
}

void AChessController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	highlightCube->SetActorHiddenInGame(selectedPiece == nullptr);

	if (selectedPiece)
	{
		FHitResult TraceResult(ForceInit);
		GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
		AActor* actor = TraceResult.GetActor();

		if (actor && actor->IsA(ABoardTile::StaticClass()))
		{
			ABoardTile* tile = Cast<ABoardTile>(actor);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *tile->GetFName().ToString());

			if (highlightTile != tile)
			{
				if (highlightTile)
					highlightTile->Light(false);

				highlightTile = tile;
				highlightTile->Light(true);
			}

			if (highlightCube)
			{
				FVector pos = tile->GetActorLocation();
				pos.Z = TraceResult.ImpactPoint.Z;
				highlightCube->SetActorLocation(pos);
			}
		}
	}
}