#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_
namespace game_framework {
	class elevator
	{
	public:
		elevator(int, int, int, int);
		int GetX2();
		int GetX();
		int GetY();
		void LoadBitmap();
		void On_ShowandMove();
	protected:
		CMovingBitmap map2_elevator;
		int x, y;
		int tx, ty;
		int bux, buy;
		int dir;
	};
}
#endif