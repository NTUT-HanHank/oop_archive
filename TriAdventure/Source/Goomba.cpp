#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Goomba.h"
namespace game_framework {

	void Goomba::Initalize()
	{
		x = 500;
		y = 175;
		hp = 2;
		ishitting = false;
		LoadBitmap();
	}
	void Goomba::SetMapXY(int x, int y)
	{
		mx = x;
		my = y;
	}
	bool Goomba::isattack()
	{
		if ((y>=ey&&y<=ey+25) || (y+goomba_move.Height()>=ey&& y + goomba_move.Height()<=ey+25))
		{
			if((x>=ex&&ex+25>=x) || (x+39>=ex && x+39<=ex+25) || (x<=ex&& x+39>=ex+25))
				return true;
			return false;
		}
		return false;
	}
	int Goomba::GetX()
	{
		return x;
	}
	int Goomba::GetY()
	{
		return y;
	}
	void Goomba::LoadBitmap()
	{
		goomba_move.AddBitmap(IDB_goomba_1, RGB(0, 160, 0));
		goomba_move.AddBitmap(IDB_goomba_2, RGB(0, 160, 0));
	}
	bool Goomba::GetHit(int bx, int by)
	{
		if ((bx > x + mx && bx < x + mx + goomba_move.Width()) && (by > y&&by < y + goomba_move.Height()))
		{
			hp -= 1;
			return true;
		}
		return false;
	}
	void Goomba::GetEraserXY(int erx, int ery)
	{
		ex = erx;
		ey = ery;
	}
	void Goomba::OnMove()
	{
		goomba_move.SetDelayCount(8);
		goomba_move.OnMove();
	}
	void Goomba::OnShow()
	{
		x -= 1;
		if (hp > 0)
		{
			goomba_move.SetTopLeft(x + mx, y + my);
			goomba_move.OnShow();
		}
		else if (hp <= 0)
		{
			x = -1000;
			y = -1000;
			goomba_move.SetTopLeft(x,y);
			goomba_move.OnShow();
		}
	}
	int Goomba::gethp()
	{
		return hp;
	}
}