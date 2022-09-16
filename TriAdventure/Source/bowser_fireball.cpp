#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "bowser_fireball.h"
namespace game_framework
{
	bowser_fireball::bowser_fireball(int x, int y)
	{
		bfx = x;
		bfy = y;
		t = 60;
		cont = false;
		LoadBitmap();
	}
	int bowser_fireball::GetX()
	{
		return bfx;
	}
	int bowser_fireball::GetY()
	{
		return bfy;
	}
	void bowser_fireball::LoadBitmap()
	{
		bf.AddBitmap(IDB_fireball1, RGB(0,162,232));
		bf.AddBitmap(IDB_fireball2, RGB(0, 162, 232));
		bf.AddBitmap(IDB_fireball3, RGB(0, 162, 232));
		bf.AddBitmap(IDB_fireball4, RGB(0, 162, 232));
	}
	void bowser_fireball::OnShow()
	{
		delay(t);
		bf.SetTopLeft(bfx, bfy);
		bf.OnShow();
		bf.OnMove();
		if (bfy <= 380)
		{
			bfy += 10;
		}
		if (t == 0)
		{
			cont = true;
		}
	}
	void bowser_fireball::OnMove()
	{
		SetXY();
	}
	void bowser_fireball::delay(int &time)
	{
		time -= 1;
	}
	bool bowser_fireball::getcont()
	{
		return cont;
	}
	void bowser_fireball::SetXY()
	{
		if (coordinate.empty()) {
			coordinate.push_back(bfx);
			coordinate.push_back(bfx + bf.Width());
			coordinate.push_back(bfy);
			coordinate.push_back(bfy + bf.Height());
		}
		else {
			coordinate[0] = (bfx);
			coordinate[1] = (bfx + bf.Width());
			coordinate[2] = (bfy);
			coordinate[3] = (bfy + bf.Height());
		}
	}
	vector<int> bowser_fireball::xy()
	{
		return coordinate;
	}
}