#ifndef _DICK_H_
#define _DICK_H_
#include "dick_bullet.h"
namespace game_framework {
	class dick
	{
	public:
		~dick()
		{
			for (int i = 0; i < (int)vdb.size(); i++)
			{
				delete vdb[i];
			}
		}
		dick(int,int,int);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		int	 getdirection();
		int  getdickx();
		int  getdicky();
		void getEraserXY(int, int);
		vector<int> getdickbulletXY(int);
		int  vdbsize();
		int  AAA();
	protected:
		bool islaunch;
		int dx, dy;
		int dbx, dby;
		int ex, ey;
		int direction;
		CAnimation Dick[2];
		vector<int>	lxy;
		vector<int>	rxy;
		vector<vector<int>>	 ldbxy;
		vector<vector<int>>	 rdbxy;
		vector<dick_bullet*> vdb;
	};
}
#endif