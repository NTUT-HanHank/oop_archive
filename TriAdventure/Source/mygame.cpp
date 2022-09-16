/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <fstream>
#include <string>
#include "mygame.h"
int selectPage = 0;
int isFinish = 0;
bool isClear = false;
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	/////////////////////////////////////////////////////////////////////////////
	CGameStateInit::CGameStateInit(CGame *g)
		: CGameState(g)
	{
	}
	void CGameStateInit::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(0);	// 一開始的loading進度為0%
		//
		// 開始載入資料
		//
		title.LoadBitmap(IDB_title);
		arrow.LoadBitmap(IDB_arrow, RGB(255,255,0));
		aboutmenu.LoadBitmapA(about);
		option.LoadBitmap(IDB_option);
		isoption = isabout = false;
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
		CAudio::Instance()->Load(0, "Sounds\\mainmenu.mp3");
		CAudio::Instance()->Play(0, true);
	}
	void CGameStateInit::OnBeginState()
	{
		currentoption = 0;
		
	}
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_SPACE = 13;
		if (nChar == KEY_DOWN)
		{
			if (currentoption == 0)
				currentoption = 1;
			else if (currentoption == 1)
				currentoption = 2;
			else if(currentoption==2)
				currentoption = 3;
			else if (currentoption == 3)
				currentoption = 0;
		}
		if (nChar == KEY_SPACE)
		{
			if (currentoption == 0)
			{
				CAudio::Instance()->Stop(0);
				if (isClear)
					selectPage = 0;
				GotoGameState(GAME_STATE_RUN);
			}
			else if (currentoption == 1)
				isoption = true;
			else if (currentoption == 2)
				isabout = true;
			else if(currentoption==3)
				PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
		}
		if (nChar == KEY_UP)								// Demo 關閉遊戲的方法
			if (currentoption == 0)
				currentoption = 3;
			else if (currentoption == 1)
				currentoption = 0;
			else if (currentoption == 2)
				currentoption = 1;	
			else if (currentoption == 3)
				currentoption = 2;
		if (nChar == KEY_ESC)
		{
			isoption = false;
			isabout = false;
		}
	}
	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}
	void CGameStateInit::OnShow()
	{
		//
		// 貼上logo
		//
		
		if (isoption)
		{
			option.SetTopLeft(0, 0);
			option.ShowBitmap();
		}
		if (isabout)
		{
			aboutmenu.SetTopLeft(0, 0);
			aboutmenu.ShowBitmap();
		}
		if (!isoption && !isabout)
		{
			title.SetTopLeft(0, 0);
			title.ShowBitmap();
			if (currentoption == 0)
			{
				arrow.SetTopLeft(250, 276);
				arrow.ShowBitmap();
			}
			if (currentoption == 1)
			{
				arrow.SetTopLeft(250, 330);
				arrow.ShowBitmap();
			}
			if (currentoption == 2)
			{
				arrow.SetTopLeft(250, 384);
				arrow.ShowBitmap();
			}
			if (currentoption == 3)
			{
				arrow.SetTopLeft(250, 437);
				arrow.ShowBitmap();
			}
		}
		//
		// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
		//
		
	}
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	/////////////////////////////////////////////////////////////////////////////
	CGameStateOver::CGameStateOver(CGame *g)
		: CGameState(g)
	{
	}
	void CGameStateOver::OnMove()
	{
		game_over_title.OnMove();
	}
	void CGameStateOver::OnBeginState()
	{
		CAudio::Instance()->Play(2, true);

	}
	void CGameStateOver::OnInit()
	{
		game_over_title.AddBitmap(IDB_game_over1);
		game_over_title.AddBitmap(IDB_game_over2);
		game_over_title.AddBitmap(IDB_game_over3);
		game_over_title.AddBitmap(IDB_game_over4);
		game_over_title.AddBitmap(IDB_game_over5);
		game_over_title.AddBitmap(IDB_game_over4);
		game_over_title.AddBitmap(IDB_game_over3);
		game_over_title.AddBitmap(IDB_game_over2);
		game_over_title.AddBitmap(IDB_game_over1);
		game_over_title.SetDelayCount(5);
		CAudio::Instance()->Load(2, "Sounds\\dead.mp3");
	}
	void CGameStateOver::OnShow()					//全部刪掉
	{
		game_over_title.OnShow();

	}
	void CGameStateOver::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_Z = 0x5A;
		const char KEY_R = 0x52;
		const char KEY_M = 77;
		if (nChar == KEY_M)
		{
			GotoGameState(GAME_STATE_INIT);
			selectPage = 0;
			CAudio::Instance()->Stop(2);
			CAudio::Instance()->Play(0, true);
		}
		if (nChar == KEY_R)
		{
			GotoGameState(GAME_STATE_RUN);
			CAudio::Instance()->Stop(2);
		}
	}
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	/////////////////////////////////////////////////////////////////////////////
	CGameStateRun::CGameStateRun(CGame *g)
		: CGameState(g), NUMBALLS(28)
	{
	}
	CGameStateRun::~CGameStateRun()
	{
	}
	void CGameStateRun::OnBeginState()
	{
		if (selectPage == 0 || isClear)
		{
			world_1.SetRestart();
			isClear = false;
		}
		world_1.Inital();
		world_1.LoadBitmap();
		eraser.Initialize(&world_1);
		world_1.MonsterInitial();
		/*CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
		CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
		CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI*/
	}
	void CGameStateRun::OnMove()							// 移動遊戲元素
	{
		world_1.SetMovingRight((eraser.GetMovingSituation()));
		world_1.SetMovingLeft(eraser.GetMovingLeft());
		world_1.OnMove();
		eraser.OnMove();
		world_1.MonsterOnMove();

		selectPage=world_1.Getcurrentmap();
		if (!eraser.Getinvincible() &&(eraser.GetX1() - world_1.GetX() < 1985 && eraser.GetY1() >= 480 || eraser.Getisdead()))
		{
			CAudio::Instance()->Pause();
			GotoGameState(GAME_STATE_OVER);
		}
	}
	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		eraser.LoadBitmap();
		world_1.LoadBitmap();
		world_1.MonsterLoadBitmap();
		CAudio::Instance()->Load(1,"Sounds\\world_1.mp3");
		CAudio::Instance()->Load(3,"Sounds\\bowser.mp3");
		CAudio::Instance()->Load(4, "Sounds\\bullet.wav");
		CAudio::Instance()->Load(5, "Sounds\\win.mp3");
		CAudio::Instance()->Load(6,"Sounds\\dick.WAV");
		CAudio::Instance()->Load(7, "Sounds\\world_2.mp3");
		CAudio::Instance()->Load(8, "Sounds\\world_3.mp3");
		CAudio::Instance()->Load(9, "Sounds\\world_4.mp3");
		CAudio::Instance()->Load(10, "Sounds\\sunflower.mp3");
		CAudio::Instance()->Load(11, "Sounds\\vszxd-khhv6.mp3");
		CAudio::Instance()->Load(12, "Sounds\\ending.mp3");
		demo = false;
		kill = false;
		ShowInitProgress(50);
		Sleep(300);
	}
	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_Z = 0x5A;
		const char KEY_R = 0x52;
		const char KEY_D = 68;
		const char KEY_M = 77;
		const char KEY_K = 75;
		if (nChar == KEY_LEFT )
		{
			eraser.Setdir(1);
			eraser.SetMovingLeft(true);
		}
		if (nChar == KEY_RIGHT) {
			eraser.Setdir(0);
			eraser.SetMovingRight(true);
		}
		if (nChar == KEY_UP && (eraser.GetOnFloor() || eraser.GetJumpCount() < 2)) {
			eraser.SetMovingUp(true);
		}
		if (nChar == KEY_Z)
			eraser.shooting(true);
		if (nChar == KEY_D)
		{
			demo = !demo;
			eraser.Setinvincible(demo);
		}
		if (!world_1.getifisanimation())
		{
			if (nChar == KEY_K)
			{
				kill = !kill;
				world_1.GetisKill(kill);
			}
		}
		if (world_1.Getcurrentmap() == 11)
		{
			if (nChar == KEY_M)
			{
				CAudio::Instance()->Stop(12);
				CAudio::Instance()->Play(0, true);
				isClear = true;
				GotoGameState(GAME_STATE_INIT);
			}
		}
	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_Z = 0x5A;
		if (nChar == KEY_LEFT)
		{
			eraser.SetMovingLeft(false);
			eraser.SetmapLeft(false);
		}
		if (nChar == KEY_RIGHT)
			eraser.SetMovingRight(false);
		if (nChar == KEY_Z)
			eraser.shooting(false);
	}
	void CGameStateRun::OnShow()
	{
		world_1.OnShow();
		eraser.OnShow();
	}
}