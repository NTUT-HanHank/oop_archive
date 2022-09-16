#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "sunflower_seed.h"
namespace game_framework
{
	sunflower_seed::sunflower_seed(int x, int y)
	{
		seedx = x;
		seedy = y;
		LoadBitmap();
	}
	int sunflower_seed::GetX()
	{
		return seedx;
	}
	int sunflower_seed::GetY()
	{
		return seedy;
	}
	void sunflower_seed::OnShow()
	{
		if (seedy < 480)
		{
			seedy += 1;
			seed.SetTopLeft(seedx, seedy);
			seed.OnShow();
		}
	}
	void sunflower_seed::OnMove()
	{
		seed.OnMove();
		SetXY();
	}
	void sunflower_seed::LoadBitmap()
	{
		seed.AddBitmap(seed01, RGB(239,127,116));
		seed.AddBitmap(seed02, RGB(239,127,116));
		seed.AddBitmap(seed03, RGB(239,127,116));
		seed.AddBitmap(seed04, RGB(239,127,116));
		seed.SetDelayCount(3);
	}
	void sunflower_seed::SetXY()
	{
		if (coordinate.empty()) {
			coordinate.push_back(seedx);
			coordinate.push_back(seedx + seed.Width());
			coordinate.push_back(seedy);
			coordinate.push_back(seedy + seed.Height());
		}
		else {
			coordinate[0] = seedx;
			coordinate[1] = seedx + seed.Width();
			coordinate[2] = seedy;
			coordinate[3] = seedy + seed.Height();
		}
	}
	vector<int> sunflower_seed::seedxy()
	{
		return coordinate;
	}
}