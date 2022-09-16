#ifndef _BOWSERFIREBALL_H_
#define _BOWSERFIREBALL_H_
namespace game_framework
{
	class bowser_fireball
	{
	public:
		bowser_fireball(int,int);
		int GetX();
		int GetY();
		void LoadBitmap();
		void OnShow();
		void OnMove();
		void delay(int &);
		bool getcont();
		void SetXY();
		vector<int> xy();
	protected:
		int bfx, bfy;
		bool cont;
		int t;
		CAnimation bf;
		vector<int > coordinate;
	};
}
#endif