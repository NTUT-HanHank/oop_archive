#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Rex.h"
namespace game_framework
{
	int Rex::GetX()
	{
		return rx;
	}
	int Rex::GetY()
	{
		return ry;
	}
	Rex::Rex(int x,int y)
	{
		rx = x;
		ry = y;
		hp = 5;
		timer_hurt = -1;
		timer_gethit = -1;
		ishitting = false;
		LoadBitmap();
	}
	void Rex::LoadBitmap()
	{
		rex_hurt.AddBitmap(IDB_rex_hurt, RGB(165, 235, 255));
		rex_hurt.AddBitmap(IDB_rex_hurt, RGB(165, 235, 255));
		rex_hurt.AddBitmap(IDB_rex_hurt, RGB(165, 235, 255));
		rex_idle.AddBitmap(IDB_rex_idle, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk1, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk2, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk3, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk4, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk5, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk6, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk7, RGB(165, 235, 255));
		rex_walk.AddBitmap(IDB_rex_walk8, RGB(165, 235, 255));
	}
	bool Rex::GetHit(int bx, int by)
	{
		if ((bx > rx && bx <rx + rex_idle.Width()) && (by > ry&&by < ry + rex_idle.Height()))
		{
			hp -= 1;
			ishitting = true;
			return true;
		}
		return false;
	}
	bool Rex::isattack()
	{
		if ((ry+10 >= ey && ry+10 <= ey + 25) || (ry + 43 >= ey && ry + 43 <= ey + 25))
		{
			if ((rx >= ex && ex + 25 >= rx) || (rx + 30 >= ex && rx + 30 <= ex + 25) || (rx <= ex && rx + 30 >= ex + 25))
				return true;
			return false;
		}
		return false;
	}
	void Rex::GetEraserXY(int x, int y)
	{
		ex = x;
		ey = y;
	}
	int Rex::GetHp()
	{
		return hp;
	}
	void Rex::OnMove()
	{
		if(ishitting)
			rex_hurt.OnMove();
		rex_walk.SetDelayCount(5);
		rex_walk.OnMove();
	}
	void Rex::OnShow()
	{
		if (hp > 0)
		{
			if (ishitting)
			{
				rex_hurt.SetTopLeft(rx, ry);
				rex_hurt.OnShow();
				if (rex_hurt.IsFinalBitmap())
				{
					ishitting = false;
					rex_hurt.Reset();
				}
			}
			else {
				if (rx - ex > 300 || abs(ey - ry) >= 20)
				{
					rex_idle.SetTopLeft(rx, ry);
					rex_idle.OnShow();
				}
				else if(rx-ex<300 && abs(ey - ry) < 20)
				{
					rx -= 2;
					rex_walk.SetTopLeft(rx, ry);
					rex_walk.OnShow();
				}
			}
		}
	}
}