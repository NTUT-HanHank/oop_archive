#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Pollen.h"
namespace game_framework
{
	Pollen::Pollen(int x, int y)
	{
		px = x;
		py = y;
		count = 0;
		LoadBitmap();
	}
	int Pollen::GetX()
	{
		return px;
	}
	int Pollen::GetY()
	{
		return py;
	}
	void Pollen::LoadBitmap()
	{
		polen.AddBitmap(Pollen_01, RGB(0, 128, 128));
		polen.AddBitmap(Pollen_02, RGB(0, 128, 128));
		polen.AddBitmap(Pollen_03, RGB(0, 128, 128));
		polen.AddBitmap(Pollen_04, RGB(0, 128, 128));
		polen.AddBitmap(Pollen_05, RGB(0, 128, 128));
		polen.SetDelayCount(2);
	}
	void Pollen::OnMove()
	{
		polen.OnMove();
		SetXY();
	}
	void Pollen::OnShow()
	{
		if (px >= 0)
		{
			polen.SetTopLeft(px, py);
			polen.OnShow();
			px -= 15;
		}
	}
	void Pollen::delay(int &time)
	{
		time -= 1;
	}
	void Pollen::SetXY()
	{
		if (coordinate.empty()) {
			coordinate.push_back(px);
			coordinate.push_back(px + polen.Width());
			coordinate.push_back(py);
			coordinate.push_back(py + polen.Height());
		}
		else {
			coordinate[0] = (px);
			coordinate[1] = (px + polen.Width());
			coordinate[2] = (py);
			coordinate[3] = (py + polen.Height());
		}
	}
	vector<int> Pollen::xy()
	{
		return coordinate;
	}
}