#include"Bullet.h"

void Bullet::Move() {
	t2k::vec3 move;
	move = t2k::vec3(1, 0, 0);
	t2k::vec3Normalize(move);
	pos += (move*speed);
	DrawGraph(pos.x, pos.y, gfx, true);
}
void Bullet::Draw() {
	if (bullet > 0) {
		
	}
	else if (bullet < 0) {

	}
}
void Bullet::All() {
	Move();
	Draw();
}