#include"Enemy.h"
#include"DxLib.h"
#include"player.h"
#include"GM.h"
void Enemy::move() {


	//�����������
	auto playerPos = playerPtr->pos;
	auto enemyPos = pos;
	//���̕���
	auto sub = playerPos - enemyPos;
	auto direction = t2k::vec3Normalize(sub);
	pos += direction * speed;

	
}

void Enemy::Draw(){

	if (life==true) {
		DrawGraph(pos.x,pos.y ,gfx[gmptr->enemy_type][gmptr->enemy_now], true);
	}
}

void Enemy::All() {
	move();
	Draw();
}