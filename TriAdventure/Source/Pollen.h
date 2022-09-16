#ifndef _POLLEN_H_
#define _POLLEN_H_
namespace game_framework
{
	class Pollen
	{
	public:
		Pollen(int, int);
		int GetX();
		int GetY();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void delay(int &);
		void SetXY();
		vector<int> xy();
	protected:
		int px, py;
		int t;
		int count;
		CAnimation polen;
		vector<int > coordinate;
	};
}
#endif