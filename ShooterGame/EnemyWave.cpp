
/*
* 波の動作をする敵の処理関数
*/

#include"Enemy.h"
#include"event.h"
#include"player.h"
#include<math.h>

////動き出しカウントを１ずつ増やす
//int moveCounter = 0;

//波の動作をする敵の画像読み込み関数
void LoadEnemyWave(Enemy& eWave)
{
	//平常時画像読み込み
	eWave.object.graph = LoadGraph("img/enemyTako.png");

	//ダメージ画像読み込み
	eWave.damagedGraph = LoadGraph("img/enemyDamagedTako.png");
}

//波の動作をする敵の初期関数
void InitEnemyWave(Enemy& eWave)
{
	//敵の表示フラグをオフにする
	eWave.graphFlag = true;

	//敵のダメージフラグをオフにする
	eWave.damagedFlag = false;

	//敵の平常時画像サイズを読み込む
	GetGraphSize(eWave.object.graph, &eWave.object.w, &eWave.object.h);

	//敵のダメージ画像サイズを読み込む
	GetGraphSize(eWave.damagedGraph, &eWave.object.w, &eWave.object.h);

	//ラジアン変数を０にする
	eWave.rad = 0;

	////敵の動き出しカウントを０にする
	//eWave.moveCounter = 0;

	//敵の座標の初期設定
	eWave.object.x = (SCREEN_W * 3) + (SCREEN_W / 2);
	eWave.object.y = SCREEN_H / 2;

}

//波の動作をする敵のアップデート関数
void UpdateEnemyWave(Enemy& eWave, Player& player, int& remainP)
{
	//平常時フラグかダメージフラグがオンの時に移動処理を行う
	if (eWave.graphFlag == true || eWave.damagedFlag == true)
	{
		//敵の移動処理
		eWave.object.x -= ENEMY_WAVE_SPEED;

		eWave.rad += 0.03f;

		eWave.object.y += cos(eWave.rad) * ENEMY_WAVE_SPEED;

		//波の動作をとする敵本体と自機本体の当たり判定
		if (CollisionSmallRect(eWave.object, player.object, player.hitFlag))
		{
			//自機のダメージフラグをオンにする
			player.damagedFlag = true;

			//自機の平常時表示フラグをオフにする
			player.graphFlag = false;

			//自機の残機の処理を行う
			UpdateRemainPlayer(remainP);

			//自機のダメージカウントを０にする
			player.damagedCount = 0;

			//自機の当たり判定フラグをオフにする
			player.hitFlag = false;

		}
	}
}

//波の動作をする敵の描画関数
void DrawEnemyWave(Enemy& eWave)
{
	//敵の平常時表示フラグがオンの時にダメージフラグをオフにして平常時画像を描画する
	if (eWave.graphFlag == true)
	{
		DrawGraph((int)eWave.object.x, (int)eWave.object.y, eWave.object.graph, true);
	}

	//敵のダメージフラグがオンの時平常時表示フラグをオフにしてダメージ表示カウントを１ずつ増やす
	if (eWave.damagedFlag == true)
	{
		eWave.graphFlag = false;

		++eWave.drawDamagedCounter;

		DrawGraph((int)eWave.object.x, (int)eWave.object.y, eWave.damagedGraph, true);

		//敵のダメージ表示カウントが15以上のときダメージフラグをオフにしてダメージ表示カウントを０にする
		if (eWave.drawDamagedCounter >= ENEMY_DRAW_DAMAGED_COUNTER)
		{
			eWave.graphFlag = false;
			eWave.damagedFlag = false;
			eWave.drawDamagedCounter = 0;
		}

	}
}