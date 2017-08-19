#include"GM.h"

Gamemanager manager;
Gamemanager*Gamemanager::getInstanse() {
	static Gamemanager*Instance = nullptr;
	if (nullptr == Instance) {
		Instance = new Gamemanager();
	}
	return Instance;
}
