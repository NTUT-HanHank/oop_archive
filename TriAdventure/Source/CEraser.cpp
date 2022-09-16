#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
namespace game_framework {
	int CEraser::GetX1()
	{
		return x;
	}
	int CEraser::GetY1()
	{
		return y;
	}
	int CEraser::GetX2()
	{
		return x + animation.Width();
	}
	int CEraser::GetY2()
	{
		return y + animation.Height();
	}
	void CEraser::Initialize(map* m)
	{
		int X_POS[12] = { 150,100,618,618,618,55,20,25,435,181,65,88};
		int Y_POS[12] = { 210 - animation.Height(),0,160,160,160,0,410,450,6,6,6,0};
		world_1 = m;
		timer_bullet = 0;
		jumpCounter = 1;
		for (int i = 0; i < sizeof(X_POS); i++)
		{
			if (world_1->Getcurrentmap() == i)
			{
				x = X_POS[i];
				y = Y_POS[i];
			}
		}
		world_1->GetEraserXY(x, y);
		velocity = 10;
		invincible = isdoublejump = isMovingLeft = isMovingRight = isMovingUp = isMovingDown = attack = isjumping = mapmovingleft = isdead = isclimbing = false;
		isOnFloor = true;
		direction = 0;
	}
	void CEraser::LoadBitmap()
	{
		animation.AddBitmap(IDB_CHAC, RGB(255, 255, 255));
		animation2.AddBitmap(IDB_chac2, RGB(255, 255, 255));
	}
	void CEraser::OnMove()
	{
		int x_POS[12] = { 150,100,618,618,618,55,20,25,435,181,65,88};
		int y_POS[12] = { 210 - animation.Height(),0,160,140,140,0,410,450,6,6,6,0};
		if(world_1)
		judgemonster();
		if (!invincible && (world_1->judgetrap(x, &y, animation.Height()) || world_1->mattack()))
		{
			isdead = true;
		}
		if (world_1->isMapEnd(x, y))
		{
			for (int z = 1; z < sizeof(x_POS); z++)
			{
				if (z == world_1->Getcurrentmap())
				{
					x = x_POS[z];
					y = y_POS[z];
				}
			}
		}
		if (!world_1->getifisanimation())
		{
			if (attack)
			{
				if (clock() - timer_bullet >= 400)
				{
					timer_bullet = clock();
					if (direction == 0)
					{
						bullet.push_back(new Bullet(x + animation.Width(), y + (animation.Height() / 2), direction));
						CAudio::Instance()->Play(4,false);
					}
					else
					{
						bullet.push_back(new Bullet(x, y + (animation.Height() / 2), direction));
						CAudio::Instance()->Play(4, false);
					}
				}
			}
		}
		if (!world_1->judgearea(x, &y, animation.Height(), &isOnFloor) && !isMovingUp && !isjumping)
		{
			isMovingDown = true;
			isMovingUp = false;
		}
		else {
			isMovingDown = false;
		}
		if (isOnFloor) 
		{
			SetOnFloor(); 
			velocity = initial_velocity;
		}
		if (world_1->judgemoss(&x, y, direction))
		{
			isdead = true;
		}
		const int STEP_SIZE = 7;
		int i = 0;
		bool temp;
		temp = world_1->judgewall(&x, y, direction, &isclimbing);
		if (isMovingLeft) {
			if (world_1->Getcurrentmap() == 0 || world_1->Getcurrentmap()==6)
			{
				if (world_1->judgewall(&x, y, direction, &isclimbing))
				{
					SetMovingLeft(false);
					mapmovingleft = false;
				}
				else
				{
					if (x <= 260)
					{
						mapmovingleft = true;
					}
					if (world_1->GetX() == 0 || x > 260)
						x -= STEP_SIZE;
				}
			}
			else if (!(world_1->Getcurrentmap() == 0) || !(world_1->Getcurrentmap() == 6))
			{
				if (world_1->judgewall(&x, y, direction, &isclimbing))
					SetMovingLeft(false);
				else x -= STEP_SIZE;
			}
		}
		if (isMovingRight && (world_1->Getcurrentmap() == 0||world_1->Getcurrentmap()==6))
		{
			if (world_1->Getcurrentmap() == 0)
			{
				if (world_1->judgewall(&x, y, direction, &isclimbing))
				{
					mapmoving = false;
					SetMovingRight(false);
				}
				else
				{
					if (x >= 260 && 680 - world_1->GetX() < 2105) { mapmoving = true; }
					else if (x < 660) { x += STEP_SIZE; }
				}
			}
			else if (world_1->Getcurrentmap() == 6)
			{
				if (world_1->judgewall(&x, y, direction, &isclimbing))
				{
					mapmoving = false;
					SetMovingRight(false);
				}
				else
				{
					if (x >= 260 && 680 - world_1->GetX() < 3395) { mapmoving = true; }
					else if (x < 660) { x += STEP_SIZE; }
				}
			}
		}
		else if (isMovingRight && (!(world_1->Getcurrentmap() == 0)||!(world_1->Getcurrentmap()==6)))
		{
			if (world_1->judgewall(&x, y, direction, &isclimbing))
				SetMovingRight(false);
			else x += STEP_SIZE;
		}
		else  mapmoving = false;
		if (isMovingUp)
		{
			jump("jump");
		}
		if (isMovingDown)
		{
			isMovingUp = false;
			jump("fall");
		}
		world_1->GetEraserXY(x,y);
		
	}
	void CEraser::jump(string state)
	{
		if (isMovingUp)
		{
			if (abs(velocity) > initial_velocity) velocity = initial_velocity;
			if (jumpCounter == 1) { velocity = initial_velocity; jumpCounter += 1; }
			if (velocity > 0)
			{
				if (world_1->judgeceiling(x, y))
				{
					isMovingUp = false;
					isMovingDown = true;
					velocity = 1;
				}
				else
				{
					velocity--;
				}
				y -= velocity;
			}
			else
			{
				isMovingUp = false;
				isMovingDown = true;
				velocity = 1;
			}
		}
		else
		{
			if (isclimbing)
			{
				velocity = 5;
				jumpCounter = 0;
			}
			else if (velocity < initial_velocity)
			{
				velocity++;
				isMovingUp = false;
			}
			y += velocity;
		}
	}
	void CEraser::SetOnFloor()
	{
		jumpCounter = 0;
	}
	int CEraser::GetJumpCount()
	{
		return jumpCounter;
	}
	bool CEraser::GetOnFloor()
	{
		if (isOnFloor) return true;
		return false;
	}
	void CEraser::shooting(bool flag)
	{
		attack = flag;
	}
	void CEraser::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}
	void CEraser::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}
	void CEraser::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}
	void CEraser::SetMovingUp(bool flag)
	{
		jumpCounter += 1;
		isMovingUp = flag;
	}
	void CEraser::Setdir(int n)
	{
		direction = n;
	}
	void CEraser::SetmapLeft(bool flag)
	{
		mapmovingleft = flag;
	}
	void CEraser::Setinvincible(bool flag)
	{
		invincible = flag;
	}
	bool CEraser::Getinvincible()
	{
		return invincible;
	}
	void CEraser::judgemonster()
	{
		for (int i = 0; i < world_1->monsterxysize(); i++)
		{
			if ((world_1->SendMonsterXY(i)[2] >= y && world_1->SendMonsterXY(i)[2] <= y + 25) || (world_1->SendMonsterXY(i)[3] <= y + 25 && world_1->SendMonsterXY(i)[3] >= y))
			{
				if ((world_1->SendMonsterXY(i)[0] >= x && x + 25 >= world_1->SendMonsterXY(i)[0]) || (world_1->SendMonsterXY(i)[1] >= x && world_1->SendMonsterXY(i)[1] <= x + 25) || (world_1->SendMonsterXY(i)[0] <= x && world_1->SendMonsterXY(i)[1] >= x + 25))
				{
					isdead = true;
					break;
				}
				else isdead = false;
			}
			else isdead = false;
		}
	}
	void CEraser::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}
	bool CEraser::GetMovingSituation()
	{
		return mapmoving;
	}
	bool CEraser::GetMovingLeft()
	{
		return mapmovingleft;
	}
	bool CEraser::Getisdead()
	{
		return isdead;
	}
	void CEraser::OnShow()
	{
		vector<int> del;
		if (direction == 0)
		{
			animation.SetTopLeft(x, y);
			animation.OnShow();
		}
		else
		{
			animation2.SetTopLeft(x, y);
			animation2.OnShow();
		}
		for (int i = 0; i<int(bullet.size()); i++)
		{
			bullet[i]->OnShow();
			if (!bullet[i]->HitSituation())
			{
				bullet[i]->SetHit(world_1->hitmonster(bullet[i]->GetX(), bullet[i]->GetY()));
			}
			else
			{
				del.push_back(i);
			}
		}
		for (int i = (int)del.size() - 1; i >= 0; i--)
		{
			delete bullet[del[i]];
			bullet.erase(bullet.begin() + del[i]);
		}
	}
}