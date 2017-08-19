#pragma once
#include"DxLib.h"
#include"../support/vec3.h"

class Bullet {	
public:
	Bullet(){}
	Bullet(t2k::vec3 init_pos) {
		//�����e��


		bullet = 10;
		//�e�̃X�s�[�h
		speed = 10;
		pos = init_pos;
		//�e�̉摜
		gfx=LoadGraph("tama.png");
	}
	~Bullet() {
		DeleteGraph(gfx);
	}
	//�����o�֐�
	int gfx;
	float speed;
	t2k::vec3 pos;

	//�e��
	int bullet;

	void Move();
	void Draw();
	void All();
};