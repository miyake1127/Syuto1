#include"Enemy.h"
#include"DxLib.h"
#include"player.h"
#include"GM.h"
void Enemy::move() {


	//教わった部分
	auto playerPos = playerPtr->pos;
	auto enemyPos = pos;
	//差の部分
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