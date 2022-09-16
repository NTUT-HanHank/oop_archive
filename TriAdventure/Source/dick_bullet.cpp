#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "dick_bullet.h"
namespace game_framework {
	dick_bullet::dick_bullet(int x,int y,int dir)
	{
		dbx = x;
		dby = y;
		direction = dir;
		LoadBitmap(direction);
	}
	int dick_bullet::GetX()
	{
		return dbx;
	}
	int dick_bullet::GetY()
	{
		return dby;
	}
	void dick_bullet::LoadBitmap(int dir)
	{
		db.LoadBitmap(IDB_db, RGB(255,242,0));
		rdb.LoadBitmap(IDB_rdb, RGB(255, 242, 0));
	}
	void dick_bullet::OnMove()
	{
		SetXY();
	}
	void dick_bullet::OnShow()
	{
		if (direction == 0)
		{
			if (dbx != 640)
			{
				db.SetTopLeft(dbx, dby);
				db.ShowBitmap();
				dbx += 15;
			}
		}
		else
		{
			if (dbx != 0)
			{
				rdb.SetTopLeft(dbx, dby);
				rdb.ShowBitmap();
				dbx -= 15;
			}
		}
	}
	void dick_bullet::SetXY()
	{
		if(dbxy.empty()) {
			dbxy.push_back(dbx);
			dbxy.push_back(dbx+db.Width());
			dbxy.push_back(dby);
			dbxy.push_back(dby+db.Height());
		}
		else {
			dbxy[0] = dbx;
			dbxy[1] = dbx+db.Width();
			dbxy[2] = dby;
			dbxy[3] = dby+db.Height();
		  }
	}
	vector<int> dick_bullet::xy()
	{
		return dbxy;
	}
}