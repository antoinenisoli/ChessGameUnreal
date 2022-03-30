
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

void AChessController::Init(ABoard* _board)
{
	board = _board;
}

void AChessController::CheckTiles()
{
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

AChessController::FOnTurnEndDelegate& AChessController::OnTurnEndDelegate()
{
	UE_LOG(LogTemp, Display, TEXT("turn end !!"));
	return TurnEndDeletegate;
}

void AChessController::LeftClick()
{
	for (ABoardTile* tile : board->tiles)
		tile->Light(false, "");

	FHitResult TraceResult(ForceInit);
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
	AActor* actor = TraceResult.GetActor();
	for (ABoardTile* tile : board->tiles)
		tile->Light(false, "");

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
			if (tile->occupied && tile->myPiece->myTeam == selectedPiece->myTeam)
				return;

			TArray<FMove> _array = selectedPiece->GetMoves();
			for (FMove move : _array)
			{
				if (move.Offset == tile->coordinates)
				{
					if (move.CanOnlyKill)
					{
						if (tile->occupied)
						{
							tile->myPiece->Destroy();
							tile->PlacePiece(nullptr);
						}
					}

					tile->PlacePiece(selectedPiece);
					selectedPiece->SetNewTile(tile);
					selectedPiece = nullptr;

					TurnEndDeletegate.ExecuteIfBound();
				}
			}
		}
	}
}

void AChessController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//CheckTiles();
}

AChessPlayer* AChessController::GetCurrentPlayer()
{
	return Cast<AChessPlayer>(GetPawn());
}

void AChessController::HighLightTile(ABoardTile* tile)
{
	if (highlightTile)
		highlightTile->Light(false, "");

	highlightTile = tile;
	highlightTile->Light(true, "Light");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *tile->GetFName().ToString());
}

void AChessController::UnLightTile()
{
	if (highlightTile)
	{
		highlightTile->Light(false, "");
		highlightTile = nullptr;
	}
}