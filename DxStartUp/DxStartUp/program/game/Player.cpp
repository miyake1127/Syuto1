#include"player.h"
#include"DxLib.h"
#include"../support/vec3.h"
#include "Enemy.h"
#include"../support/Support.h"


void Player::move() {

	t2k::vec3 move;
	// 移動
	if (CheckHitKey(KEY_INPUT_A)) {
		move.x = -1.0f;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		move.x = 1.0f;
	}

	t2k::vec3Normalize(move);
	pos += (move * speed);
	//斜め時の処理
	if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_D)) {
		if (CheckHitKey(KEY_INPUT_W) || CheckHitKey(KEY_INPUT_S)) {
			move.x = 0.71f;
			move.y = 0.71f;
		}
	}	
	if (CheckHitKey(KEY_INPUT_A) == 1) {
		if (xcount>0)
			xcount = 0;		
			--xcount;
	}	
		if (CheckHitKey(KEY_INPUT_D) == 1) {
				if (xcount<0)
					xcount = 0;
				++xcount;
			
		}

		if (CheckHitKey(KEY_INPUT_W) == 1) {
				if (ycount>0)
					ycount = 0;
				--ycount;
		}
		if (CheckHitKey(KEY_INPUT_S) == 1) {
				if (ycount<0)
					ycount = 0;
				++ycount;
		}
	
	
	ix = abs(xcount) % 30 / 10;
	iy = abs(ycount) % 30 / 10;


	//ジャンプ処理
	if (IsKeyDownTrigger(KEY_INPUT_SPACE)&&jump_flg==false) {
		jump_flg = true;
	}
	if (jump_flg != false) {
		pos.y -= 4;
	}
	if (pos.y <=680) {
		jump_flg = false;
	}
	if (jump_flg == false && pos.y != 734) {
		pos.y +=4;
	}





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

	if (CheckHitKey(KEY_INPUT_W) != 1 && CheckHitKey(KEY_INPUT_S) != 1) {
		ycount = 0;
	}
	if (CheckHitKey(KEY_INPUT_D) != 1 && CheckHitKey(KEY_INPUT_A) != 1) {
		xcount = 0;
	}
	if (move.x == 0.71f&& move.y == 0.71f)
		gfx_now = ix;


	if (pos.y >= 734) {
		pos.y = 734;
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
	if (HP>=50) {
		DrawRotaGraph(pos.x, pos.y , 1.0,0,gfx[gfx_now], true);
	}
	else if (HP <= 50) {
		DeleteGraph(gfx[gfx_now]);
	}
	//HPバー
	//枠
	DrawBox(50,20,150,40, GetColor(0, 0, 255),false);
	//中i
	if (HP >= 50) {
		DrawBox(50, 20, HP, 40, GetColor(255, 40, 75), true);
	}
	DrawGraph(20, 15, HP_gfx, true);
	
}
void Player::All() {
	move();
	Draw();
}