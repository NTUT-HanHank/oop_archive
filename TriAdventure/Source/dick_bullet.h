#ifndef _DICKBULLET_H_
#define _DICKBULLET_H_
namespace game_framework {
	class dick_bullet
	{
	public:
		dick_bullet(int,int,int);
		int GetX();
		int GetY();
		void LoadBitmap(int);
		void OnMove();
		void OnShow();
		void SetXY();
		vector<int> xy();
	protected:
		int direction;
		int dbx, dby;
		vector<int> dbxy;
		CMovingBitmap db;
		CMovingBitmap rdb;
	};
}
#endif