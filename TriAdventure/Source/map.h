#include "Goomba.h"
#include "elevator.h"
#include "Dick.h"
#include "Rex.h"
#include "bowser.h"
#include "trap_4_1.h"
#include "Sunflower.h"
#ifndef _MAP_H_
#define _MAP_H_
namespace game_framework {
	class map
	{
	public:
		map();
		~map();
		void Inital();
		int  GetX();
		int  GetY();
		void GetEraserXY(int eraserx,int erasery);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetMovingRight(bool flag);
		void SetMovingLeft(bool flag);
		bool judgearea(int x, int* y, int height, bool*);
		bool judgewall(int* x, int y, int id,bool*);
		bool judgeceiling(int x, int y);
		bool judgetrap(int x, int* y,int height);
		bool hitmonster(int bx, int by);
		void MonsterOnMove();
		void MonsterLoadBitmap();
		void MonsterInitial();
		void DeletePreObject();
		bool isMapEnd(int ex, int ey);
		int	 Getcurrentmap();
		bool getifisanimation();
		void SetRestart();
		void playmusic();
		bool getisfinish();
		bool mattack();
		bool judgemoss(int* x,int y,int id);
		void GetmonsterXY();
		vector <int> SendMonsterXY(int);
		int  monsterxysize();
		bool getsunisattacking();
		void Setmap(int);
		void GetisKill(bool);
	protected:
		vector<elevator*> el;
		vector<dick*> dic;
		vector<Rex*> enemy_rex;
		CAnimation* mpanimation = NULL;
		bool kill;
		bool ifisanimation;
		bool monsterattack;
		int monsterx = 0;
		int monstery = 0;
		int  ex, ey;
		bool isMovingRight;
		bool isMovingLeft;
		bool isDead;
		char world[40][12] = { 0 };
		int currentmap = 0;
		int sx, sy;
		bool isfinish;
		int tx31, ty31;
		int tx32, ty32;
		bool istriger;
		Goomba enemy_goomba;
		CAnimation trap_3_1;
		CAnimation trap_3_2;
		vector<trap4_1*> trap41;
		vector<bowser*> boss_bowser;
		vector<Sunflower*> boss_sunflower;
		vector <vector<int>> area;
		vector<vector<int>> wall;
		vector<vector<int>> ceiling;
		vector<vector<int>> trap;
		vector<vector<int>>	moss;
		vector< vector <int>> monsterxy;
		bool isattacking;
	};
}
#endif