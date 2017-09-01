#pragma once
#include"DxLib.h"

class Gamemanager {
public:
	Gamemanager() {
		
		gfx= LoadGraph("haikei.png");
		zimen = LoadGraph("zimen.png");
		GetMousePoint(&mx, &my);
		

	}
	//“G‚Ì‰æ‘œ
	int enemy_gfx[3][12];
	//ƒ}ƒEƒXˆ—
	int mx;
	int	my;

	int gfx;
	int zimen;
	static Gamemanager*getInstanse();
	
	//•Ç
	int wall;
	void Draw();
};