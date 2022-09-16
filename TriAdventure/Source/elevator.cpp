#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "elevator.h"
namespace game_framework {
	elevator::elevator(int x1, int y1, int x2, int y2)
	{
		x = x1;
		y = y1;
		bux = x;
		buy = y;
		tx = x2;
		ty = y2;
		dir = 0;
		LoadBitmap();
	}
	int elevator::GetX2()
	{
		return x + map2_elevator.Width();
	}
	int elevator::GetX()
	{
		return x;
	}
	int elevator::GetY()
	{
		return y;
	}
	void elevator::LoadBitmap()
	{
		map2_elevator.LoadBitmap(IDB_elevator);
	}
	void elevator::On_ShowandMove()
	{
		srand(y);
		map2_elevator.SetTopLeft(x, y);
		if (dir == 0)
		{
			y -= rand() % 10 + 5;
			if (y < ty)
			{
				y = ty;
				dir = 1;
			}
		}
		else if (dir == 1)
		{
			y += rand() % 10 + 5;
			if (y > buy)
			{
				y = buy;
				dir = 0;
			}
		}
		map2_elevator.ShowBitmap();
	}
}