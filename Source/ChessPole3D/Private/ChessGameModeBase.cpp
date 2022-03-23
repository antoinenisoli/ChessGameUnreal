#include "ChessGameModeBase.h"
#include "Pieces/ChessPawn.h"
#include "Pieces/ChessRook.h"
#include "Pieces/ChessKing.h"
#include "Pieces/ChessBishop.h"
#include "Pieces/ChessQueen.h"
#include "Pieces/ChessKnight.h"
#include "ChessPlayer.h"
#include "ChessController.h"

AChessGameModeBase::AChessGameModeBase() : Super()
{
    DefaultPawnClass = AChessPlayer::StaticClass();
    PlayerControllerClass = AChessController::StaticClass();
}

void AChessGameModeBase::BeginPlay()
{
    ChessController = Cast<AChessController>(GetWorld()->GetFirstPlayerController());
    Board = GetWorld()->SpawnActor<ABoard>();

    PlayerOne = GetWorld()->SpawnActor<AChessPlayer>();
    PlayerOne->Init(true, 8, 8, 100);
    PlayerTwo = GetWorld()->SpawnActor<AChessPlayer>();
    PlayerTwo->Init(false, 8, 8, 100);

    Board->Init(8, 8, 100);

    SetupBoard();
    ChessController->Possess(PlayerOne);
}

void AChessGameModeBase::SetupBoard()
{
    //white
    for (int x = 0; x < Board->SizeX; x++)
        AddPiece<AChessPawn>(x, 1, true);

    AddPiece<AChessRook>(0, 0, true);
    AddPiece<AChessRook>(Board->SizeX - 1, 0, true);

    AddPiece<AChessKnight>(1, 0, true);
    AddPiece<AChessKnight>(Board->SizeX - 2, 0, true);

    AddPiece<AChessBishop>(2, 0, true);
    AddPiece<AChessBishop>(Board->SizeX - 3, 0, true);

    AddPiece<AChessQueen>(3, 0, true);

    AddPiece<AChessKing>(Board->SizeX - 4, 0, true);

    //black
    for (int x = 0; x < Board->SizeX; x++)
        AddPiece<AChessPawn>(x, 6, false);

    AddPiece<AChessRook>(0, 7, false);
    AddPiece<AChessRook>(Board->SizeX - 1, 7, false);

    AddPiece<AChessKnight>(1, 7, false);
    AddPiece<AChessKnight>(Board->SizeX - 2, 7, false);

    AddPiece<AChessBishop>(2, 7, false);
    AddPiece<AChessBishop>(Board->SizeX - 3, 7, false);

    AddPiece<AChessQueen>(3, 7, false);

    AddPiece<AChessKing>(Board->SizeX - 4, 7, false);
}

template<typename T>
void AChessGameModeBase::AddPiece(int iX, int iY, bool iIsWhite)
{
    int rotationDegrees = 0;
    if (!iIsWhite)
        rotationDegrees = 180;

    APiece* piece = GetWorld()->SpawnActor<T>(T::StaticClass(), GetPieceTransform(iX, iY, rotationDegrees));
    piece->SetColor(iIsWhite);
    piece->AttachToActor(Board, FAttachmentTransformRules::KeepRelativeTransform);
}

FTransform AChessGameModeBase::GetPieceTransform(int iX, int iY, int iRotationDegrees)
{
    FVector vec (Board->AssetSize * iX, Board->AssetSize * iY, Board->AssetSize / 2);
    return FTransform(FRotator(0, iRotationDegrees, 0), vec, FVector(0.25, 0.25, 0.25));
}
