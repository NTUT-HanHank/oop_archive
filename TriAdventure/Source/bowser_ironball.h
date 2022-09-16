#ifndef _BOWSER_IRONBALL_H_
#define _BOWSER_IRONBALL_H_
namespace game_framework
{
	class ironball
	{
	public:
		ironball(int, int,int);
		int GetX();
		int GetY();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetXY();
		vector<int> xy();
	protected:
		int ix, iy;
		int direction;
		int t;
		bool isready;
		CAnimation ib;
		vector<int > coordinate;
	};
}
#endif