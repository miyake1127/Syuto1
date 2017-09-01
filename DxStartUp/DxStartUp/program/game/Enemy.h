#pragma once
#include"../support/vec3.h"
#include"DxLib.h"
#include"player.h"
#include"Bullet.h"
class Bullet;
class Gamemanager;
class Enemy {
public:
	//ˆø”
	Enemy(Player* player, Gamemanager*gm) {
		playerPtr = player;
		//—N‚­êŠ‚Ì—”
		//bulletptr = b;
		enemy_type = 0;
		enemy_now = 1;
		enemy_posY = 0;
		gmptr = gm;
		y[0] = 734;
		y[1] = 550;
		//–½
		life = true;
		//—N‚«ŠÔ
		sporn_time = 0;
		//‘¬‚³
		speed = 1;
		

		enemy_flg = false;

	
		pos = t2k::vec3(1270,y[enemy_posY], 0);
		LoadDivGraph("pipo-halloweenchara2016_11.png", 12, 3, 4, 96 / 3, 128 / 4, gfx[0]);
		LoadDivGraph("teki2.png",12,3,4,96/3,128/4,gfx[1]);
		LoadDivGraph("teki3.png", 12, 3, 4, 96 / 3, 128 / 4, gfx[2]);
		gfx[3][1]=LoadGraph("zonb.png");
		
	}

	//—N‚«êŠ
	int y[2];
	int sporn_time;
	//“G‚Ì‰æ‘œ
	//0`3‚¨‰»‚¯
	//4ƒ]ƒ“ƒr
	int gfx[4][12];
	int zomb;
	int textureGraph;

	float speed;
	t2k::vec3 pos;
	//‰æ‘œ•\¦
	int ix;
	int iy;
	int gfx_now;
	int ycount;
	int xcount;

	//“G‚Ì‰æ‘œ
	int enemy_posY;
	int enemy_type;
	//“G‚Ì‹““®
	int enemy_now;

	bool life;


	bool enemy_flg;
	//ƒƒ“ƒoŠÖ”
	void move();
	void Draw();

	void All();
	Gamemanager* gmptr=nullptr;
	Player* playerPtr = nullptr;
};



