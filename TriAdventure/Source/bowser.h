#ifndef _BOWSER_H_
#define _BOWSER_H_
#include "bowser_fireball.h"
#include "bowser_ironball.h"
namespace game_framework
{
	class bowser
	{
	public:
		bowser::~bowser()
		{
			for (int i = 0; i < (int)bfb.size(); i++)
			{
				delete bfb[i];
			}
		}
		bowser(int,int);
		int GetX();
		int GetY();
		int GetY2();
		void sett2();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		bool getisanimation();
		bool ifishurt();
		bool GetHit(int bx, int by);
		void GetEraserXY(int x, int y);
		int GetHp();
		void delay(int &);
		void delayfireball(int &);
		void DeleteObject();
		void Setmovex();
		int bfbSize();
		vector<int> getbfbXY(int);
		int irbSize();
		vector<int> getirbXY(int);
		void GetKill(bool);
	protected:
		int bowx, bowy;
		CAnimation flight;
		CAnimation flightr;
		CAnimation bowser_creep;
		CAnimation bowser_move;
		CAnimation bowser_mover;
		CAnimation bowser_hurt;
		CAnimation bowser_hurtr;
		CAnimation bowser_dead;
		CMovingBitmap lifebar;
		CMovingBitmap lifebar_m;
		CAnimation	special_attack1;
		vector<bowser_fireball*> bfb;
		vector<ironball*> irb;
		int cc;
		bool kill;
		bool isinvincible;
		bool isadd;
		bool isfireballfinish;
		bool isironballfinish;
		bool readys;
		bool readys2;
		bool isdead;
		int ex, ey;
		bool isfire;
		int t;
		int t2;
		int t3;
		int t4;
		int delay_specialAttack;
		int hp;
		bool isanimation;
		int direction;
		bool ishitting;
		bool isready;
		int movex;
	};
}
#endif