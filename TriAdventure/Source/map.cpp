#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "map.h"
namespace game_framework {
	map::map()
	{
		Inital();
	}
	map::~map()
	{
		for (int i = 0; i < (int)dic.size(); i++)
		{
			delete dic[i];
		}
		for (int i = 0; i < (int)el.size(); i++)
		{
			delete el[i];
		}
		for (int i = 0; i < (int)enemy_rex.size(); i++)
		{
			delete enemy_rex[i];
		}
		for (int i = 0; i < (int)boss_bowser.size(); i++)
		{
			delete boss_bowser[i];
		}
		for (int i = 0; i < (int)boss_sunflower.size(); i++)
		{
			delete boss_sunflower[i];
		}
	}
	void map::MonsterInitial()
	{
		if (Getcurrentmap() == 0)
			enemy_goomba.Initalize();
	}
	void map::DeletePreObject()
	{
		for (int i = 0; i < (int)dic.size(); i++)
		{
			delete dic[i];
		}
		dic.clear();

		for (int i = 0; i < (int)boss_bowser.size(); i++)
		{
			delete boss_bowser[i];
		}
		boss_bowser.clear();
		for (int i = 0; i < (int)boss_sunflower.size(); i++)
		{
			delete boss_sunflower[i];
		}
		boss_sunflower.clear();
		for (int i = 0; i < (int)enemy_rex.size(); i++)
		{
			delete enemy_rex[i];
		}
		enemy_rex.clear();
		for (int i = 0; i < (int)el.size(); i++)
		{
			delete el[i];
		}
		el.clear();
	}
	bool map::judgearea(int x, int *y, int height, bool *onFloor)
	{
		if (Getcurrentmap() == 2)
		{
			for (int i = 0; i<int(el.size()); i++)
			{
				if (x + 12 >= el[i]->GetX() && x <= el[i]->GetX2() && abs(*y + height - el[i]->GetY()) <= 15)
				{
					*y = el[i]->GetY() - 25;
					*onFloor = true;
					return true;
				}
			}
		}
		for (int i = 0; i < int(area.size()); i++)
		{
			if (x + 25 - sx >= area[i][0] && x - sx <= area[i][2] && abs(*y + height - area[i][1]) <= 10)
			{
				*y = area[i][1] - 35;
				*onFloor = true;
				return true;
			}
		}
		*onFloor = false;
		return false;
	}
	bool map::judgemoss(int *x, int y, int id)
	{
		for (int i = 0; i < int(moss.size()); i++)
		{
			if (id == 1)
			{
				if (abs(*x - sx - moss[i][0]) <= 5)
				{
					for (int j = moss[i][1]; j <= moss[i][3]; j++)
					{
						for (int k = y; k <= y + 25; k++)
						{
							if (k == j)
							{
								return true;
							}
						}
					}
				}
			}
			else
			{
				if (abs(*x + 25 - sx - moss[i][0]) <= 5)	//140
				{
					for (int j = moss[i][1]; j <= moss[i][3]; j++)
					{
						for (int k = y; k <= y + 25; k++)
						{
							if (k == j)
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
	int map::monsterxysize()
	{
		return monsterxy.size();
	}
	bool map::getsunisattacking()
	{
		return isattacking;
	}
	void map::Setmap(int i)
	{
		currentmap = i;
	}
	void map::GetisKill(bool k)
	{
		kill = k;
	}
	void map::GetmonsterXY()
	{
		monsterxy.clear();
		for (int i = 0; i < int(dic.size()); i++)
		{
			for (int j = 0; j < dic[i]->vdbsize(); j++)
			{
				if (monsterxy.empty()) 
				{
					monsterxy.push_back(dic[i]->getdickbulletXY(j));
				}
				else 
				{
					monsterxy.push_back(dic[i]->getdickbulletXY(j));
				}
			}
		}
		for (int i = 0; i < int(boss_bowser.size()); i++)
		{
			for (int j = 0; j < boss_bowser[i]->bfbSize(); j++)
			{
				if (monsterxy.empty())
				{
					monsterxy.push_back(boss_bowser[i]->getbfbXY(j));
				}
				else
				{
					monsterxy.push_back(boss_bowser[i]->getbfbXY(j));
				}
			}
		}
		for (int i = 0; i < int(boss_bowser.size()); i++)
		{
			for (int j = 0; j < boss_bowser[i]->irbSize(); j++)
			{
				if (monsterxy.empty())
				{
					monsterxy.push_back(boss_bowser[i]->getirbXY(j));
				}
				else
				{
					monsterxy.push_back(boss_bowser[i]->getirbXY(j));
				}
			}
		}
		for (int i = 0; i < int(boss_sunflower.size()); i++)
		{
			for (int j = 0; j < boss_sunflower[i]->seedsize(); j++)
			{
				if (monsterxy.empty())
				{
					monsterxy.push_back(boss_sunflower[i]->getseedxy(j));
				}
				else
				{
					monsterxy.push_back(boss_sunflower[i]->getseedxy(j));
				}
			}
		}
		for (int i = 0; i < int(boss_sunflower.size()); i++)
		{
			for (int j = 0; j < boss_sunflower[i]->boomsize(); j++)
			{
				if (monsterxy.empty())
				{
					monsterxy.push_back(boss_sunflower[i]->getboomxy(j));
				}
				else
				{
					monsterxy.push_back(boss_sunflower[i]->getboomxy(j));
				}
			}
		}
		for (int i = 0; i < int(boss_sunflower.size()); i++)
		{
			for (int j = 0; j < boss_sunflower[i]->pollensize(); j++)
			{
				if (monsterxy.empty())
				{
					monsterxy.push_back(boss_sunflower[i]->getpollenxy(j));
				}
				else
				{
					monsterxy.push_back(boss_sunflower[i]->getpollenxy(j));
				}
			}
		}
	}
	vector<int> map::SendMonsterXY(int i)
	{
		return monsterxy[i];
	}
	bool map::judgewall(int *x, int y, int id,bool *climbing)
	{
		for (int i = 0; i < int(wall.size()); i++)
		{
			if (id == 1)
			{
				if (abs(*x - sx - wall[i][0]) <= 5)
				{
					for (int j = wall[i][1]; j <= wall[i][3]; j++)
					{
						for (int k = y; k <= y + 25; k++)
						{
							if (k == j)
							{
								if (wall[i][4] == 1)
								{
									*climbing = true;
								}
								else {
									*climbing = false;
								}
							return true;
							}
						}
					}
				}
			}
			else
			{
				if (abs(*x + 25 - sx - wall[i][0]) <= 5 )	//140
				{
					for (int j = wall[i][1]; j <= wall[i][3]; j++)
					{
						for (int k = y; k <= y + 25; k++)
						{
							if (k == j)
							{
								if (wall[i][4] == 1)
								{
									*climbing = true;
								}
								else
								{
									*climbing = false;
								}
							return true;
							}
						}
					}					
				}
			}
		}
		*climbing = false;
		return false;
	}
	bool map::judgeceiling(int x, int y)
	{
		for (int i = 0; i<int(ceiling.size()); i++)
		{
			if (abs(ceiling[i][1] - y) < 8 && x - sx + 12 > ceiling[i][0] && x - sx + 12 < ceiling[i][2])
				return true;
		}
		return false;
	}
	bool map::judgetrap(int x, int *y,int height)
	{
		for (int i = 0; i < int(trap.size()); i++)
		{
			if (x + 25 - sx >= trap[i][0] && x - sx <= trap[i][2] && abs(*y + height - trap[i][1]) <= 10)
			{
				return true;
			}
			if (abs(trap[i][1] - *y) < 5 && x-sx > trap[i][0] && x-sx < trap[i][2])	
			{
				return true;
			}
		}
		return false;
	}
	void map::LoadBitmap()
	{
		if (mpanimation != NULL) {
			delete mpanimation;
		}
		mpanimation = new CAnimation;
		if (currentmap == 0)
			mpanimation->AddBitmap(IDB_world_new_2);
		if (currentmap == 1)
			mpanimation->AddBitmap(IDB_world2_1);
		if (currentmap == 2)
			mpanimation->AddBitmap(IDB_world2_2);
		if (currentmap == 3)
			mpanimation->AddBitmap(IDB_world2_3);
		if (currentmap == 4)
			mpanimation->AddBitmap(IDB_world2_4);
		if (currentmap == 5)
			mpanimation->AddBitmap(IDB_world_boss1);
		if (currentmap == 6)
		{
			mpanimation->AddBitmap(IDB_world3_1);
			trap_3_1.AddBitmap(IDB_trap_3_1);
			trap_3_2.AddBitmap(IDB_trap_3_2);
		}
		if (currentmap == 7)
			mpanimation->AddBitmap(IDB_world_41);
		if(currentmap==8)
			mpanimation->AddBitmap(IDB_world42);
		if (currentmap == 9)
			mpanimation->AddBitmap(IDB_world43);
		if (currentmap == 10)
			mpanimation->AddBitmap(IDB_world_boss2);
		if (currentmap == 11)
			mpanimation->AddBitmap(ending);
	}
	void map::MonsterLoadBitmap()
	{
		if (Getcurrentmap() == 0)
			enemy_goomba.Initalize();
	}
	void map::Inital()
	{
		int x[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
		int y[12] = { 0,0,0,0,0,0,0,0,0,0,0,0};
		ifisanimation = false;
		isfinish = false;
		istriger = false;
		isDead = false;
		isattacking = false;
		kill = false;
		for (int i = 0; i < sizeof(x); i++)
		{
			if (Getcurrentmap() == i)
			{
				sx = x[i];
				sy = y[i];
			}
		}
		playmusic();
		isMovingRight = isMovingLeft= monsterattack = false;
		vector<int> w;
		vector<int> ar;
		vector<int> ce;
		vector<int>	tr;
		vector<int> mo;
		area.clear();
		wall.clear();
		ceiling.clear();
		trap.clear();
		moss.clear();
		DeletePreObject();
		if (currentmap == 0)
		{
			ar.push_back(0);
			ar.push_back(210);
			ar.push_back(892);
			ar.push_back(210);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1106);
			ar.push_back(181);
			ar.push_back(1322);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1346);
			ar.push_back(214);
			ar.push_back(1399);
			ar.push_back(214);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1400);
			ar.push_back(121);
			ar.push_back(1425);
			ar.push_back(121);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1425);
			ar.push_back(151);
			ar.push_back(1470);
			ar.push_back(151);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1470);
			ar.push_back(121);
			ar.push_back(1507);
			ar.push_back(121);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1650);
			ar.push_back(127);
			ar.push_back(1812);
			ar.push_back(127);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1939);
			ar.push_back(273);
			ar.push_back(1986);
			ar.push_back(273);
			area.push_back(ar);
			ar.clear();
			ar.push_back(1980);
			ar.push_back(326);
			ar.push_back(2057);
			ar.push_back(326);
			area.push_back(ar);
			ar.clear();
			w.push_back(1985);
			w.push_back(277);
			w.push_back(1985);
			w.push_back(471);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1323);
			w.push_back(183);
			w.push_back(1323);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(692);
			tr.push_back(388);
			tr.push_back(717);
			tr.push_back(388);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(718);
			tr.push_back(360);
			tr.push_back(743);
			tr.push_back(360);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(743);
			tr.push_back(414);
			tr.push_back(796);
			tr.push_back(414);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(823);
			tr.push_back(414);
			tr.push_back(848);
			tr.push_back(414);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(849);
			tr.push_back(360);
			tr.push_back(873);
			tr.push_back(360);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(928);
			tr.push_back(442);
			tr.push_back(952);
			tr.push_back(442);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(954);
			tr.push_back(414);
			tr.push_back(979);
			tr.push_back(414);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1032);
			tr.push_back(334);
			tr.push_back(1057);
			tr.push_back(334);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1059);
			tr.push_back(442);
			tr.push_back(1083);
			tr.push_back(442);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1111);
			tr.push_back(442);
			tr.push_back(1136);
			tr.push_back(442);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1137);
			tr.push_back(334);
			tr.push_back(1163);
			tr.push_back(334);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1189);
			tr.push_back(442);
			tr.push_back(1213);
			tr.push_back(442);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1216);
			tr.push_back(414);
			tr.push_back(1240);
			tr.push_back(414);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(1267);
			tr.push_back(360);
			tr.push_back(1293);
			tr.push_back(360);
			trap.push_back(tr);
			tr.clear();
			for (int i = 0; i <= 20; i++)
			{
				w.push_back(i);
				w.push_back(0);
				w.push_back(i);
				w.push_back(480);
				w.push_back(0);
				wall.push_back(w);
				w.clear();
			}
			w.push_back(1293);
			w.push_back(224);
			w.push_back(1293);
			w.push_back(384);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1941);
			w.push_back(287);
			w.push_back(1941);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1268);
			w.push_back(196);
			w.push_back(1268);
			w.push_back(222);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1400);
			w.push_back(123);
			w.push_back(1400);
			w.push_back(226);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(718);
			ce.push_back(224);
			ce.push_back(890);
			ce.push_back(224);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(694);
			ce.push_back(250);
			ce.push_back(718);
			ce.push_back(250);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(1107);
			ce.push_back(196);
			ce.push_back(1267);
			ce.push_back(196);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(1650);
			ce.push_back(142);
			ce.push_back(1813);
			ce.push_back(142);
			ceiling.push_back(ce);
			ce.clear();
		}
		else if (currentmap == 1)
		{
			for (int i = 0; i < (int)enemy_rex.size(); i++)
			{
				delete enemy_rex[i];
			}
			enemy_rex.clear();
			enemy_rex.push_back(new Rex(447, 35));
			enemy_rex.push_back(new Rex(447, 233));
			ce.push_back(0);
			ce.push_back(17);
			ce.push_back(57);
			ce.push_back(17);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(130);
			ce.push_back(17);
			ce.push_back(610);
			ce.push_back(17);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(557);
			ce.push_back(93);
			ce.push_back(610);
			ce.push_back(93);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(0);
			ce.push_back(93);
			ce.push_back(478);
			ce.push_back(93);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(0);
			ce.push_back(190);
			ce.push_back(57);
			ce.push_back(190);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(135);
			ce.push_back(190);
			ce.push_back(610);
			ce.push_back(190);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(0);
			ce.push_back(296);
			ce.push_back(478);
			ce.push_back(296);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(557);
			ce.push_back(296);
			ce.push_back(610);
			ce.push_back(296);
			ceiling.push_back(ce);
			ce.clear();
			ar.push_back(0);
			ar.push_back(79);
			ar.push_back(478);
			ar.push_back(79);
			area.push_back(ar);
			ar.clear();
			ar.push_back(558);
			ar.push_back(79);
			ar.push_back(610);
			ar.push_back(79);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(181);
			ar.push_back(56);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(135);
			ar.push_back(181);
			ar.push_back(610);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(282);
			ar.push_back(478);
			ar.push_back(282);
			area.push_back(ar);
			ar.clear();
			ar.push_back(558);
			ar.push_back(282);
			ar.push_back(610);
			ar.push_back(282);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(383);
			ar.push_back(56);
			ar.push_back(383);
			area.push_back(ar);
			ar.clear();
			ar.push_back(135);
			ar.push_back(383);
			ar.push_back(610);
			ar.push_back(383);
			area.push_back(ar);
			ar.clear();
			w.push_back(610);
			w.push_back(0);
			w.push_back(610);
			w.push_back(480);
			wall.push_back(w);
			w.clear();
			w.push_back(4);
			w.push_back(0);
			w.push_back(4);
			w.push_back(78);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(4);
			w.push_back(182);
			w.push_back(4);
			w.push_back(282);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(4);
			w.push_back(282);
			w.push_back(4);
			w.push_back(382);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(4);
			w.push_back(382);
			w.push_back(4);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
		}
		else if (Getcurrentmap() == 2)
		{
			for (int i = 0; i < (int)el.size(); i++)
			{
				delete el[i];
			}
			el.clear();
			el.push_back(new elevator(458, 435, 458, 31));
			el.push_back(new elevator(280, 435, 280, 240));
			el.push_back(new elevator(280, 229, 280, 31));
			el.push_back(new elevator(103, 435, 103, 301));
			el.push_back(new elevator(103, 301, 103, 165));
			el.push_back(new elevator(103, 165, 103, 31));
			tr.push_back(39);
			tr.push_back(46);
			tr.push_back(545);
			tr.push_back(46);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(39);
			tr.push_back(427);
			tr.push_back(545);
			tr.push_back(427);
			trap.push_back(tr);
			tr.clear();
			ar.push_back(583);
			ar.push_back(181);
			ar.push_back(640);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			ar.push_back(0);
			ar.push_back(181);
			ar.push_back(55);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			w.push_back(635);
			w.push_back(0);
			w.push_back(635);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(620);
			w.push_back(47);
			w.push_back(620);
			w.push_back(97);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(27);
			ce.push_back(23);
			ce.push_back(582);
			ce.push_back(23);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(582);
			ce.push_back(46);
			ce.push_back(608);
			ce.push_back(46);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(609);
			ce.push_back(98);
			ce.push_back(640);
			ce.push_back(98);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(0);
			ce.push_back(121);
			ce.push_back(27);
			ce.push_back(121);
			ceiling.push_back(ce);
			ce.clear();
		}
		else if (currentmap == 3)
		{
			for (int i = 0; i < (int)dic.size(); i++)
			{
				delete dic[i];
			}
			dic.clear();
			dic.push_back(new dick(18, 352, 0));
			dic.push_back(new dick(18, 251, 0));
			dic.push_back(new dick(625, 352, 1));
			dic.push_back(new dick(625, 251, 1));
			w.push_back(640);
			w.push_back(0);
			w.push_back(640);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(31);
			tr.push_back(429);
			tr.push_back(611);
			tr.push_back(429);
			trap.push_back(tr);
			tr.clear();
			ar.push_back(572);
			ar.push_back(185);
			ar.push_back(640);
			ar.push_back(185);
			area.push_back(ar);
			ar.clear();
			ar.push_back(519);
			ar.push_back(286);
			ar.push_back(625);
			ar.push_back(286);
			area.push_back(ar);
			ar.clear();
			ar.push_back(440);
			ar.push_back(386);
			ar.push_back(625);
			ar.push_back(386);
			area.push_back(ar);
			ar.clear();
			ar.push_back(249);
			ar.push_back(297);
			ar.push_back(381);
			ar.push_back(297);
			area.push_back(ar);
			ar.clear();
			ar.clear();
			ar.push_back(0);
			ar.push_back(185);
			ar.push_back(71);
			ar.push_back(185);
			area.push_back(ar);
			ar.clear();
			ar.push_back(18);
			ar.push_back(286);
			ar.push_back(123);
			ar.push_back(286);
			area.push_back(ar);
			ar.clear();
			ar.push_back(18);
			ar.push_back(386);
			ar.push_back(202);
			ar.push_back(386);
			area.push_back(ar);
			ar.clear();
			w.push_back(72);
			w.push_back(226);
			w.push_back(72);
			w.push_back(377);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(573);
			w.push_back(226);
			w.push_back(573);
			w.push_back(377);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(600);
			ce.push_back(111);
			ce.push_back(639);
			ce.push_back(111);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(573);
			ce.push_back(226);
			ce.push_back(624);
			ce.push_back(226);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(521);
			ce.push_back(326);
			ce.push_back(624);
			ce.push_back(326);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(44);
			ce.push_back(72);
			ce.push_back(600);
			ce.push_back(72);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(0);
			ce.push_back(124);
			ce.push_back(44);
			ce.push_back(124);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(18);
			ce.push_back(226);
			ce.push_back(71);
			ce.push_back(226);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(19);
			ce.push_back(326);
			ce.push_back(123);
			ce.push_back(326);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(249);
			ce.push_back(314);
			ce.push_back(381);
			ce.push_back(314);
			ceiling.push_back(ce);
			ce.clear();
		}
		else if (currentmap == 4)
		{
			ar.push_back(586);
			ar.push_back(181);
			ar.push_back(640);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			w.push_back(640);
			w.push_back(123);
			w.push_back(640);
			w.push_back(172);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(612);
			ce.push_back(121);
			ce.push_back(640);
			ce.push_back(121);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(610);
			w.push_back(23);
			w.push_back(610);
			w.push_back(122);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(610);
			w.push_back(199);
			w.push_back(610);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(36);
			tr.push_back(45);
			tr.push_back(598);
			tr.push_back(45);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(36);
			tr.push_back(354);
			tr.push_back(163);
			tr.push_back(354);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(470);
			tr.push_back(354);
			tr.push_back(598);
			tr.push_back(354);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(188);
			tr.push_back(376);
			tr.push_back(241);
			tr.push_back(376);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(394);
			tr.push_back(376);
			tr.push_back(444);
			tr.push_back(376);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(259);
			tr.push_back(403);
			tr.push_back(273);
			tr.push_back(403);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(364);
			tr.push_back(403);
			tr.push_back(374);
			tr.push_back(403);
			trap.push_back(tr);
			tr.clear();
			w.push_back(279);
			w.push_back(426);
			w.push_back(279);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(356);
			w.push_back(426);
			w.push_back(356);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
		}
		else if (currentmap == 5)
		{
			for (int i = 0; i < (int)boss_bowser.size(); i++)
			{

				delete boss_bowser[i];
			}
			boss_bowser.clear();
			boss_bowser.push_back(new bowser(500, 0));
			ar.push_back(0);
			ar.push_back(408);
			ar.push_back(640);
			ar.push_back(408);
			area.push_back(ar);
			ar.clear();
			w.push_back(635);
			w.push_back(0);
			w.push_back(635);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(5);
			w.push_back(0);
			w.push_back(5);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
		}
		else if(currentmap==6)				
		{
			ar.push_back(0);
			ar.push_back(442);
			ar.push_back(150);
			ar.push_back(442);
			area.push_back(ar);
			ar.clear();
			w.push_back(5);
			w.push_back(0);
			w.push_back(5);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(150);
			w.push_back(418);
			w.push_back(150);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(150);
			ar.push_back(417);
			ar.push_back(176);
			ar.push_back(417);
			area.push_back(ar);
			ar.clear();
			ar.push_back(176);
			ar.push_back(396);
			ar.push_back(201);
			ar.push_back(396);
			area.push_back(ar);
			ar.clear();
			w.push_back(171);
			w.push_back(392);
			w.push_back(171);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(355);
			ar.push_back(392);
			ar.push_back(379);
			ar.push_back(392);
			area.push_back(ar);
			ar.clear();
			tr.push_back(202);
			tr.push_back(410);
			tr.push_back(353);
			tr.push_back(410);
			trap.push_back(tr);
			tr.clear();
			w.push_back(379);
			w.push_back(317);
			w.push_back(379);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(354);
			w.push_back(392);
			w.push_back(354);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(176);
			w.push_back(392);
			w.push_back(176);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(380);
			ar.push_back(316);
			ar.push_back(405);
			ar.push_back(316);
			area.push_back(ar);
			ar.clear();
			w.push_back(354);
			w.push_back(75);
			w.push_back(354);
			w.push_back(253);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(405);
			w.push_back(227);
			w.push_back(405);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(328);
			w.push_back(150);
			w.push_back(328);
			w.push_back(245);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(329);
			ce.push_back(245);
			ce.push_back(354);
			ce.push_back(245);
			ceiling.push_back(ce);
			ce.clear();
			tr.push_back(356);
			tr.push_back(80);
			tr.push_back(379);
			tr.push_back(80);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(405);
			tr.push_back(202);
			tr.push_back(456);
			tr.push_back(202);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(465);
			tr.push_back(125);
			tr.push_back(470);
			tr.push_back(125);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(465);
			tr.push_back(73);
			tr.push_back(470);
			tr.push_back(73);
			trap.push_back(tr);
			tr.clear();
			ar.push_back(405);
			ar.push_back(239);
			ar.push_back(558);
			ar.push_back(239);
			area.push_back(ar);
			ar.clear();
			ar.push_back(202);
			ar.push_back(443);
			ar.push_back(353);
			ar.push_back(443);
			area.push_back(ar);
			ar.clear();
			tr.push_back(380);
			tr.push_back(50);
			tr.push_back(455);
			tr.push_back(50);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(482);
			tr.push_back(50);
			tr.push_back(557);
			tr.push_back(50);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(482);
			tr.push_back(202);
			tr.push_back(526);
			tr.push_back(202);
			trap.push_back(tr);
			tr.clear();
			w.push_back(533);
			w.push_back(252);
			w.push_back(533);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(558);
			w.push_back(393);
			w.push_back(558);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(584);
			w.push_back(419);
			w.push_back(584);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(609);
			w.push_back(369);
			w.push_back(609);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(634);
			w.push_back(369);
			w.push_back(634);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(533);
			ar.push_back(392);
			ar.push_back(558);
			ar.push_back(392);
			area.push_back(ar);
			ar.clear();
			ar.push_back(559);
			ar.push_back(418);
			ar.push_back(583);
			ar.push_back(481);
			area.push_back(ar);
			ar.clear();
			ar.push_back(584);
			ar.push_back(444);
			ar.push_back(609);
			ar.push_back(444);
			area.push_back(ar);
			ar.clear();
			ar.push_back(609);
			ar.push_back(368);
			ar.push_back(635);
			ar.push_back(368);
			area.push_back(ar);
			ar.clear();
			ar.push_back(635);
			ar.push_back(442);
			ar.push_back(688);
			ar.push_back(442);
			area.push_back(ar);
			ar.clear();
			ar.push_back(688);
			ar.push_back(416);
			ar.push_back(715);
			ar.push_back(416);
			area.push_back(ar);
			ar.clear();
			w.push_back(688);
			w.push_back(418);
			w.push_back(688);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(727);
			tr.push_back(404);
			tr.push_back(853);
			tr.push_back(404);
			trap.push_back(tr);
			tr.clear();
			ar.push_back(866);
			ar.push_back(416);
			ar.push_back(943);
			ar.push_back(416);
			area.push_back(ar);
			ar.clear();
			w.push_back(944);
			w.push_back(417);
			w.push_back(944);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(945);
			ar.push_back(466);
			ar.push_back(1144);
			ar.push_back(466);
			area.push_back(ar);
			ar.clear();
			w.push_back(1145);
			w.push_back(365);
			w.push_back(1145);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1145);
			ar.push_back(364);
			ar.push_back(1195);
			ar.push_back(364);
			area.push_back(ar);
			ar.clear();
			w.push_back(1196);
			w.push_back(289);
			w.push_back(1196);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1196);
			ar.push_back(289);
			ar.push_back(1220);
			ar.push_back(289);
			area.push_back(ar);
			ar.clear();
			w.push_back(1220);
			w.push_back(265);
			w.push_back(1220);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1221);
			ar.push_back(263);
			ar.push_back(1245);
			ar.push_back(263);
			area.push_back(ar);
			ar.clear();
			w.push_back(1245);
			w.push_back(239);
			w.push_back(1245);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1246);
			ar.push_back(238);
			ar.push_back(1304);
			ar.push_back(238);
			area.push_back(ar);
			ar.clear();
			w.push_back(1305);
			w.push_back(239);
			w.push_back(1305);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1306);
			ar.push_back(290);
			ar.push_back(1338);
			ar.push_back(290);
			area.push_back(ar);
			ar.clear();
			w.push_back(1339);
			w.push_back(291);
			w.push_back(1339);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1340);
			ar.push_back(395);
			ar.push_back(1373);
			ar.push_back(395);
			area.push_back(ar);
			ar.clear();
			w.push_back(1374);
			w.push_back(396);
			w.push_back(1374);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1375);
			ar.push_back(471);
			ar.push_back(1441);
			ar.push_back(471);
			area.push_back(ar);
			ar.clear();
			w.push_back(1442);
			w.push_back(446);
			w.push_back(1442);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1443);
			ar.push_back(445);
			ar.push_back(1476);
			ar.push_back(445);
			area.push_back(ar);
			ar.clear();
			w.push_back(1344);
			w.push_back(394);
			w.push_back(1344);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1376);
			w.push_back(394);
			w.push_back(1344);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1476);
			ar.push_back(395);
			ar.push_back(1731);
			ar.push_back(395);
			area.push_back(ar);
			ar.clear();
			tr.push_back(1511);
			tr.push_back(435);
			tr.push_back(1852);
			tr.push_back(435);
			trap.push_back(tr);
			tr.clear();
			w.push_back(1475);
			w.push_back(395);
			w.push_back(1475);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1509);
			w.push_back(395);
			w.push_back(1509);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1510);
			ar.push_back(470);
			ar.push_back(1853);
			ar.push_back(470);
			area.push_back(ar);
			ar.clear();
			w.push_back(1852);
			w.push_back(315);
			w.push_back(1852);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(1853);
			tr.push_back(296);
			tr.push_back(1887);
			tr.push_back(296);
			trap.push_back(tr);
			tr.clear();
			w.push_back(1852);
			w.push_back(315);
			w.push_back(1852);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1852);
			w.push_back(71);
			w.push_back(1852);
			w.push_back(199);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(1819);
			ce.push_back(70);
			ce.push_back(1853);
			ce.push_back(70);
			ceiling.push_back(ce);
			ce.clear();
			ar.push_back(1887);
			ar.push_back(472);
			ar.push_back(2657);
			ar.push_back(472);
			area.push_back(ar);
			ar.clear();
			w.push_back(1887);
			w.push_back(329);
			w.push_back(1887);
			w.push_back(460);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(1961);
			w.push_back(197);
			w.push_back(1961);
			w.push_back(327);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(1985);
			w.push_back(197);
			w.push_back(1985);
			w.push_back(327);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(1965);
			tr.push_back(184);
			tr.push_back(1979);
			tr.push_back(184);
			trap.push_back(tr);
			tr.clear();
			w.push_back(1887);
			w.push_back(49);
			w.push_back(1887);
			w.push_back(199);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			ce.push_back(1887);
			ce.push_back(41);
			ce.push_back(1906);
			ce.push_back(41);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(1907);
			w.push_back(16);
			w.push_back(1907);
			w.push_back(41);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(1907);
			ce.push_back(16);
			ce.push_back(1931);
			ce.push_back(16);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(1907);
			w.push_back(0);
			w.push_back(1907);
			w.push_back(16);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(1957);
			w.push_back(106);
			w.push_back(1957);
			w.push_back(120);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(1957);
			ar.push_back(105);
			ar.push_back(2104);
			ar.push_back(105);
			area.push_back(ar);
			ar.clear();
			w.push_back(2104);
			w.push_back(105);
			w.push_back(2104);
			w.push_back(169);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(2105);
			ar.push_back(130);
			ar.push_back(2130);
			ar.push_back(130);
			area.push_back(ar);
			ar.clear();
			w.push_back(2131);
			w.push_back(130);
			w.push_back(2131);
			w.push_back(169);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(2105);
			ar.push_back(157);
			ar.push_back(2280);
			ar.push_back(157);
			area.push_back(ar);
			ar.clear();
			w.push_back(2281);
			w.push_back(157);
			w.push_back(2281);
			w.push_back(274);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(2332);
			w.push_back(199);
			w.push_back(2332);
			w.push_back(265);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			ar.push_back(2332);
			ar.push_back(199);
			ar.push_back(2381);
			ar.push_back(199);
			area.push_back(ar);
			ar.clear();
			ce.push_back(2328);
			ce.push_back(265);
			ce.push_back(2356);
			ce.push_back(265);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2356);
			w.push_back(265);
			w.push_back(2356);
			w.push_back(316);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2350);
			ce.push_back(317);
			ce.push_back(2381);
			ce.push_back(317);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(0);
			ce.push_back(0);
			ce.push_back(3400);
			ce.push_back(0);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(1958);
			ce.push_back(325);
			ce.push_back(1987);
			ce.push_back(325);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2255);
			w.push_back(197);
			w.push_back(2255);
			w.push_back(275);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2252);
			ce.push_back(274);
			ce.push_back(2282);
			ce.push_back(274);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2382);
			w.push_back(199);
			w.push_back(2382);
			w.push_back(316);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			ar.push_back(2431);
			ar.push_back(156);
			ar.push_back(2455);
			ar.push_back(156);
			area.push_back(ar);
			ar.clear();
			w.push_back(2430);
			w.push_back(157);
			w.push_back(2430);
			w.push_back(223);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(2456);
			w.push_back(157);
			w.push_back(2456);
			w.push_back(223);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(2656);
			w.push_back(223);
			w.push_back(2656);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2556);
			ce.push_back(223);
			ce.push_back(2655);
			ce.push_back(223);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2555);
			w.push_back(223);
			w.push_back(2555);
			w.push_back(249);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2506);
			ce.push_back(248);
			ce.push_back(2555);
			ce.push_back(248);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2506);
			w.push_back(248);
			w.push_back(2506);
			w.push_back(301);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2479);
			ce.push_back(301);
			ce.push_back(2509);
			ce.push_back(301);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2481);
			w.push_back(209);
			w.push_back(2506);
			w.push_back(300);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			ar.push_back(2481);
			ar.push_back(209);
			ar.push_back(2556);
			ar.push_back(209);
			area.push_back(ar);
			ar.clear();
			w.push_back(2556);
			w.push_back(182);
			w.push_back(2556);
			w.push_back(218);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(2557);
			ar.push_back(181);
			ar.push_back(2705);
			ar.push_back(181);
			area.push_back(ar);
			ar.clear();
			w.push_back(2706);
			w.push_back(182);
			w.push_back(2706);
			w.push_back(218);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(2707);
			ar.push_back(208);
			ar.push_back(2791);
			ar.push_back(208);
			area.push_back(ar);
			ar.clear();
			w.push_back(2792);
			w.push_back(208);
			w.push_back(2792);
			w.push_back(221);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2762);
			ce.push_back(222);
			ce.push_back(2794);
			ce.push_back(222);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2763);
			w.push_back(222);
			w.push_back(2763);
			w.push_back(247);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2734);
			ce.push_back(247);
			ce.push_back(2763);
			ce.push_back(247);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2734);
			w.push_back(247);
			w.push_back(2734);
			w.push_back(272);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2705);
			ce.push_back(272);
			ce.push_back(2734);
			ce.push_back(272);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2705);
			w.push_back(272);
			w.push_back(2705);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(2706);
			ar.push_back(464);
			ar.push_back(2791);
			ar.push_back(464);
			area.push_back(ar);
			ar.clear();
			w.push_back(2792);
			w.push_back(412);
			w.push_back(2792);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(2792);
			ar.push_back(412);
			ar.push_back(3250);
			ar.push_back(412);
			area.push_back(ar);
			ar.clear();
			w.push_back(3251);
			w.push_back(412);
			w.push_back(3251);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(3252);
			ar.push_back(464);
			ar.push_back(3337);
			ar.push_back(464);
			area.push_back(ar);
			ar.clear();
			w.push_back(3338);
			w.push_back(361);
			w.push_back(3338);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(3339);
			ar.push_back(360);
			ar.push_back(3400);
			ar.push_back(360);
			area.push_back(ar);
			ar.clear();
			ce.push_back(3361);
			ce.push_back(276);
			ce.push_back(3400);
			ce.push_back(276);
			ceiling.push_back(ce);
			ce.clear();
			tr.push_back(3290);
			tr.push_back(196);
			tr.push_back(3297);
			tr.push_back(196);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(3345);
			tr.push_back(196);
			tr.push_back(3357);
			tr.push_back(196);
			trap.push_back(tr);
			tr.clear();
			w.push_back(3364);
			w.push_back(204);
			w.push_back(3364);
			w.push_back(276);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(3279);
			w.push_back(204);
			w.push_back(3279);
			w.push_back(297);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(3250);
			w.push_back(170);
			w.push_back(3250);
			w.push_back(297);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(3246);
			ce.push_back(298);
			ce.push_back(3283);
			ce.push_back(298);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(3219);
			ce.push_back(170);
			ce.push_back(3250);
			ce.push_back(170);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(3221);
			w.push_back(94);
			w.push_back(3221);
			w.push_back(170);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(2312);
			ce.push_back(125);
			ce.push_back(2508);
			ce.push_back(125);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(2311);
			w.push_back(111);
			w.push_back(2311);
			w.push_back(125);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(2508);
			w.push_back(111);
			w.push_back(2508);
			w.push_back(125);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			tr.push_back(2312);
			tr.push_back(74);
			tr.push_back(2508);
			tr.push_back(74);
			trap.push_back(tr);
			tr.clear();
		}
		else if (currentmap == 7)
		{
			ar.push_back(0);
			ar.push_back(467);
			ar.push_back(418);
			ar.push_back(467);
			area.push_back(ar);
			ar.clear();
			w.push_back(0);
			w.push_back(0);
			w.push_back(0);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(0);
			ce.push_back(305);
			ce.push_back(239);
			ce.push_back(305);
			ceiling.push_back(ce);
			ce.clear();
			ar.push_back(131);
			ar.push_back(380);
			ar.push_back(159);
			ar.push_back(380);
			area.push_back(ar);
			ar.clear();
			w.push_back(131);
			w.push_back(380);
			w.push_back(131);
			w.push_back(400);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(159);
			w.push_back(380);
			w.push_back(159);
			w.push_back(400);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(129);
			ce.push_back(400);
			ce.push_back(162);
			ce.push_back(400);
			ceiling.push_back(ce);
			ce.clear();
			ar.push_back(209);
			ar.push_back(440);
			ar.push_back(236);
			ar.push_back(440);
			area.push_back(ar);
			ar.clear();
			w.push_back(208);
			w.push_back(440);
			w.push_back(208);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(236);
			w.push_back(440);
			w.push_back(236);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(261);
			w.push_back(384);
			w.push_back(261);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(236);
			w.push_back(278);
			w.push_back(236);
			w.push_back(304);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(236);
			ce.push_back(278);
			ce.push_back(314);
			ce.push_back(278);
			ceiling.push_back(ce);
			ce.clear();
			tr.push_back(272);
			tr.push_back(358);
			tr.push_back(278);
			tr.push_back(358);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(324);
			tr.push_back(358);
			tr.push_back(330);
			tr.push_back(358);
			trap.push_back(tr);
			tr.clear();
			w.push_back(340);
			w.push_back(388);
			w.push_back(340);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(314);
			w.push_back(253);
			w.push_back(314);
			w.push_back(278);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(314);
			ce.push_back(252);
			ce.push_back(548);
			ce.push_back(252);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(575);
			w.push_back(300);
			w.push_back(575);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(548);
			w.push_back(252);
			w.push_back(548);
			w.push_back(300);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(548);
			ce.push_back(300);
			ce.push_back(575);
			ce.push_back(300);
			ceiling.push_back(ce);
			ce.clear();
		}
		else if (currentmap == 8)
		{
			for (int i = 0; i < (int)trap41.size(); i++)
			{
				delete trap41[i];
				trap41.erase(trap41.begin());
			}
			trap41.clear();
			trap41.push_back(new trap4_1(537,230,0));
			trap41.push_back(new trap4_1(78,480,1));
			ar.push_back(411);
			ar.push_back(267);
			ar.push_back(563);
			ar.push_back(267);
			area.push_back(ar);
			ar.clear();
			w.push_back(410);
			w.push_back(0);
			w.push_back(410);
			w.push_back(268);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(588);
			w.push_back(0);
			w.push_back(588);
			w.push_back(205);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(586);
			ce.push_back(205);
			ce.push_back(614);
			ce.push_back(205);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(615);
			w.push_back(205);
			w.push_back(615);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(256);
			ar.push_back(372);
			ar.push_back(614);
			ar.push_back(372);
			area.push_back(ar);
			ar.clear();
			w.push_back(563);
			w.push_back(267);
			w.push_back(563);
			w.push_back(309);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(359);
			ce.push_back(308);
			ce.push_back(563);
			ce.push_back(308);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(358);
			w.push_back(283);
			w.push_back(358);
			w.push_back(309);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(334);
			ce.push_back(283);
			ce.push_back(358);
			ce.push_back(283);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(334);
			w.push_back(102);
			w.push_back(334);
			w.push_back(283);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(334);
			w.push_back(23);
			w.push_back(334);
			w.push_back(102);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(255);
			w.push_back(76);
			w.push_back(334);
			w.push_back(361);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			mo.push_back(309);
			mo.push_back(266);
			mo.push_back(309);
			mo.push_back(274);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(281);
			mo.push_back(135);
			mo.push_back(281);
			mo.push_back(198);
			moss.push_back(mo);
			mo.clear();
			ar.push_back(218);
			ar.push_back(84);
			ar.push_back(246);
			ar.push_back(84);
			area.push_back(ar);
			ar.clear();
			tr.push_back(258);
			tr.push_back(130);
			tr.push_back(281);
			tr.push_back(130);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(258);
			tr.push_back(202);
			tr.push_back(281);
			tr.push_back(202);
			trap.push_back(tr);
			tr.clear();
			ce.push_back(78);
			ce.push_back(23);
			ce.push_back(335);
			ce.push_back(23);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(78);
			w.push_back(23);
			w.push_back(78);
			w.push_back(179);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			tr.push_back(78);
			tr.push_back(161);
			tr.push_back(114);
			tr.push_back(161);
			trap.push_back(tr);
			tr.clear();
			tr.push_back(167);
			tr.push_back(161);
			tr.push_back(205);
			tr.push_back(161);
			trap.push_back(tr);
			tr.clear();
			w.push_back(206);
			w.push_back(76);
			w.push_back(206);
			w.push_back(179);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(115);
			w.push_back(182);
			w.push_back(115);
			w.push_back(230);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(166);
			w.push_back(182);
			w.push_back(166);
			w.push_back(230);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			mo.push_back(182);
			mo.push_back(233);
			mo.push_back(182);
			mo.push_back(255);
			moss.push_back(mo);
			mo.clear();
			tr.push_back(182);
			tr.push_back(255);
			tr.push_back(205);
			tr.push_back(255);
			trap.push_back(tr);
			tr.clear();
			w.push_back(206);
			w.push_back(255);
			w.push_back(206);
			w.push_back(480);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			ar.push_back(112);
			ar.push_back(340);
			ar.push_back(172);
			ar.push_back(340);
			area.push_back(ar);
			ar.clear();
			w.push_back(78);
			w.push_back(255);
			w.push_back(78);
			w.push_back(480);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			tr.push_back(79);
			tr.push_back(255);
			tr.push_back(103);
			tr.push_back(255);
			trap.push_back(tr);
			tr.clear();
			mo.push_back(103);
			mo.push_back(233);
			mo.push_back(103);
			mo.push_back(255);
			moss.push_back(mo);
			mo.clear();
			ce.push_back(75);
			ce.push_back(231);
			ce.push_back(117);
			ce.push_back(231);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(165);
			ce.push_back(231);
			ce.push_back(208);
			ce.push_back(231);
			ceiling.push_back(ce);
			ce.clear();
			mo.push_back(170);
			mo.push_back(361);
			mo.push_back(170);
			mo.push_back(480);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(115);
			mo.push_back(361);
			mo.push_back(115);
			mo.push_back(480);
			moss.push_back(mo);
			mo.clear();
		}
		else if (currentmap == 9)
		{
			ce.push_back(0);
			ce.push_back(0);
			ce.push_back(640);
			ce.push_back(0);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(207);
			w.push_back(0);
			w.push_back(207);
			w.push_back(73);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			mo.push_back(171);
			mo.push_back(0);
			mo.push_back(171);
			mo.push_back(38);
			moss.push_back(mo);
			mo.clear();
			w.push_back(154);
			w.push_back(48);
			w.push_back(154);
			w.push_back(99);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			mo.push_back(152);
			mo.push_back(102);
			mo.push_back(152);
			mo.push_back(123);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(131);
			mo.push_back(102);
			mo.push_back(131);
			mo.push_back(123);
			moss.push_back(mo);
			mo.clear();
			tr.push_back(130);
			tr.push_back(123);
			tr.push_back(152);
			tr.push_back(123);
			trap.push_back(tr);
			tr.clear();
			w.push_back(205);
			w.push_back(120);
			w.push_back(205);
			w.push_back(227);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			mo.push_back(215);
			mo.push_back(76);
			mo.push_back(215);
			mo.push_back(119);
			moss.push_back(mo);
			mo.clear();
			w.push_back(155);
			w.push_back(218);
			w.push_back(155);
			w.push_back(268);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(130);
			w.push_back(218);
			w.push_back(130);
			w.push_back(268);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			mo.push_back(149);
			mo.push_back(192);
			mo.push_back(149);
			mo.push_back(217);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(135);
			mo.push_back(192);
			mo.push_back(135);
			mo.push_back(217);
			moss.push_back(mo);
			mo.clear();
			tr.push_back(135);
			tr.push_back(192);
			tr.push_back(142);
			tr.push_back(192);
			trap.push_back(tr);
			tr.clear();
			w.push_back(129);
			w.push_back(0);
			w.push_back(129);
			w.push_back(100);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(77);
			w.push_back(0);
			w.push_back(77);
			w.push_back(72);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(77);
			w.push_back(72);
			w.push_back(77);
			w.push_back(255);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(131);
			ce.push_back(269);
			ce.push_back(158);
			ce.push_back(269);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(203);
			ce.push_back(227);
			ce.push_back(232);
			ce.push_back(227);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(213);
			w.push_back(325);
			w.push_back(213);
			w.push_back(377);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(237);
			w.push_back(325);
			w.push_back(237);
			w.push_back(377);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			ce.push_back(210);
			ce.push_back(377);
			ce.push_back(240);
			ce.push_back(377);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(283);
			w.push_back(253);
			w.push_back(283);
			w.push_back(304);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(283);
			w.push_back(172);
			w.push_back(283);
			w.push_back(253);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(283);
			w.push_back(134);
			w.push_back(283);
			w.push_back(172);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(231);
			w.push_back(126);
			w.push_back(231);
			w.push_back(200);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(231);
			w.push_back(200);
			w.push_back(231);
			w.push_back(227);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(283);
			w.push_back(304);
			w.push_back(283);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			mo.push_back(220);
			mo.push_back(302);
			mo.push_back(220);
			mo.push_back(324);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(230);
			mo.push_back(302);
			mo.push_back(230);
			mo.push_back(324);
			moss.push_back(mo);
			mo.clear();
			tr.push_back(220);
			tr.push_back(302);
			tr.push_back(230);
			tr.push_back(302);
			trap.push_back(tr);
			tr.clear();
			ar.push_back(77);
			ar.push_back(468);
			ar.push_back(282);
			ar.push_back(468);
			area.push_back(ar);
			ar.clear();
			w.push_back(77);
			w.push_back(355);
			w.push_back(77);
			w.push_back(404);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(77);
			w.push_back(404);
			w.push_back(77);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(75);
			ce.push_back(355);
			ce.push_back(106);
			ce.push_back(355);
			ceiling.push_back(ce);
			ce.clear();
			mo.push_back(95);
			mo.push_back(304);
			mo.push_back(95);
			mo.push_back(328);
			moss.push_back(mo);
			mo.clear();
			tr.push_back(77);
			tr.push_back(304);
			tr.push_back(95);
			tr.push_back(304);
			trap.push_back(tr);
			tr.clear();
			w.push_back(103);
			w.push_back(329);
			w.push_back(103);
			w.push_back(354);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			w.push_back(77);
			w.push_back(0);
			w.push_back(77);
			w.push_back(354);
			w.push_back(1);
			wall.push_back(w);
			w.clear();
			tr.push_back(136);
			tr.push_back(432);
			tr.push_back(223);
			tr.push_back(432);
			trap.push_back(tr);
			tr.clear();
			mo.push_back(136);
			mo.push_back(432);
			mo.push_back(136);
			mo.push_back(456);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(223);
			mo.push_back(432);
			mo.push_back(223);
			mo.push_back(456);
			moss.push_back(mo);
			mo.clear();
			mo.push_back(222);
			mo.push_back(101);
			mo.push_back(222);
			mo.push_back(125);
			moss.push_back(mo);
			mo.clear();
			tr.push_back(238);
			tr.push_back(98);
			tr.push_back(248);
			tr.push_back(98);
			trap.push_back(tr);
			tr.clear();
			mo.push_back(248);
			mo.push_back(74);
			mo.push_back(248);
			mo.push_back(98);
			moss.push_back(mo);
			mo.clear();
			ar.push_back(294);
			ar.push_back(135);
			ar.push_back(359);
			ar.push_back(135);
			area.push_back(ar);
			ar.clear();
			w.push_back(256);
			w.push_back(22);
			w.push_back(256);
			w.push_back(72);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(256);
			ce.push_back(22);
			ce.push_back(333);
			ce.push_back(22);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(333);
			w.push_back(22);
			w.push_back(333);
			w.push_back(47);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(333);
			ce.push_back(47);
			ce.push_back(640);
			ce.push_back(47);
			ceiling.push_back(ce);
			ce.clear();
			w.push_back(486);
			w.push_back(47);
			w.push_back(486);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(359);
			w.push_back(135);
			w.push_back(359);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
		}
		else if (currentmap == 10)
		{
			for (int i = 0; i < (int)boss_sunflower.size(); i++)
			{
				delete boss_sunflower[i];
			}
			boss_sunflower.clear();
			boss_sunflower.push_back(new Sunflower(400, 175));
			w.push_back(26);
			w.push_back(0);
			w.push_back(26);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(103);
			w.push_back(0);
			w.push_back(103);
			w.push_back(73);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(103);
			ce.push_back(73);
			ce.push_back(640);
			ce.push_back(73);
			ceiling.push_back(ce);
			ce.clear();
			ar.push_back(97);
			ar.push_back(207);
			ar.push_back(199);
			ar.push_back(207);
			area.push_back(ar);
			ar.clear();
			w.push_back(97);
			w.push_back(207);
			w.push_back(97);
			w.push_back(223);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(199);
			w.push_back(207);
			w.push_back(199);
			w.push_back(223);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(276);
			ar.push_back(207);
			ar.push_back(379);
			ar.push_back(207);
			area.push_back(ar);
			ar.clear();
			w.push_back(276);
			w.push_back(207);
			w.push_back(276);
			w.push_back(223);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(397);
			w.push_back(207);
			w.push_back(397);
			w.push_back(223);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(60);
			ar.push_back(347);
			ar.push_back(607);
			ar.push_back(347);
			area.push_back(ar);
			ar.clear();
			w.push_back(60);
			w.push_back(347);
			w.push_back(60);
			w.push_back(364);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(607);
			w.push_back(347);
			w.push_back(607);
			w.push_back(364);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ce.push_back(60);
			ce.push_back(364);
			ce.push_back(607);
			ce.push_back(364);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(97);
			ce.push_back(223);
			ce.push_back(199);
			ce.push_back(223);
			ceiling.push_back(ce);
			ce.clear();
			ce.push_back(276);
			ce.push_back(223);
			ce.push_back(397);
			ce.push_back(223);
			ceiling.push_back(ce);
			ce.clear();
			tr.push_back(34);
			tr.push_back(456);
			tr.push_back(630);
			tr.push_back(34);
			trap.push_back(tr);
			tr.clear();
		}
		else if (currentmap == 11)
		{
			w.push_back(0);
			w.push_back(0);
			w.push_back(0);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			w.push_back(640);
			w.push_back(0);
			w.push_back(640);
			w.push_back(480);
			w.push_back(0);
			wall.push_back(w);
			w.clear();
			ar.push_back(0);
			ar.push_back(472);
			ar.push_back(640);
			ar.push_back(472);
			area.push_back(ar);
			ar.clear();
		}
	}
	int map::Getcurrentmap()
	{
		return currentmap;
	}
	bool map::getifisanimation()
	{
		if (Getcurrentmap() == 5)
		{
			ifisanimation=boss_bowser[0]->getisanimation();
			return ifisanimation;
		}
		if(Getcurrentmap()==10)
		{
			ifisanimation = boss_sunflower[0]->getisintro();
			return ifisanimation;
		}
		return ifisanimation;
		
	}
	void map::SetRestart()
	{
		currentmap = 0;
	}
	void map::playmusic()
	{
		if (currentmap == 0)
		{
			CAudio::Instance()->Play(1, true);
		}
		if(currentmap==1 || currentmap==2 || currentmap==3 || currentmap==4)
			CAudio::Instance()->Play(7, true);
		if (currentmap == 5)
		{
			CAudio::Instance()->Play(3, true);
		}
		if (currentmap == 6)
		{
			CAudio::Instance()->Play(8,true);
		}
		if (currentmap == 7 || currentmap==9 || currentmap==8)
		{
			CAudio::Instance()->Play(9, true);
		}
		if (currentmap == 10)
		{
			CAudio::Instance()->Play(10, true);
		}
		if (currentmap == 11)
		{
			CAudio::Instance()->Play(12, true);
		}
	}
	bool map::getisfinish()
	{
		return isfinish;
	}
	bool map::mattack()
	{
		return monsterattack;
	}
	int map::GetX()
	{
		return sx;
	}
	int map::GetY()
	{
		return sy;
	}
	void map::GetEraserXY(int eraserx, int erasery)
	{
		ex = eraserx;
		ey = erasery;
	}
	void map::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}
	void map::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}
	bool map::hitmonster(int bx, int by)
	{
		if (Getcurrentmap() == 0)
		{
			if (enemy_goomba.GetHit(bx, by) && enemy_goomba.gethp() >= 0)
				return true;
		}
		else if (Getcurrentmap() == 1)
		{
			for (int i = 0; i < (int)enemy_rex.size(); i++)
			{
				if(enemy_rex[i]->GetHit(bx, by) && enemy_rex[i]->GetHp()>=0)
					return true;
			}
		}
		else if (Getcurrentmap() == 5)
		{
			for (int i = 0; i < (int)boss_bowser.size(); i++)
			{
				if (boss_bowser[i]->GetHit(bx, by) && boss_bowser[i]->GetHp() >= 0)
					return true;
			}
		}
		else if (Getcurrentmap() == 10)
		{
			for (int i = 0; i < (int)boss_sunflower.size(); i++)
			{
				if (boss_sunflower[i]->GetHit(bx, by) && boss_sunflower[i]->GetHp() >= 0)
					return true;
			}
		}
		return false;
	}
	void map::MonsterOnMove()
	{
		if (Getcurrentmap() == 0)
			enemy_goomba.OnMove();
	}
	void map::OnMove()
	{
		const int STEP_SIZE = 7;
		if (isMovingRight)
		{
			if (640 - sx <= mpanimation->Width()) {
				sx -= STEP_SIZE;
			}
		}
		if (isMovingLeft)
		{
			if (sx + STEP_SIZE >= 0)
			{
				sx += 0-sx;
			}
			else
			{
				sx += STEP_SIZE;
			}
		}
		if (Getcurrentmap() == 3) 
		{
			for (int i = 0; i < (int)dic.size(); i++)
			{
				dic[i]->OnMove();
			}
		}
		if(Getcurrentmap() == 5)
		{
			for (int i = 0; i < (int) boss_bowser.size(); i++)
			{
				boss_bowser[i]->OnMove();
			}
		}
		if (Getcurrentmap() == 6)
		{
			ty32 = 380;
			tx32 = 1509 + sx;
			if (!istriger)
			{
				tx31 = 1269 + sx;
				ty31 = 340;
			}
			else tx31 += 60;
			if (ex - sx >= 1476)
			{
				istriger = true;
			}
		}
		GetmonsterXY();
	}
	void map::OnShow()
	{
		mpanimation->SetTopLeft(sx, sy);
		mpanimation->OnShow();
		if (Getcurrentmap() == 0)
		{
			enemy_goomba.SetMapXY(sx, sy);
			enemy_goomba.OnShow();
			enemy_goomba.GetEraserXY(ex-sx, ey);
			monsterattack = enemy_goomba.isattack();
		}
		else if (Getcurrentmap() == 1)
		{
			int x = 0;
			for (int i = 0; i < (int)enemy_rex.size(); i++)
			{
				enemy_rex[i]->GetEraserXY(ex, ey);
				enemy_rex[i]->OnShow();
				enemy_rex[i]->OnMove();
				if (enemy_rex[i]->isattack())
					monsterattack = true;
				if (enemy_rex[i]->GetHp() == 0)
				{
					delete enemy_rex[x];
					enemy_rex.erase(enemy_rex.begin()+x);
				}
				else
				{
					x++;
				}
			}
		}
		else if (Getcurrentmap() == 2)
		{
			for (int i = 0; i < (int)el.size(); i++)
				el[i]->On_ShowandMove();
		}
		else if (Getcurrentmap() == 3)
		{
			int x = 0;
			for (int i = 0; i < (int)dic.size(); i++)
			{
				dic[i]->OnShow();
			}
		}
		else if (Getcurrentmap() == 5)
		{
			for (int i = 0; i < (int)boss_bowser.size(); i++)
			{
				boss_bowser[i]->GetEraserXY(ex, ey);
				boss_bowser[i]->OnShow();
				boss_bowser[i]->GetKill(kill);
			}
		}
		else if (Getcurrentmap() == 6)
		{
			trap_3_1.SetTopLeft(tx31,ty31);
			trap_3_1.OnShow();
			if (ex - sx <= 1731)
			{
				trap_3_2.SetTopLeft(tx32, ty32);
				trap_3_2.OnShow();
			}
		}
		else if (Getcurrentmap() == 8 )
		{
			int x = 0;
			for (int i = 0; i < (int)trap41.size(); i++)
			{
				trap41[i]->GetEraserXY(ex, ey);
				trap41[i]->OnShow();
				if (trap41[i]->isattack())
					monsterattack = true;
				if (trap41[i]->Getty() <= 0)
				{
					delete trap41[x];
					trap41.erase(trap41.begin() + x);
				}
				else
					x++;
			}
		}
		else if (Getcurrentmap() == 10)
		{
			for (int i = 0; i < (int)boss_sunflower.size(); i++)
			{
				boss_sunflower[i]->GetEraserXY(ex, ey);
				boss_sunflower[i]->OnShow();
				boss_sunflower[i]->OnMove();
				boss_sunflower[i]->GetKill(kill);
				isattacking = boss_sunflower[i]->getisattacking();
				if (boss_sunflower[i]->isattack())
					monsterattack = true;
			}
		}
		kill = false;
	}
	bool map::isMapEnd(int ex, int ey)
	{
		if (currentmap == 0 && ex - sx >= 1987 && ex - sx <= 2104 && ey >= 480)
		{
			currentmap += 1;
			LoadBitmap();
			sx = 1934;
			sy = 1;
			Inital();
			OnShow();
			CAudio::Instance()->Stop(1);
			return true;
		}
		else if (currentmap == 1 && ex < 1 && ey <= 181 && ey >= 80)
		{
			currentmap +=1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 2 && ex < 1 && ey <= 181)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 3 && ex < 1 && ey <= 181)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 4 &&  ey >= 440)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			CAudio::Instance()->Stop(7);
			return true;
		}
		else if (currentmap == 5 && boss_bowser[0]->GetY2()<=0)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			CAudio::Instance()->Stop(5);
			return true;
		}
		else if (currentmap == 6 && ex - sx >= 3400)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			CAudio::Instance()->Stop(8);
			return true;
		}
		else if (currentmap == 7 && ex>=419 &&ey+25 >= 480)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 8 && ex >= 175 && ey + 25 >= 480)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			return true;
		}
		else if (currentmap == 9 && ex >= 358 && ey + 25 >= 480)
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			CAudio::Instance()->Stop(9);
			return true;
		}
		else if (currentmap == 10 && boss_sunflower[0]->getready())
		{
			currentmap += 1;
			LoadBitmap();
			Inital();
			OnShow();
			CAudio::Instance()->Stop(10);
			return true;
		}
		return false;
	}
}