
#pragma once
#include "CoreMinimal.h"

struct FMove
{
	FMove(FIntPoint iOffset, bool iIsFirstMove, bool iCanOnlyKill)
	{
		Offset = iOffset;
		IsFirstMove = iIsFirstMove;
		CanOnlyKill = iCanOnlyKill;
	}

public:

	FIntPoint Offset;
	bool IsFirstMove;
	bool CanOnlyKill;
};
