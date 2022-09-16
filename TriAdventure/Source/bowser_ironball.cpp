#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "bowser_ironball.h"
namespace game_framework
{
	ironball::ironball(int x, int y,int dir)
	{
		ix = x;
		iy = y;
		LoadBitmap();
		direction = dir;
		isready = false;
	}
	int ironball::GetX()
	{
		return ix;
	}
	int ironball::GetY()
	{
		return iy;
	}
	void ironball::LoadBitmap()
	{
		ib.AddBitmap(IDB_ironball1, RGB(194,235,200));
		ib.AddBitmap(IDB_ironball2, RGB(194, 235, 200));
		ib.AddBitmap(IDB_ironball3, RGB(194, 235, 200));
		ib.AddBitmap(IDB_ironball4, RGB(194, 235, 200));
		ib.AddBitmap(IDB_ironball5, RGB(194, 235, 200));
		ib.AddBitmap(IDB_ironball6, RGB(194, 235, 200));
		ib.AddBitmap(IDB_ironball7, RGB(194, 235, 200));
		ib.AddBitmap(IDB_ironball8, RGB(194, 235, 200));
	}
	void ironball::OnMove()
	{
		SetXY();
		ib.OnMove();
	}
	void ironball::OnShow()
	{
		ib.SetTopLeft(ix, iy);
		ib.OnShow();
		ib.OnMove();
		if (iy <= 335 && !isready)
		{
			iy += 10;
			if (iy >= 335)
				isready = true;
		}
		if (ix <= 580 && direction==0 && isready)
		{
			ix += 15;
			if(ix>=580)
				direction = 1;
		}
		else if (ix >= 0 && direction==1 && isready)
		{
			ix -= 15;
			if(ix<=0)
				direction = 0;
		}
	}
	void ironball::SetXY()
	{
		if (coordinate.empty()) {
			coordinate.push_back(ix);
			coordinate.push_back(ix + ib.Width());
			coordinate.push_back(iy);
			coordinate.push_back(iy + ib.Height());
		}
		else {
			coordinate[0] = (ix);
			coordinate[1] = (ix + ib.Width());
			coordinate[2] = (iy);
			coordinate[3] = (iy + ib.Height());
		}
	}
	vector<int> ironball::xy()
	{
		return coordinate;
	}
}