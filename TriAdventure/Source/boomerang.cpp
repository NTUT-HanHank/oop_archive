#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "boomerang.h"
namespace game_framework
{
	boomerang::boomerang(int x, int y)
	{
		boomx = x;
		boomy = y;
		LoadBitmap();
		t = 30;
		com = false;
		turn = false;
	}
	int boomerang::GetX()
	{
		return boomx;
	}
	int boomerang::GetY()
	{
		return boomy;
	}
	void boomerang::LoadBitmap()
	{
		boom.AddBitmap(boomerang01, RGB(239, 127, 116));
		boom.AddBitmap(boomerang02, RGB(239, 127, 116));
		boom.AddBitmap(boomerang03, RGB(239, 127, 116));
		boom.AddBitmap(boomerang04, RGB(239, 127, 116));
		boom.AddBitmap(boomerang05, RGB(239, 127, 116));
		boom.AddBitmap(boomerang06, RGB(239, 127, 116));
		boom.AddBitmap(boomerang07, RGB(239, 127, 116));
		boom.AddBitmap(boomerang08, RGB(239, 127, 116));
		boom.SetDelayCount(2);
	}
	void boomerang::OnMove()
	{
		boom.OnMove();
		SetXY();
	}
	void boomerang::OnShow()
	{
		boom.SetTopLeft(boomx, boomy);
		boom.OnShow();
		delay(t);
		if (t <= 0)
		{
			if (boomx >= -150 && !turn)
			{
				boomx -= 20;
				
			}
			else if (boomx <= -150)
			{
				turn = true;
			}
			if (turn)
			{
				boomy = 133;
				boomx += 20;
			}
		}
	}
	void boomerang::delay(int &time)
	{
		time-=1;
	}
	void boomerang::SetXY()
	{
		if (coordinate.empty()) {
			coordinate.push_back(boomx);
			coordinate.push_back(boomx + boom.Width());
			coordinate.push_back(boomy);
			coordinate.push_back(boomy + boom.Height());
		}
		else {
			coordinate[0] = boomx;
			coordinate[1] = boomx + boom.Width();
			coordinate[2] = boomy;
			coordinate[3] = boomy + boom.Height();
		}
	}
	vector<int> boomerang::xy()
	{
		return coordinate;
	}
}