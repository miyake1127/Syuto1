#include"Bullet.h"
#include"DxLib.h"
#include"../support/Support.h"




void Bullet::Move() {
	pos += (move*speed);
	
	
}
void Bullet::HAN() {
	
	
}

void Bullet::draw() {
	DrawGraph(pos.x, pos.y, gfx, true);
}

void Bullet::All() {
	Move();
	draw();

}