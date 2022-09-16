#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "trap_4_1.h"
namespace game_framework
{
	trap4_1::trap4_1(int x,int y,int idenity)
	{
		tx = x;
		ty = y;
		id = idenity;
		ex = 435;
		istriger = false;
		LoadBitmap();
	}
	void trap4_1::GetEraserXY(int x, int y)
	{
		ex = x;
		ey = y;
	}
	int trap4_1::Getty()
	{
		return ty+trap_4_1.Height();
	}
	void trap4_1::LoadBitmap()
	{
		trap_4_1.AddBitmap(IDB_trap_4_1,RGB(35,0,0));
	}
	bool trap4_1::isattack()
	{
		if ((ty >= ey && ty <= ey + 25) || (ty + trap_4_1.Height() >= ey && ty + trap_4_1.Height() <= ey + 25))
		{
			if ((tx >= ex && ex + 25 >= tx) || (tx + 28 >= ex && tx + 28 <= ex + 25) || (tx <= ex && tx + 28 >= ex + 25))
			{
				istriger = false;
				return true;
			}
			return false;
		}
		return false;
	}
	void trap4_1::OnShow()
	{
		if (id == 0)
		{
			trap_4_1.SetTopLeft(tx, ty);
			trap_4_1.OnShow();

			if (ex >= 500)
			{
				istriger = true;
			}
			if (ty + trap_4_1.Height() <= 0)
				istriger = false;
			if (istriger)
				ty -= 20;
		}
		else if (id == 1)
		{
			trap_4_1.SetTopLeft(tx, ty);
			trap_4_1.OnShow();
			if (ex <= 133 && ey>=400)
			{
				istriger = true;
			}
			if (ty + trap_4_1.Height() <= 0)
				istriger = false;
			if (istriger)
				ty -= 20;
		}
	}
}