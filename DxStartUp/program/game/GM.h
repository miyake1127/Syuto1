#pragma once
#include"DxLib.h"

class Gamemanager {
public:
	Gamemanager() {
		
		enemy_type = 0;
		enemy_now = 0;
	}
	static Gamemanager*getInstanse();
	//�G�̉摜
	int enemy_type;
	//�G�̋���
	int enemy_now;
	//��
	int wall;
};