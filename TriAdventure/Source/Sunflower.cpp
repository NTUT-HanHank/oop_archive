#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Sunflower.h"
namespace game_framework
{
	Sunflower::Sunflower(int x, int y)
	{
		sx = x;
		sy = y;
		vx = 0; 
		cx = 0;
		cy = 0;
		vy = 300;
		LoadBitmap();
		isintro = true;
		kill = falow = fahigh = grow = final = firepollen = firing = fire = invincible = isattacking = isplay = firepollen = fp = isdead = ready = false;
		hp = 60;
		t = 90;						//§ï®É¶¡30 1¬í
		t2 = 60;
		t3 = 270;
		t4 = 150;
		attackmode = 0;
	}
	int Sunflower::GetX()
	{
		return sx;
	}
	int Sunflower::GetY()
	{
		return sy;
	}
	void Sunflower::LoadBitmap()
	{
		Intro.AddBitmap(Intro1, RGB(20, 31, 236));
		Intro.AddBitmap(Intro2, RGB(20, 31, 236));
		Intro.AddBitmap(Intro3, RGB(20, 31, 236));
		Intro.AddBitmap(Intro4, RGB(20, 31, 236));
		Intro.AddBitmap(Intro1, RGB(20, 31, 236));
		Intro.AddBitmap(Intro2, RGB(20, 31, 236));
		Intro.AddBitmap(Intro3, RGB(20, 31, 236));
		Intro.AddBitmap(Intro4, RGB(20, 31, 236));
		Intro.AddBitmap(Intro1, RGB(20, 31, 236));
		Intro.AddBitmap(Intro2, RGB(20, 31, 236));
		Intro.AddBitmap(Intro3, RGB(20, 31, 236));
		Intro.AddBitmap(Intro4, RGB(20, 31, 236));
		Intro.AddBitmap(Intro1, RGB(20, 31, 236));
		Intro.AddBitmap(Intro2, RGB(20, 31, 236));
		Intro.AddBitmap(Intro3, RGB(20, 31, 236));
		Intro.AddBitmap(Intro4, RGB(20, 31, 236));
		Intro.AddBitmap(Intro1, RGB(20, 31, 236));
		Intro.AddBitmap(Intro2, RGB(20, 31, 236));
		Intro.AddBitmap(Intro3, RGB(20, 31, 236));
		Intro.AddBitmap(Intro4, RGB(20, 31, 236));
		Intro.AddBitmap(Intro1, RGB(20, 31, 236));
		Intro.AddBitmap(Intro2, RGB(20, 31, 236));
		Intro.AddBitmap(Intro3, RGB(20, 31, 236));
		Intro.AddBitmap(Intro4, RGB(20, 31, 236));
		Intro.AddBitmap(Intro5, RGB(20, 31, 236));
		Intro.AddBitmap(Intro6, RGB(20, 31, 236));
		Intro.AddBitmap(Intro7, RGB(20, 31, 236));
		Intro.AddBitmap(Intro8, RGB(20, 31, 236));
		Intro.AddBitmap(Intro9, RGB(20, 31, 236));
		Intro.AddBitmap(Intro10, RGB(20, 31, 236));
		Intro.AddBitmap(Intro11, RGB(20, 31, 236));
		Intro.AddBitmap(Intro12, RGB(20, 31, 236));
		Intro.AddBitmap(Intro13, RGB(20, 31, 236));
		Intro.AddBitmap(Intro14, RGB(20, 31, 236));
		Intro.AddBitmap(Intro15, RGB(20, 31, 236));
		Intro.AddBitmap(Intro16, RGB(20, 31, 236));
		Intro.AddBitmap(Intro17, RGB(20, 31, 236));
		Intro.AddBitmap(Intro18, RGB(20, 31, 236));
		Intro.AddBitmap(Intro19, RGB(20, 31, 236));
		Intro.AddBitmap(Intro20, RGB(20, 31, 236));
		Idle.AddBitmap(Idle0,RGB(20,31,236));
		Idle.AddBitmap(Idle01, RGB(20, 31, 236));
		Idle.AddBitmap(Idle02, RGB(20, 31, 236));
		Idle.AddBitmap(Idle03, RGB(20, 31, 236));
		Idle.AddBitmap(Idle04, RGB(20, 31, 236));
		Idle.AddBitmap(Idle05, RGB(20, 31, 236));
		Idle.AddBitmap(Idle06, RGB(20, 31, 236));
		Idle.AddBitmap(Idle07, RGB(20, 31, 236));
		Idle.AddBitmap(Idle08, RGB(20, 31, 236));
		Idle.AddBitmap(Idle09, RGB(20, 31, 236));
		Idle.AddBitmap(Idle10, RGB(20, 31, 236));
		Idle.AddBitmap(Idle11, RGB(20, 31, 236));
		Idle.AddBitmap(Idle12, RGB(20, 31, 236));
		Idle.AddBitmap(Idle13, RGB(20, 31, 236));
		Idle.AddBitmap(Idle14, RGB(20, 31, 236));
		Idle.AddBitmap(Idle15, RGB(20, 31, 236));
		Idle.AddBitmap(Idle16, RGB(20, 31, 236));
		Idle.AddBitmap(Idle17, RGB(20, 31, 236));
		Idle.AddBitmap(Idle18, RGB(20, 31, 236));
		Idle.AddBitmap(Idle19, RGB(20, 31, 236));
		Idle.AddBitmap(Idle20, RGB(20, 31, 236));
		Idle.AddBitmap(Idle21, RGB(20, 31, 236));
		Idle.AddBitmap(Idle22, RGB(20, 31, 236));
		Idle.AddBitmap(Idle23, RGB(20, 31, 236));
		FA_Low.AddBitmap(FA_low01, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low02, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low03, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low04, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low05, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low06, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low07, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low08, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low09, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low10, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low11, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low12, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low13, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low14, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low15, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low16, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low17, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low18, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low19, RGB(21, 31, 236));
		FA_Low.AddBitmap(FA_low20, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high01, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high02, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high03, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high04, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high05, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high06, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high07, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high08, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high09, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high10, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high11, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high12, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high13, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high14, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high15, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high16, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high17, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high18, RGB(21, 31, 236));
		FA_High.AddBitmap(FA_high19, RGB(21, 31, 236));
		FS.AddBitmap(FS_01, RGB(21, 31, 236));
		FS.AddBitmap(FS_02, RGB(21, 31, 236));
		FS.AddBitmap(FS_03, RGB(21, 31, 236));
		FS.AddBitmap(FS_04, RGB(21, 31, 236));
		FS.AddBitmap(FS_05, RGB(21, 31, 236));
		FS.AddBitmap(FS_06, RGB(21, 31, 236));
		FS.AddBitmap(FS_07, RGB(21, 31, 236));
		FS.AddBitmap(FS_08, RGB(21, 31, 236));
		FS.AddBitmap(FS_09, RGB(21, 31, 236));
		FS.AddBitmap(FS_10, RGB(21, 31, 236));
		FS.AddBitmap(FS_11, RGB(21, 31, 236));
		FS.AddBitmap(FS_12, RGB(21, 31, 236));
		FS.AddBitmap(FS_13, RGB(21, 31, 236));
		FS.AddBitmap(FS_14, RGB(21, 31, 236));
		FS.AddBitmap(FS_15, RGB(21, 31, 236));
		FS.AddBitmap(FS_16, RGB(21, 31, 236));
		FS.AddBitmap(FS_17, RGB(21, 31, 236));
		FS.AddBitmap(FS_18, RGB(21, 31, 236));
		FS.AddBitmap(FS_19, RGB(21, 31, 236));
		FS.AddBitmap(FS_20, RGB(21, 31, 236));
		FS.AddBitmap(FS_21, RGB(21, 31, 236));
		FS.AddBitmap(FS_22, RGB(21, 31, 236));
		Create.AddBitmap(Create_01, RGB(21, 31, 236));
		Create.AddBitmap(Create_02, RGB(21, 31, 236));
		Create.AddBitmap(Create_03, RGB(21, 31, 236));
		Create.AddBitmap(Create_04, RGB(21, 31, 236));
		Create.AddBitmap(Create_05, RGB(21, 31, 236));
		Create.AddBitmap(Create_06, RGB(21, 31, 236));
		Create.AddBitmap(Create_07, RGB(21, 31, 236));
		Create.AddBitmap(Create_08, RGB(21, 31, 236));
		Create.AddBitmap(Create_09, RGB(21, 31, 236));
		Create.AddBitmap(Create_10, RGB(21, 31, 236));
		Create.AddBitmap(Create_11, RGB(21, 31, 236));
		Create.AddBitmap(Create_12, RGB(21, 31, 236));
		Create.AddBitmap(Create_13, RGB(21, 31, 236));
		Create.AddBitmap(Create_14, RGB(21, 31, 236));
		Create.AddBitmap(Create_15, RGB(21, 31, 236));
		Create.AddBitmap(Create_16, RGB(21, 31, 236));
		Create.AddBitmap(Create_17, RGB(21, 31, 236));
		Create.AddBitmap(Create_18, RGB(21, 31, 236));
		Create.AddBitmap(Create_19, RGB(21, 31, 236));
		Create.AddBitmap(Create_20, RGB(21, 31, 236));
		Create.AddBitmap(Create_21, RGB(21, 31, 236));
		Create.AddBitmap(Create_22, RGB(21, 31, 236));
		Create.AddBitmap(Create_23, RGB(21, 31, 236));
		Create.AddBitmap(Create_24, RGB(21, 31, 236));
		Create.AddBitmap(Create_25, RGB(21, 31, 236));
		Create.AddBitmap(Create_26, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_01, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_02, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_03, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_04, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_05, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_06, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_07, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_08, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_09, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_10, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_11, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_12, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_13, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_14, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_15, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_16, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_17, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_18, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_19, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_20, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_21, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_22, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_23, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_24, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_25, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_26, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_27, RGB(21, 31, 236));
		Final_Intro.AddBitmap(FIntro_28,RGB(21,31,236));
		Final_Idle.AddBitmap(FIdle_01, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_02, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_03, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_04, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_05, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_06, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_07, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_08, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_09, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_10, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_11, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_12, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_13, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_14, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_15, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_16, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_17, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_18, RGB(21, 31, 236));
		Final_Idle.AddBitmap(FIdle_19, RGB(21, 31, 236));
		FP.AddBitmap(FP_01, RGB(0, 128, 128));
		FP.AddBitmap(FP_02, RGB(0, 128, 128));
		FP.AddBitmap(FP_03, RGB(0, 128, 128));
		FP.AddBitmap(FP_04, RGB(0, 128, 128));
		FP.AddBitmap(FP_05, RGB(0, 128, 128));
		FP.AddBitmap(FP_06, RGB(0, 128, 128));
		FP.AddBitmap(FP_07, RGB(0, 128, 128));
		FP.AddBitmap(FP_08, RGB(0, 128, 128));
		FP.AddBitmap(FP_09, RGB(0, 128, 128));
		FP.AddBitmap(FP_10, RGB(0, 128, 128));
		FP.AddBitmap(FP_11, RGB(0, 128, 128));
		FP.AddBitmap(FP_12, RGB(0, 128, 128));
		FP.AddBitmap(FP_13, RGB(0, 128, 128));
		FP.AddBitmap(FP_14, RGB(0, 128, 128));
		FP.AddBitmap(FP_15, RGB(0, 128, 128));
		FP.AddBitmap(FP_16, RGB(0, 128, 128));
		FP.AddBitmap(FP_17, RGB(0, 128, 128));
		FP.AddBitmap(FP_18, RGB(0, 128, 128));
		FP.AddBitmap(FP_19, RGB(0, 128, 128));
		FP.AddBitmap(FP_20, RGB(0, 128, 128));
		FP.AddBitmap(FP_21, RGB(0, 128, 128));
		FP.AddBitmap(FP_22, RGB(0, 128, 128));
		vine.AddBitmap(vine01, RGB(21, 31, 236));
		Death.AddBitmap(Death_01, RGB(0, 100, 131));
		Death.AddBitmap(Death_02, RGB(0, 100, 131));
		Death.AddBitmap(Death_03, RGB(0, 100, 131));
		Death.AddBitmap(Death_04, RGB(0, 100, 131));
		Death.AddBitmap(Death_05, RGB(0, 100, 131));
		Death.AddBitmap(Death_06, RGB(0, 100, 131));
		Death.AddBitmap(Death_07, RGB(0, 100, 131));
		Death.AddBitmap(Death_08, RGB(0, 100, 131));
		Death.AddBitmap(Death_09, RGB(0, 100, 131));
		Death.AddBitmap(Death_10, RGB(0, 100, 131));
		Death.AddBitmap(Death_11, RGB(0, 100, 131));
		Death.AddBitmap(Death_12,RGB(0,100,131));
		lifebar.LoadBitmap(IDB_lifebar);
		lifebar_m.LoadBitmap(IDB_iifebar_m);
		Idle.SetDelayCount(2);
		Intro.SetDelayCount(3);
		FA_Low.SetDelayCount(3);
		FA_High.SetDelayCount(3);
		FP.SetDelayCount(3);
		FS.SetDelayCount(3);
		Create.SetDelayCount(4);
		Final_Intro.SetDelayCount(3);
		Final_Idle.SetDelayCount(2);
		Death.SetDelayCount(2);
	}
	void Sunflower::OnMove()
	{
		if (hp <= 0 || kill)
			hp = 0;
		if (isdead)
		{
			delay(t4);
			if (t4 <= 0)
			{
				ready = true;
			}
		}
		int x = 0,y = 0;
		if (isintro)
		{
			if (hp > 20)
				Intro.OnMove();
			else if (hp == 20)
			{
				Final_Intro.OnMove();
			}
			else if (hp == 0 && !isdead)
			{
				isdead = true;
			}
			else if (hp == 0)
			{
				Death.OnMove();
			}
		}
		else
		{
			if (!isattacking && !firepollen)
			{
				if (hp > 20)
				{
					Idle.OnMove();
					delay(t);
					if (t <= 0)
					{
						t = 90;
						Setattacking(true);
					}
				}
				else
				{
					Final_Idle.OnMove();
					delay(t2);
					delay(t3);
					if (t2 <= 0)
					{
						t2 = 60;
						SetFirePollen(true);
					}
				}
			}
			else
			{
				if(hp>20)
				if (attackmode == 0)
				{
					FA_Lowaddition();
				}
				if (attackmode == 1)
				{
					FA_Highaddition();
				}
				if (attackmode == 2)
				{
					Fireseed();
				}
				if (attackmode == 3)
				{
					Create_addition();
				}
			}
			if (firepollen)
			{
				FirePollen();
			}
		}
		if (firing)
		{
			x = rand() % 3;
			for (int i = 0; i < 7; i++)
			{
				y = rand() % 150 - 200;
				sd.push_back(new sunflower_seed(detseedxy[x][i], y));
			}
			firing = false;
		}
		for (int i = 0; i < (int)sd.size(); i++)
		{
			sd[i]->OnMove();
		}
		for (int i = 0; i < (int)brang.size(); i++)
		{
			brang[i]->OnMove();
		}
		for (int i = 0; i < (int)pollen.size(); i++)
		{
			pollen[i]->OnMove();
		}
	}
	void Sunflower::OnShow()
	{
		int x = 0;
		invincible = false;
		if (hp == 0)
		{
			isintro = true;
			isplay = false;
		}
		if (Intro.IsFinalBitmap() &&hp>20)
			isintro = false;
		if (Final_Intro.IsFinalBitmap() && isplay)
		{
			isintro = false;
			isattacking = false;
			final = true;
		}
		if (hp == 20 && !isplay)
		{
			invincible = true;
			isintro = true;
			isplay = true;
		}
		if (isintro && hp>20)
		{
			for (int i = 0; i < 40; i++)
			{
				if (Intro.GetCurrentBitmapNumber() == i)
				{
					sx = intro[i];
					Intro.SetTopLeft(sx,sy);
					Intro.OnShow();
				}
			}
		}
		else if (isintro && isplay)
		{
			Final_Intro.SetTopLeft(400, sy-100);
			Final_Intro.OnShow();
			if (Final_Intro.GetCurrentBitmapNumber() == 16)
				grow = true;
		}
		else if (isintro && hp == 0)
		{
			Death.SetTopLeft(400,sy-100);
			Death.OnShow();
		}
		else
		{
			sx = 400;
			if (hp > 20)
			{
				if (!isattacking)
				{
					Idle.SetTopLeft(400, sy);
					Idle.OnShow();
					invincible = true;
				}
				else
				{
					if (attackmode == 0)
					{
						for (int i = 0; i < 20; i++)
						{
							if (FA_Low.GetCurrentBitmapNumber() == i)
							{
								sx = fa_low[i];
								FA_Low.SetTopLeft(sx , sy);
								FA_Low.OnShow();								
							}
						}
					}
					else if (attackmode == 1)
					{
						for (int i = 0; i < 19; i++)
						{
							if (FA_High.GetCurrentBitmapNumber() == i)
							{
								sx = fa_high[i];
								FA_High.SetTopLeft(sx , sy - 150);
								FA_High.OnShow();
							}
						}

					}
					else if (attackmode == 2)
					{
						FS.SetTopLeft(sx, sy);
						FS.OnShow();
					}
					else if (attackmode == 3)
					{
						Create.SetTopLeft(sx, sy);
						Create.OnShow();
					}
				}
			}
			else if (final)
			{
				delay(t3);
				if (!firepollen)
				{
					Final_Idle.SetTopLeft(400, sy-100);
					Final_Idle.OnShow();
				}
				else
				{
					FP.SetTopLeft(400,sy-100);
					FP.OnShow();
				}
			}
		}
		if (grow)
		{
			vine.SetTopLeft(vx,vy);
			vine.OnShow();
		}
		for (int i = 0; i < (int)sd.size(); i++)
		{
			sd[i]->OnShow();
		}
		for (int i = 0; i < (int)brang.size(); i++)
		{
			brang[i]->OnShow();
		}
		for (int i = 0; i < (int)pollen.size(); i++)
		{
			pollen[i]->OnShow();
		}
		DeleteObject();
		lifebar.SetTopLeft(610, 90);
		lifebar.ShowBitmap();
		for (int i = 0; i < 60 - hp; i++)
		{
			if (i % 2 == 0)
			{
				lifebar_m.SetTopLeft(611, 91 + i/2 * 3);
				lifebar_m.ShowBitmap();
			}
		}
	}
	bool Sunflower::getisintro()
	{
		return isintro;
	}
	bool Sunflower::GetHit(int bx, int by)
	{
		if (hp == 20 && !final)
		{
			hp -= 0;
			return false;
		}
		if ((bx > sx ) && (by > sy&&by < sy + 313) && bx<640 && !invincible)
		{
			hp -= 1;
			return true;
		}
		return false;
	}
	void Sunflower::GetEraserXY(int x, int y)
	{
		ex = x;
		ey = y;
	}
	int Sunflower::GetHp()
	{
		if (hp <= 0)
			hp = 0;
		return hp;
	}
	void Sunflower::delay(int &time)
	{
		time -= 1;
	}
	void Sunflower::DeleteObject()
	{
		int index = 0;
		int index2 = 0;
		int index3 = 0;
		for (int i = 0; i < (int)sd.size(); i++)
		{
			if (sd[index]->GetY() > 480)
			{
				delete sd[index];
				sd.erase(sd.begin() + index);
			}
			else
			{
				index++;
			}
		}
		for (int i = 0; i < (int)brang.size(); i++)
		{
			if (brang[index2]->GetX() > 640)
			{
				CAudio::Instance()->Stop(11);
				delete brang[index2];
				brang.erase(brang.begin() + index2);
			}
			else
			{
				index2++;
			}
		}
		for (int i = 0; i < (int)pollen.size(); i++)
		{
			if (pollen[index3]->GetX() < 0)
			{
				delete pollen[index3];
				pollen.erase(pollen.begin() + index3);
			}
			else
			{
				index3++;
			}
		}
	}
	void Sunflower::FA_Lowaddition()
	{
		FA_Low.OnMove();
		if (FA_Low.IsFinalBitmap())
		{
			FA_Low.Reset();
			isattacking = false;
		}
	}
	void Sunflower::FA_Highaddition()
	{
		FA_High.OnMove();
		if (FA_High.IsFinalBitmap())
		{
			FA_High.Reset();
			isattacking = false;
		}
	}
	void Sunflower::Fireseed()
	{
		FS.OnMove();
		if (FS.IsFinalBitmap())
		{
			FS.Reset();
			isattacking = false;
		}
	}
	void Sunflower::Create_addition()
	{
		Create.OnMove();
		if (Create.GetCurrentBitmapNumber() == 19 && brang.size() == 0)
		{
			brang.push_back(new boomerang(372, 269));
			CAudio::Instance()->Play(11, true);
			fire = false;
		}
		if (Create.IsFinalBitmap())
		{
			Create.Reset();
			isattacking = false;
		}
	}
	void Sunflower::FirePollen()
	{
		FP.OnMove();
		if (FP.GetCurrentBitmapNumber() == 16 && pollen.size() == 0)
		{
			pollen.push_back(new Pollen(400, 170));
		}
		if (FP.IsFinalBitmap())
		{
			FP.Reset();
			firepollen = false;
		}
	}
	void Sunflower::Setattacking(bool a)
	{
		isattacking = a;
		if (isattacking)
		{
			attackmode = attackingmode[cx][cy];
			cy++;
			if (cy == 4)
			{
				cx++;
				cy = 0;
			}
			if (cx == 3)
			{
				cx = 0;
			}
			if (attackmode == 2)
			{
				firing = true;
			}
			if (attackmode == 3)
			{
				fire = true;
			}
		}
	}
	void Sunflower::SetFirePollen(bool a)
	{
		firepollen = a;
		if (firepollen)
			fp = true;
	}
	bool Sunflower::isattack()
	{
		if (isattacking)
		{
			if (attackmode == 0)
			{
				if (ey > 223)
				{
					if ((sx >= ex && ex + 25 >= sx) || (597 >= ex && 597 <= ex + 25) || (sx <= ex && 597 >= ex + 25))
						return true;
					return false;
				}
				return false;
			}
			if (attackmode == 1)
			{
				if (ey < 207)
				{
					if ((sx >= ex && ex + 25 >= sx) || (597 >= ex && 597 <= ex + 25) || (sx <= ex && 597 >= ex + 25))
						return true;
					return false;
				}
				return false;
			}
		}
		if (grow)
		{
			if (ey>=300)
			{
				if ((vx >= ex && ex + 25 >= vx) || (vx + vine.Width() >= ex && vx + vine.Width() <= ex + 25) || (vx <= ex && vx + vine.Width() >= ex + 25))
					return true;
				return false;
			}
		}
		return false;
	}
	int Sunflower::seedsize()
	{
		return sd.size();
	}
	vector<int> Sunflower::getseedxy(int i)
	{
		return sd[i]->seedxy();
	}
	int Sunflower::boomsize()
	{
		return brang.size();
	}
	vector<int> Sunflower::getboomxy(int i)
	{
		return brang[i]->xy();
	}
	bool Sunflower::getisattacking()
	{
		if (!final)
			return isattacking;
		else
			return firepollen;
	}
	int Sunflower::pollensize()
	{
		return pollen.size();
	}
	vector<int> Sunflower::getpollenxy(int i)
	{
		return pollen[i]->xy();
	}
	bool Sunflower::getready()
	{
		return ready;
	}
	void Sunflower::GetKill(bool k)
	{
		kill = k;
	}
}