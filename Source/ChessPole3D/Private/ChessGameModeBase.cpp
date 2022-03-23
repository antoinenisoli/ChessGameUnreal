#include "ChessGameModeBase.h"
#include "Pieces/ChessPawn.h"

void AChessGameModeBase::BeginPlay()
{
    Board = GetWorld()->SpawnActor<ABoard>();

    UStaticMesh* whiteTileMesh = LoadObject<UStaticMesh>( Board, TEXT("/Game/Meshes/WhiteTile"));
    UStaticMesh* blackTileMesh = LoadObject<UStaticMesh>( Board, TEXT("/Game/Meshes/BlackTile"));
    
    Board->Init(8, 8, 100, whiteTileMesh, blackTileMesh);

    SetupBoard();
}

void AChessGameModeBase::SetupBoard()
{
    for (int x = 0; x < Board->SizeX; x++)
    {
        AddPawn( x, 1, true);
        AddPawn( x, 6, false);
    }
}

void AChessGameModeBase::AddPawn(int iX, int iY, bool iIsWhite)
{
    int rotationDegrees = 0;
    if( !iIsWhite )
        rotationDegrees = 180;

    APiece* piece = GetWorld()->SpawnActor<AChessPawn>(AChessPawn::StaticClass(), GetPieceTransform( iX, iY, rotationDegrees ));
    piece->SetColor( iIsWhite );

    piece->AttachToActor( Board, FAttachmentTransformRules::KeepRelativeTransform );
}

FTransform AChessGameModeBase::GetPieceTransform(int iX, int iY, int iRotationDegrees)
{
    FVector vec ( Board->AssetSize * iX, Board->AssetSize * iY, Board->AssetSize / 2 );
    return FTransform( FRotator( 0, iRotationDegrees, 0 ), vec, FVector( 0.25, 0.25, 0.25 ));
}
