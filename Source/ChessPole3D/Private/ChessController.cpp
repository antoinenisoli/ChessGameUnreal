// Fill out your copyright notice in the Description page of Project Settings.


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
		selectedPiece->Unselect();

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

		if (actor)
		{
			UE_LOG(LogTemp, Display, TEXT("right click"));
		}
	}
}