#include "DxLib.h"
#include "game_main.h"
#include "../support/Support.h"
#include <time.h>
#include <math.h>
#include"player.h"
#include"Enemy.h"
#include"GM.h"
#include"Bullet.h"

#define SAFE_DELETE(p){\
if(nullptr!=p){\
delete p;\
p=nullptr;\
}\
}

int frame = 10;
//最終的の無くす部分
Gamemanager*gm = nullptr;
bool init = false;
Player *player = nullptr;
Enemy *enemy = nullptr;
const int Bullet_NUM=10;
Bullet*bullet[Bullet_NUM];
Bullet*siken;
const float PI = 3.1415f;
//=============================================================================
// name... game_main
// work... ゲームのメインループ
// arg.... none
// ret.... [ 正常終了 : 0 ]
//=============================================================================
int game_main()
{
	/*
	float angle = 2 * DX_PI_F;
	float angleB = 2*PI;*/
	//初期化


	if (init == false) {
		//siken = new Bullet();
		gm = new Gamemanager();
		player = new Player();
		enemy = new Enemy(player,gm);
		player->enemyPtr = enemy;
		memset(bullet, 0,sizeof(bullet));
		init = true;
	}

	//弾の生成
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		if (frame % 10 == 0) {
			for (int i = 0; i < Bullet_NUM; i++) {
				if (nullptr == bullet[i]) {
					bullet[i] = new Bullet(player->pos);
					break;
				}
			}
		}
		frame++;
	}
	else {
		frame = 0;
	}



	for (int i = 0; i < Bullet_NUM; i++) {
		if (nullptr != bullet[i]) {
			bullet[i]->Move();

			if ( 800< bullet[i]->pos.x) {
				SAFE_DELETE(bullet[i]);
			}
		}
	}


	//仮の塗りつぶし
	DrawBox(0, 0, 1400, 150, GetColor(0, 255, 0), true);
	DrawBox(700, 100,900, 1000, GetColor(255, 255, 0), true);

	player->All();
	enemy->All();



	//DrawGraph(200, 200, siken->gfx, true);
	return 0 ;

}

