// Fill out your copyright notice in the Description page of Project Settings.

#include "BoardTile.h"
#include "ChessController.h"

AChessController::AChessController()
{
	bShowMouseCursor = true;
	selectedPiece = nullptr;
}

void AChessController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AChessController::LeftClick);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &AChessController::RightClick);
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