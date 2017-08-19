#pragma once
#include"DxLib.h"

class Gamemanager {
public:
	Gamemanager() {
		
		enemy_type = 0;
		enemy_now = 0;
	}
	static Gamemanager*getInstanse();
	//“G‚Ì‰æ‘œ
	int enemy_type;
	//“G‚Ì‹““®
	int enemy_now;
	//•Ç
	int wall;
};