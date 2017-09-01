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


int nasu= 0;
int kill;
int scene;
int frame = 10;
//�ŏI�I�̖���������
Gamemanager*gm = nullptr;
bool init = false;
Player *player = nullptr;


const int enemy_num=4;
Enemy*enemy[enemy_num];
const int Bullet_NUM=5;
Bullet*bullet[Bullet_NUM];
//=============================================================================
// name... game_main
// work... �Q�[���̃��C�����[�v
// arg.... none
// ret.... [ ����I�� : 0 ]
//=============================================================================
int game_main()
{
	//������
	ClearDrawScreen();
	if (init == false) {
		SetDrawScreen(DX_SCREEN_BACK);
		gm = new Gamemanager();
		player = new Player();
		kill = 0;
		memset(bullet, 0, sizeof(bullet));
		memset(enemy, 0, sizeof(enemy));
		init = true;
		
	}


	gm->Draw();

	//�e�̐���
	if (GetMouseInput()&MOUSE_INPUT_LEFT) {
		if (frame % 10 == 0) {
			for (int i = 0; i < Bullet_NUM; i++) {
				if (nullptr == bullet[i]) {
					bullet[i] = new Bullet(player->pos, gm, player, enemy[enemy_num]);
					break;
				}
			}
		}
		frame++;
	}
	else {
		frame = 0;
	}

	//�e�̔���
	for (int p = 0; p < enemy_num; p++) {
		for (int i = 0; i < Bullet_NUM; i++) {
			if (nullptr != bullet[i]) {
				bullet[i]->All();

				//��ʊO�ɏo����ʏ���
				if (1240 < bullet[i]->pos.x || 0 > bullet[i]->pos.x ||
					768 < bullet[i]->pos.y || 0 > bullet[i]->pos.y) {
					SAFE_DELETE(bullet[i]);
				}
			}
		}
	}
/////////�e///
	
///////////
///////////////�G�̏���/////////////////////////////////////////////////////////////////////////
	

	nasu += 1;
		if (nasu % 50== 0) {

		for (int i=0; i < enemy_num; i++) {

			if (enemy[i] == nullptr) {
				enemy[i] = new Enemy(player,gm);
				enemy[i]->enemy_flg = true;
				break;
			}
							}


			}
		for (int i = 0; i < enemy_num; i++) {


			if (enemy[i]!=nullptr) {
				enemy[i]->All();
				if (enemy[i]->life == false) {
					SAFE_DELETE(enemy[i]);
					kill += 1;				}
			}
		}

	
	

	

		for (int i = 0; i < Bullet_NUM; i++) {
			
				for (int p = 0; p < enemy_num; p++) {
					if (enemy[p]&&bullet[i]!=nullptr) {
						if (((enemy[p]->pos.x - bullet[i]->pos.x) *(enemy[p]->pos.x - bullet[i]->pos.x)) + ((enemy[p]->pos.y - bullet[i]->pos.y) * (enemy[p]->pos.y - bullet[i]->pos.y)) <= (20 + 20)*(20 + 20)) {
							enemy[p]->life = false;
							if (enemy[p]->life == false) {
								SAFE_DELETE(bullet[i]);
							}
						}
					}
			}
		}
////////////////////////////////////////////////////////////////////////////////////////////
		int x = player->pos.x;
		int y = player->pos.y;


		player->All();

		DrawStringEx(300, 50, 0xfffffff, "playerY=%d", y);
		DrawStringEx(100, 50, 0xfffffff, "playerX=%d", x);
		DrawStringEx(500, 50, 0xfffffff, "kill=%d", kill);
		ScreenFlip() ;   
		return 0;

	}

