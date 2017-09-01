#pragma once
#include"DxLib.h"
#include"../support/vec3.h"
#include"GM.h"
#include"player.h"
#include"Enemy.h"
class Player;
class Gamemanager;
class Bullet {	
public:
	Bullet(){}
	Bullet(t2k::vec3 init_pos, Gamemanager*gm,Player*player,Enemy*enemy) {		
		//初期弾数
		em = enemy;
		gmptr = gm;
		GetMousePoint(&gmptr->mx, &gmptr->my);
		t2k::vec3 mousePos(gmptr->mx,gmptr->my, 0);
		move =t2k::vec3Normalize(init_pos-mousePos)*-1;
		bullet = 15;
		//弾のスピード
		speed = 5;
		pos = init_pos;
		gfx=LoadGraph("tama.png");


	}
	~Bullet() {
		DeleteGraph(gfx);
	}
	//メンバ関数
	int gfx;
	t2k::vec3 move;
	float speed;
	t2k::vec3 pos;
	//弾数
	int bullet;
	void All();
	void draw();
	void Move();
	void HAN();
	Gamemanager *gmptr=nullptr;
	Player*player = nullptr;
	Enemy*em = nullptr;
};