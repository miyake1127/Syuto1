#pragma once
#include"../support/vec3.h"
#include"DxLib.h"
#include"player.h"
class Gamemanager;
class Enemy {
public:
	//����
	Enemy(Player* player,Gamemanager*gm) {
		playerPtr = player;
		//�N���ꏊ�̗���
		gmptr = gm;
		x = rand()%100;
		y = rand() % 100;
		//�摜��
		width = 29;
		height = 40;
		//��
		life = true;
		//����
		speed = 1;
		pos = t2k::vec3(x,y, 0);
		LoadDivGraph("pipo-halloweenchara2016_11.png", 12, 3, 4, 96 / 3, 128 / 4, gfx[0]);
		LoadDivGraph("teki2.png",12,3,4,96/3,128/4,gfx[1]);
		LoadDivGraph("teki3.png", 12, 3, 4, 96 / 3, 128 / 4, gfx[2]);
	}

	//�N���ꏊ
	int x;
	int y;

	//�摜��
	int width;
	int height;
	//�G�̉摜
	int gfx[3][12];
	int textureGraph;

	float speed;
	t2k::vec3 pos;

	//�摜�\��
	int ix;
	int iy;
	int gfx_now;
	int ycount;
	int xcount;

	int life;

	//�����o�֐�
	void move();
	void Draw();

	void All();
	Gamemanager* gmptr=nullptr;
	Player* playerPtr = nullptr;
};



