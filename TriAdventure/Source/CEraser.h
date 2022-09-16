#include "map.h"
#include "Bullet.h"
#ifndef _CERASER_H_
#define _CERASER_H_
namespace game_framework {
	class CEraser
	{
	public:
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize(map* m);				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定擦子左上角座標
		bool GetMovingSituation();
		bool GetMovingLeft();
		bool Getisdead();
		void shooting(bool flag);
		void jump(string state);
		void SetOnFloor();
		int GetJumpCount();
		bool GetOnFloor();
		void  Setdir(int n);
		void SetmapLeft(bool flag);
		void Setinvincible(bool flag);
		bool Getinvincible();
		void judgemonster();
		~CEraser()
		{
			for (int i = 0; i < (int)bullet.size(); i++)
			{
				delete bullet[i];
			}
		}
	protected:
		map *world_1;
		CAnimation animation;		
		CAnimation animation2;
		vector<Bullet*> bullet;
		int x, y, flag = 1;					
		int world[40][12] = { 0 };
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool mapmoving;
		bool mapmovingleft;
		bool attack;
		bool isOnFloor;
		bool isclimbing;
		bool isjumping;
		int jumpCounter;
		bool isdoublejump;
		bool invincible;
		int velocity;
		double timer_bullet;
		int initial_velocity = 15;
		int direction;
		bool isdead;
	};
}
#endif