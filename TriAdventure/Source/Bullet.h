#ifndef _BULLET_H_
#define _BULLET_H_
namespace game_framework {
	class Bullet
	{
	public:
		Bullet(int ex, int ey, int dir);
		int GetX();
		int GetY();
		void LoadBitmap();
		void OnShow();
		void SetHit(bool flag);
		bool HitSituation();
	protected:
		int x, y;
		int direction;
		bool ishit;
		CMovingBitmap cbullet;
	};
}
#endif 