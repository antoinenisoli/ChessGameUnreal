
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

AChessController::FOnTurnEndDelegate& AChessController::OnTurnEndDelegate()
{
	UE_LOG(LogTemp, Display, TEXT("turn end !!"));
	return TurnEndDeletegate;
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
		APiece* piece = Cast<APiece>(actor);
		if (piece->myTeam == GetCurrentPlayer()->myTeam)
		{
			selectedPiece = piece;
			selectedPiece->Select();
		}
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
				
				TurnEndDeletegate.ExecuteIfBound();
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

		if (actor)
		{
			ABoardTile* tile = nullptr;
			if (actor->IsA(APiece::StaticClass()))
				tile = Cast<APiece>(actor)->myTile;
			else if (actor->IsA(ABoardTile::StaticClass()))
				tile = Cast<ABoardTile>(actor);

			if (tile && highlightTile != tile)
				HighLightTile(tile);
		}
		else
			UnLightTile();
	}
	else 
		UnLightTile();
}

AChessPlayer* AChessController::GetCurrentPlayer()
{
	return Cast<AChessPlayer>(GetPawn());
}

void AChessController::HighLightTile(ABoardTile* tile)
{
	if (highlightTile)
		highlightTile->Light(false);

	highlightTile = tile;
	highlightTile->Light(true);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *tile->GetFName().ToString());
}

void AChessController::UnLightTile()
{
	if (highlightTile)
	{
		highlightTile->Light(false);
		highlightTile = nullptr;
	}
}