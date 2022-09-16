#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Bullet.h"
namespace game_framework {
	Bullet::Bullet(int ex, int ey, int dir)
	{
		x = ex;
		y = ey;
		direction = dir;
		ishit = false;
		LoadBitmap();
	}
	bool Bullet::HitSituation()
	{
		return ishit;
	}
	void Bullet::SetHit(bool flag)
	{
		ishit = flag;
	}
	void Bullet::LoadBitmap()
	{
		cbullet.LoadBitmap(IDB_Bullet, RGB(0, 0, 0));
	}
	void Bullet::OnShow()
	{
		cbullet.SetTopLeft(x, y);
		if (!ishit)
		{
			cbullet.ShowBitmap();
		}
		if (direction == 1)
		{
			x -= 15;
		}
		else
		{
			x += 15;
		}
	}
	int Bullet::GetX()
	{
		return x;
	}
	int Bullet::GetY()
	{
		return y;
	}
}