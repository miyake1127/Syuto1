#pragma once

#include "DxLib.h"
#include "../support/vec3.h"
#include"player.h"

//ヘッダーでincludeではエラー 
class Enemy;

class Player {
public:
	 Player() {
		 GetWindowSize(&haba,&takasa);
		 width = 29;
		 height = 40;
		life = true;
		speed = 10;
		pos = t2k::vec3(400, 100, 0);
		LoadDivGraph("nasubi.png", 12, 3, 4, 49, 66, gfx);
	}

	//画像幅
	int width;
	int height;

	int gfx[12];
	float speed;
	t2k::vec3 pos;
	
	//画像表示
	int ix;
	int iy;
	int gfx_now;
	int ycount;
	int xcount;

	int life;

	//メンバ関数
	void move();
	void Draw();

	void All();
	int takasa;
	int haba;
	Enemy* enemyPtr;
	
};


