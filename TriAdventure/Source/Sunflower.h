#ifndef _SUNFLOWER_H_
#define _SUNFLOWER_H_
#include "sunflower_seed.h"
#include "boomerang.h"
#include "Pollen.h"
namespace game_framework
{
	class Sunflower
	{
	public:
		Sunflower(int, int);
		int GetX();
		int GetY();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		bool getisintro();
		bool GetHit(int bx, int by);
		void GetEraserXY(int x, int y);
		int GetHp();
		void delay(int &);
		void DeleteObject();
		void FA_Lowaddition();
		void FA_Highaddition();
		void Fireseed();
		void Create_addition();
		void FirePollen();
		void Setattacking(bool);
		void SetFirePollen(bool);
		bool isattack();
		int  seedsize();
		vector<int> getseedxy(int);
		int  boomsize();
		vector<int> getboomxy(int);
		bool getisattacking();
		int  pollensize();
		vector<int> getpollenxy(int);
		bool getready();
		void GetKill(bool);
	protected:
		int sx, sy;
		int ex, ey;
		int vx, vy;
		int cx, cy;
		int t,t2,t3,t4;
		bool kill;
		bool isdead;
		bool ready;
		bool final;
		bool fp;
		bool isintro;
		bool firepollen;
		bool falow;
		bool fahigh;
		bool readys;
		bool isplay;
		bool isattacking;
		bool grow;
		bool firing;
		bool fire;
		bool invincible;
		int  attackmode;
		bool grown;
		int  hp;
		int  intro[40] = { 400,400,398,398,400,400,398,398,400,400,398,398,400,400,398,398,400,400,398,398,400,400,398,398,395,390,360,343,290,168,138,140,155,165,188,150,152,255,170,278 };
		int  fa_low[20] = {400,377,368,366,365,371,373,358,259,188,-61,-73,-66,-62,-35,-2,216,266,291,278};
		int  fa_high[19] = {380,366,360,353,352,353,392,324,275,211,-18,-21,-25,-25,29,55,321,376,387};
		int  detseedxy[3][7] = { {30,70,110,190,300,350,150},{75,150,175,200,235,280,375},{55,145,180,225,270,100,350}};
		int attackingmode[3][4] = { {0,1,2,3},{0,2,3,1},{2,0,1,3} };
		bool isinvincible;
		vector<sunflower_seed*> sd;
		vector<boomerang*> brang;
		vector<Pollen*> pollen;
		CAnimation Idle;
		CAnimation Intro;
		CAnimation FA_Low;
		CAnimation FA_High;
		CAnimation FS;
		CAnimation Create;
		CAnimation Final_Intro;
		CAnimation Final_Idle;
		CAnimation FP;
		CAnimation Death;
		CAnimation vine;
		CMovingBitmap lifebar;
		CMovingBitmap lifebar_m;
	};
}
#endif