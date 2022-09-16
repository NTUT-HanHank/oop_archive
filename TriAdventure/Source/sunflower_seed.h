#ifndef _SUNFLOWER_SEED_H_
#define _SUNFLOWER_SEED_H_
namespace game_framework
{
	class sunflower_seed
	{
	public:
		sunflower_seed(int, int);
		int GetX();
		int GetY();
		void OnShow();
		void OnMove();
		void LoadBitmap();
		void SetXY();
		vector<int> seedxy();
	protected:
		int seedx, seedy;
		CAnimation seed;
		vector<int> coordinate;
	};
}
#endif