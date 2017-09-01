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
	
	//�����蔻��
	if ((playerPtr->pos.x- pos.x) *(playerPtr->pos.x - pos.x)+ (playerPtr->pos.y - pos.y) *(playerPtr->pos.y - pos.y) <= (20 + 20)*(20 + 20)) {
		playerPtr->HP -= 1;
	}
	//�|�W�V����
	
}

void Enemy::Draw(){
	//DrawRotaGraph(pos.x, pos.y , 1.0,0,gfx[gfx_now], true);
	//���ە\������
	if (life==true) {
		DrawRotaGraph(pos.x, pos.y, 1.0, 0, gfx[enemy_type][enemy_now], true);
		//DrawGraph(pos.x,pos.y ,gfx[enemy_type][enemy_now], true);
	}
	else {
		DeleteGraph(gfx[enemy_type][enemy_now]);
	}

}

void Enemy::All() {
	move();
	Draw();
}