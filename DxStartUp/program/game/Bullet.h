#pragma once
#include"DxLib.h"
#include"../support/vec3.h"

class Bullet {	
public:
	Bullet(){}
	Bullet(t2k::vec3 init_pos) {
		//初期弾数


		bullet = 10;
		//弾のスピード
		speed = 10;
		pos = init_pos;
		//弾の画像
		gfx=LoadGraph("tama.png");
	}
	~Bullet() {
		DeleteGraph(gfx);
	}
	//メンバ関数
	int gfx;
	float speed;
	t2k::vec3 pos;

	//弾数
	int bullet;

	void Move();
	void Draw();
	void All();
};