#ifndef _TRAP_4_1_H_
#define _TRAP_4_1_H_
namespace game_framework
{
	class trap4_1
	{
	public:
		trap4_1(int, int,int);
		void GetEraserXY(int, int);
		int  Getty();
		void LoadBitmap();
		bool isattack();
		void OnShow();
	protected:
		int tx, ty;
		int ex, ey;
		int id;
		bool istriger;
		CAnimation trap_4_1;
	};
}
#endif