#ifndef _BOOMERANG_H_
#define _BOOMERANG_H_
namespace game_framework
{
	class boomerang
	{
	public:
		boomerang(int, int);
		int GetX();
		int GetY();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void delay(int &);
		void SetXY();
		vector<int> xy();
	protected:
		int boomx, boomy;
		int t;
		bool com;
		bool turn;
		CAnimation boom;
		vector<int > coordinate;
	};
}
#endif