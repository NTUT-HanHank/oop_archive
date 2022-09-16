#ifndef _GOOMBA_H_
#define _GOOMBA_H_
namespace game_framework {
	class Goomba
	{
	public:
		int GetX();
		int GetY();
		void Initalize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		int	 gethp();
		bool GetHit(int bx, int by);
		void GetEraserXY(int, int);
		void SetMapXY(int x, int y);
		bool isattack();
	protected:
		CAnimation goomba_move;
		int x, y;
		int ex, ey;
		int mx, my;
		int hp;
		bool ishitting;
	};
}
#endif