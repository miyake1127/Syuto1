#include"GM.h"
#include"DxLib.h"



void Gamemanager::Draw(){
	DrawGraph(0, 0, gfx,false);
	DrawGraph(0, 280, zimen, true);
}


Gamemanager manager;
Gamemanager*Gamemanager::getInstanse() {
	static Gamemanager*Instance = nullptr;
	if (nullptr == Instance) {
		Instance = new Gamemanager();
	}
	return Instance;
}

