#pragma once
#include"DxLib.h"

class Gamemanager {
public:
	Gamemanager() {
		
		gfx= LoadGraph("haikei.png");
		zimen = LoadGraph("zimen.png");
		GetMousePoint(&mx, &my);
		

	}
	//�G�̉摜
	int enemy_gfx[3][12];
	//�}�E�X����
	int mx;
	int	my;

	int gfx;
	int zimen;
	static Gamemanager*getInstanse();
	
	//��
	int wall;
	void Draw();
};