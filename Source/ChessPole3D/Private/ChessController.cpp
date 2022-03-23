// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessController.h"

void AChessController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AChessController::LeftClick);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &AChessController::RightClick);
}

void AChessController::LeftClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Left click"));
}

void AChessController::RightClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Right click"));
}