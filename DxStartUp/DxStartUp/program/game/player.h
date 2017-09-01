#pragma once

#include "DxLib.h"
#include "../support/vec3.h"

//�w�b�_�[��include�ł̓G���[ 
class Enemy;

class Player {
public:
	 Player() {
		 jump_flg = false;
		 HP_gfx = LoadGraph("heat.png");
		 HP = 150;
		 GetWindowSize(&haba,&takasa);
		 width = 29;
		 height = 40;
		speed = 5;
		pos = t2k::vec3(44, 734, 0);
		LoadDivGraph("nasubi.png", 12, 3, 4, 49, 66, gfx);
	}
	 int HP_gfx;
	//�摜��
	int width;
	int height;

	int gfx[12];
	float speed;
	t2k::vec3 pos;
	int HP;
	//�摜�\��
	int ix;
	int iy;
	int gfx_now;
	int ycount;
	int xcount;

	//�W�����v
	bool jump_flg;

	//�����o�֐�
	void move();
	void Draw();

	void All();
	int takasa;
	int haba;
	Enemy* enemyPtr;
	
};


