#include"player.h"
#include"DxLib.h"
#include"../support/vec3.h"
#include "Enemy.h"


void Player::move() {

	t2k::vec3 move;
	// 移動
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		move.x = -1.0f;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		move.x = 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		move.y = -1.0f;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		move.y = 1.0f;
	}

	t2k::vec3Normalize(move);
	pos += (move * speed);
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT)) {
		if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_DOWN)) {
			move.x = 0.71f;
			move.y = 0.71f;
		}
	}

	

		

	if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
		
		if (xcount>0)
				
			xcount = 0;
		
			--xcount;
	}

		
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
				if (xcount<0)
					xcount = 0;
				++xcount;
			
		}

		if (CheckHitKey(KEY_INPUT_UP) == 1) {
				if (ycount>0)
					ycount = 0;
				--ycount;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
				if (ycount<0)
					ycount = 0;
				++ycount;
		}
	
	
	ix = abs(xcount) % 30 / 10;
	iy = abs(ycount) % 30 / 10;
	//画像ハンドルX軸
	if (xcount > 0) {
		ix += 3;
		gfx_now = ix;
	}
	if (xcount < 0) {
		ix += 9;
		gfx_now = ix;
	}
	//画像ハンドルY軸
	if (ycount > 0) {
		iy += 6;
		gfx_now = iy;
	}
	if (ycount < 0) {
		iy += 0;
		gfx_now = iy;
	}

	if (CheckHitKey(KEY_INPUT_UP) != 1 && CheckHitKey(KEY_INPUT_DOWN) != 1) {
		ycount = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) != 1 && CheckHitKey(KEY_INPUT_LEFT) != 1) {
		xcount = 0;
	}
	if (move.x == 0.71f&& move.y == 0.71f)
		gfx_now = ix;
	if (pos.y >= takasa) {
		pos.y = takasa;
	}
	if (pos.x >= haba) {
		pos.x = haba;
	}
	if (pos.y <= 0) {
		pos.y = 0;
	}
	if (pos.x <= 0) {
		pos.x = 0;
	}
}

void Player::Draw()
{
	//表示
	if (life=true) {
		DrawRotaGraph(pos.x, pos.y , 1.0,0,gfx[gfx_now], true);
	}
}
void Player::All() {
	move();
	Draw();
}