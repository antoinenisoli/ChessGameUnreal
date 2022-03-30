
#pragma once

#include "CoreMinimal.h"

struct FMove
{
	FMove(FIntPoint iOffset, bool iIsFirstMove, boo iCanOnlyKill)
	{
		Offset = iOffset;
		IsFirstMove = isFirstMove;
		CanOnlyKill = iCanOnlyKill;
	}

	FIntPoint Offset;
	bool IsFirstMove;
	bool CanOnlyKill;
};
