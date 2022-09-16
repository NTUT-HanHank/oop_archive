#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "bowser.h"
#include <cstdlib>  //亂數相關函數 
#include <ctime>   // 時間相關函數 
namespace game_framework
{
	int bowser::GetX()
	{
		return bowx;
	}
	int bowser::GetY()
	{
		return bowy;
	}
	int bowser::GetY2()
	{
		return bowy+bowser_dead.Height();
	}
	void bowser::sett2()
	{
		if (hp < 10)
		{
			t2 = 9;
		}
	}
	bowser::bowser(int x,int y)
	{
		bowx = x;
		bowy = y;
		hp = 30;
		LoadBitmap();
		t = 240;
		t2 = 15;
		t3 = 300;
		t4 = 300;
		ishitting = isready = isinvincible = isdead = isadd = kill = false;
		isanimation = isfire = isfireballfinish = isironballfinish = readys = readys2 = true;
		delay_specialAttack = 20;
		direction = 0;				//0向左
		movex = 2;
		unsigned seed;
		seed = (unsigned)time(NULL); // 取得時
		srand(seed); // 以時間序列當亂數種子
	}
	void bowser::LoadBitmap()
	{
		flight.AddBitmap(IDB_flight1, RGB(194, 235, 200));
		flight.AddBitmap(IDB_flight2, RGB(194, 235, 200));
		flight.AddBitmap(IDB_flight3, RGB(194, 235, 200));
		flight.AddBitmap(IDB_flight4, RGB(194, 235, 200));
		flight.SetDelayCount(3);
		flightr.AddBitmap(IDB_flight_mover1, RGB(194, 235, 200));
		flightr.AddBitmap(IDB_flight_mover2, RGB(194, 235, 200));
		flightr.AddBitmap(IDB_flight_mover3, RGB(194, 235, 200));
		flightr.AddBitmap(IDB_flight_mover4, RGB(194, 235, 200));
		flightr.SetDelayCount(3);
		bowser_creep.AddBitmap(IDB_bowser_creep1_1, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep1_2, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep1_3, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep1_4, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep2_1, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep2_2, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep2_3, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep2_4, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep3_1, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep3_2, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep3_3, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep3_4, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_1, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_2, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_3, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_4, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_1, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_2, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_3, RGB(194, 235, 200));
		bowser_creep.AddBitmap(IDB_bowser_creep4_4, RGB(194, 235, 200));
		bowser_creep.SetDelayCount(7);
		special_attack1.AddBitmap(IDB_bowser_creep2_1, RGB(194, 235, 200));
		special_attack1.AddBitmap(IDB_bowser_creep2_2, RGB(194, 235, 200));
		special_attack1.AddBitmap(IDB_bowser_creep2_3, RGB(194, 235, 200));
		special_attack1.AddBitmap(IDB_bowser_creep2_4, RGB(194, 235, 200));
		special_attack1.SetDelayCount(3);
		bowser_move.AddBitmap(IDB_bowser_move1, RGB(194, 235, 200));
		bowser_move.AddBitmap(IDB_bowser_move2, RGB(194, 235, 200));
		bowser_move.AddBitmap(IDB_bowser_move3, RGB(194, 235, 200));
		bowser_move.AddBitmap(IDB_bowser_move4, RGB(194, 235, 200));
		bowser_move.SetDelayCount(5);
		bowser_mover.AddBitmap(IDB_bowser_mover1, RGB(194, 235, 200));
		bowser_mover.AddBitmap(IDB_bowser_mover2, RGB(194, 235, 200));
		bowser_mover.AddBitmap(IDB_bowser_mover3, RGB(194, 235, 200));
		bowser_mover.AddBitmap(IDB_bowser_mover4, RGB(194, 235, 200));
		bowser_mover.SetDelayCount(5);
		bowser_hurt.AddBitmap(IDB_bowser_hurt1, RGB(194, 235, 200));
		bowser_hurt.AddBitmap(IDB_bowser_hurt2, RGB(194, 235, 200));
		bowser_hurt.AddBitmap(IDB_bowser_hurt3, RGB(194, 235, 200));
		bowser_hurt.AddBitmap(IDB_bowser_hurt4, RGB(194, 235, 200));
		bowser_hurtr.AddBitmap(IDB_bowser_hurtr1, RGB(194, 235, 200));
		bowser_hurtr.AddBitmap(IDB_bowser_hurtr2, RGB(194, 235, 200));
		bowser_hurtr.AddBitmap(IDB_bowser_hurtr3, RGB(194, 235, 200));
		bowser_hurtr.AddBitmap(IDB_bowser_hurtr4, RGB(194, 235, 200));
		bowser_dead.AddBitmap(IDB_bowser_dead1, RGB(194, 235, 200));
		bowser_dead.AddBitmap(IDB_bowser_dead_2, RGB(194, 235, 200));
		bowser_dead.AddBitmap(IDB_bowser_dead3, RGB(194, 235, 200));
		bowser_dead.AddBitmap(IDB_bowser_dead4, RGB(194, 235, 200));
		bowser_dead.SetDelayCount(3);
		lifebar.LoadBitmap(IDB_lifebar);
		lifebar_m.LoadBitmap(IDB_iifebar_m);
	}
	void bowser::OnMove()
	{
		int k = 0;
		int dick = 0;
		if (hp < 0 || kill)	hp = 0;
		if ((hp == 20 && readys) || (hp==10&&readys2))
		{
			isinvincible = true;
			if (hp == 20)
			{
				isfireballfinish = false;
				readys = false;
			}
			else
			{
				isironballfinish = false;
				readys2 = false;
			}
		}
		if (hp == 0 && !isdead)
		{
			CAudio::Instance()->Stop(3);
			CAudio::Instance()->Play(5,true);
			isdead = true;
		}
		if (isanimation)
		{
			flight.OnMove();
			bowser_dead.OnMove();
		}
		else
		{
			if (hp > 0 && !isinvincible)
			{
				delayfireball(t2);
				if (direction == 0)
				{
					bowser_move.OnMove();
					if (ishitting)
						bowser_hurt.OnMove();
					else if (t2 <= 0)
					{
						bfb.push_back(new bowser_fireball(bowx, bowy));
						if (hp < 10)
							t2 = 9;
						else
							t2 = 15;
					}
				}
				else
				{
					bowser_mover.OnMove();
					if (ishitting)
						bowser_hurtr.OnMove();
					else if (t2 <= 0)
					{
						bfb.push_back(new bowser_fireball(bowx+bowser_move.Width(), bowy));
						if(hp < 10)
							t2 = 9;
						else
							t2 = 15;
					}
				}
			}
			else if (hp == 20 && isinvincible)
			{
				special_attack1.OnMove();
				if (!isfireballfinish)
				{
					if (delay_specialAttack == 0)
					{
						dick = rand() % 620;
						bfb.push_back(new bowser_fireball(dick, 0));
						delay_specialAttack = 5;
					}
					delay(delay_specialAttack);
					delay(t3);
					if (t3 == 0)
					{
						isinvincible = false;
						isfireballfinish = false;
					}
				}
			}
			else if (hp == 10 && isinvincible)
			{
				if (!isadd)
				{
					irb.push_back(new ironball(0, 100,0));
					irb.push_back(new ironball(580, 100,1));
					isadd = true;
				}
				special_attack1.OnMove();
				if (!isironballfinish)
				{
					delay(t4);
					if (t4 == 0)
					{
						isinvincible = false;
						isironballfinish = false;
					}
				}
			}
		}
		for (int i = 0; i < (int)bfb.size(); i++) {
			bfb[i]->OnMove();
		}
		for (int i = 0; i < (int)irb.size(); i++) {
			irb[i]->OnMove();
		}
	}
	bool bowser::ifishurt()
	{
		return ishitting;
	}
	void bowser::OnShow()
	{
		delay(t);
		if (t<=0)
		{
			if (isanimation)
			{
				if (bowy < 200 && hp>0)				//改30
				{
					flight.SetTopLeft(bowx, bowy);
					flight.OnShow();
					bowy += 5;
				}
				else if (bowy == 200 && !bowser_creep.IsFinalBitmap())
				{
					bowser_creep.OnMove();
					bowser_creep.SetTopLeft(bowx, bowy);
					bowser_creep.OnShow();
				}
				else if (hp == 0)
				{
					bool isready = false;
					bowser_dead.SetTopLeft(bowx, bowy);
					bowser_dead.OnShow();
					if (bowx <= 300)
					{
						bowx += 1;
					}
					else if (bowx >= 300)
					{
						bowx -= 1;
					}
					if (bowx == 300) isready = true;
					if (isready)
					{
						bowy -= 6;
					}
				}
				if (bowser_creep.IsFinalBitmap()) isanimation = false;
			}
			else
			{	
				if (hp > 0 && !isinvincible)
				{
					isanimation = false;
					if (ishitting)
					{
						if (direction == 0)
						{
							bowser_hurt.SetTopLeft(bowx, bowy);
							bowser_hurt.OnShow();
							bowser_hurt.SetDelayCount(5);
							if (bowser_hurt.IsFinalBitmap())
							{
								ishitting = false;
								bowser_hurt.Reset();
							}
							
						}
						else
						{
							bowser_hurtr.SetTopLeft(bowx, bowy);
							bowser_hurtr.OnShow();
							bowser_hurtr.SetDelayCount(5);
							if (bowser_hurtr.IsFinalBitmap())
							{
								ishitting = false;
								bowser_hurtr.Reset();
							}
						}
					}
					else
					{
						if (direction == 0)
						{
							bowser_move.SetTopLeft(bowx, bowy);
							bowser_move.OnShow();
							bowx -= 8;
							if (bowx<=300)
							{
								bowy -= movex;
							}
							else if (bowx >=300)
							{
								bowy += movex;
							}
							if (bowx <= 0)
							{
								direction = 1;
							}
						}
						else if (direction == 1)
						{
							bowser_mover.SetTopLeft(bowx, bowy);
							bowser_mover.OnShow();
							bowx += 8;
							if (bowx <= 300)
							{
								bowy += movex;
							}
							else if (bowx >= 300)
							{
								bowy -= movex;
							}
							if (bowx >= 576)
							{
								direction = 0;
							}
						}
					}
				}
				else if (hp == 20 && isinvincible)
				{
					special_attack1.SetTopLeft(bowx, bowy);
					special_attack1.OnShow();
				
				}
				else if (hp == 10 && isinvincible)
				{
					special_attack1.SetTopLeft(bowx, bowy);
					special_attack1.OnShow();
					for (int i = 0;i < (int)irb.size(); i++)
					{
						irb[i]->OnShow();
					}
				}
				for (int i = 0; i < (int)bfb.size(); i++)
				{
					bfb[i]->OnShow();
				}
			}
			DeleteObject();
			lifebar.SetTopLeft(610,90);
			lifebar.ShowBitmap();
			for (int i = 0; i < 30 - hp; i++)
			{
				lifebar_m.SetTopLeft(611, 91 + i * 3);
				lifebar_m.ShowBitmap();
			}
		}
		if (hp == 0) isanimation = true;
	}
	bool bowser::getisanimation()
	{
		return isanimation;
	}
	bool bowser::GetHit(int bx, int by)
	{
		if ((bx > bowx  && bx < bowx +bowser_move.Width()) && (by > bowy&&by < bowy + bowser_move.Height()))
		{
			if(!isinvincible)
				hp -= 1;
			ishitting = true;
			return true;
		}
		return false;
	}
	void bowser::GetEraserXY(int x, int y)
	{
		ex = x;
		ey = y;
	}
	int bowser::GetHp()
	{
		return hp;
	}
	void bowser::delay(int &time)
	{
		time -= 1;
	}
	void bowser::delayfireball(int &time2)
	{
		time2 -= 1;
	}
	void bowser::DeleteObject()
	{
		int index = 0;
		for (int i = 0; i < (int)bfb.size(); i++)
		{
			if (bfb[index]->getcont() || (hp == 10 && isinvincible))
			{
				delete bfb[index];
				bfb.erase(bfb.begin()+index);
			}
			else
			{
				index++;
			}
		}
	}
	void bowser::Setmovex()
	{
		if (hp < 20)
		{
			movex = 8;
		}
	}
	int bowser::bfbSize()
	{
		return bfb.size();
	}
	vector<int> bowser::getbfbXY(int i)
	{
		return bfb[i]->xy();
	}
	int bowser::irbSize()
	{
		return irb.size();
	}
	vector<int> bowser::getirbXY(int i)
	{
		return irb[i]->xy();
	}
	void bowser::GetKill(bool k)
	{
		kill = k;
	}
}