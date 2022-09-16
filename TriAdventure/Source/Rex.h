#ifndef _REX_H_
#define _REX_H_
namespace game_framework
{
	class Rex
	{
	public:
		int GetX();
		int GetY();
		Rex(int,int);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		bool GetHit(int bx, int by);
		void GetEraserXY(int x,int y);
		int  GetHp();
		bool isattack();
	protected:
		double timer_hurt;
		double timer_gethit;
		CAnimation rex_idle;
		CAnimation rex_walk;
		CAnimation rex_hurt;
		int rx, ry;
		int ex, ey;
		int hp;
		bool ishitting;
	};
}
#endif