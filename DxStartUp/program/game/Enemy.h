#pragma once
#include"../support/vec3.h"
#include"DxLib.h"
#include"player.h"
class Gamemanager;
class Enemy {
public:
	//ˆø”
	Enemy(Player* player,Gamemanager*gm) {
		playerPtr = player;
		//—N‚­êŠ‚Ì—”
		gmptr = gm;
		x = rand()%100;
		y = rand() % 100;
		//‰æ‘œ•
		width = 29;
		height = 40;
		//–½
		life = true;
		//‘¬‚³
		speed = 1;
		pos = t2k::vec3(x,y, 0);
		LoadDivGraph("pipo-halloweenchara2016_11.png", 12, 3, 4, 96 / 3, 128 / 4, gfx[0]);
		LoadDivGraph("teki2.png",12,3,4,96/3,128/4,gfx[1]);
		LoadDivGraph("teki3.png", 12, 3, 4, 96 / 3, 128 / 4, gfx[2]);
	}

	//—N‚«êŠ
	int x;
	int y;

	//‰æ‘œ•
	int width;
	int height;
	//“G‚Ì‰æ‘œ
	int gfx[3][12];
	int textureGraph;

	float speed;
	t2k::vec3 pos;

	//‰æ‘œ•\¦
	int ix;
	int iy;
	int gfx_now;
	int ycount;
	int xcount;

	int life;

	//ƒƒ“ƒoŠÖ”
	void move();
	void Draw();

	void All();
	Gamemanager* gmptr=nullptr;
	Player* playerPtr = nullptr;
};



