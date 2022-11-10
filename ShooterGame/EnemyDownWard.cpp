
/*
* 下向きの固定敵の処理関数
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"

//下向きの固定敵の画像読み込み関数
void LoadEnemyDownWard(Enemy& eDownWard)
{
	//敵の画像読み込み
	eDownWard.object.graph = LoadGraph("img/enemyIka.png");

	//ダメージ画像読み込み
	eDownWard.damagedGraph = LoadGraph("img/enemyDamagedIka.png");
}

//下向きの固定敵の初期関数
void InitEnemyDownWard(Enemy& eDownWard, int forSize)
{
	//敵の平常の表示フラグをオンにする
	eDownWard.graphFlag = true;

	//敵のダメージフラグをオフにする
	eDownWard.damagedFlag = false;

	//ダメージ画像表示カウント
	eDownWard.drawDamagedCounter = 0;

	//敵の画像サイズを読み込む
	GetGraphSize(eDownWard.object.graph, &eDownWard.object.w, &eDownWard.object.h);

	//敵のダメージ画像サイズを読み込む
	GetGraphSize(eDownWard.damagedGraph, &eDownWard.object.w, &eDownWard.object.h);

	//敵の座標の初期設定
	eDownWard.object.x = (float)(SCREEN_W + 100 + eDownWard.object.w * forSize);
	eDownWard.object.y = 20.0f;
}

//下向きの固定敵のアップデート関数
void UpdateEnemyDownWard(Enemy& eDownWard, Player& player, int& remainP)
{
	//敵の表示フラグまたはダメージフラグがオンの時
	if (eDownWard.graphFlag == true || eDownWard.damagedFlag == true)
	{
		//移動処理
		eDownWard.object.x -= MAP_SCREEN_SPEEDX;

		//敵本体と自機本体の当たり判定
		if (CollisionSmallRect(eDownWard.object, player.object, player.hitFlag))
		{
			//自機のダメージフラグをオンにする
			player.damagedFlag = true;

			//自機の平常時フラグをオフにする
			player.graphFlag = false;

			//自機のダメージを受けるまでのフレームカウントを０にする
			player.damagedCount = 0;

			//自機の当たり判定フラグをオフにする
			player.hitFlag = false;

			//自機の残機のアップデート関数を呼び出す
			UpdateRemainPlayer(remainP);
		}
	}
}

//下向きの固定敵の描画関数
void DrawEnemyDownWard(Enemy& eDownWard)
{
	//敵の表示フラグがオンの時平常時画像を描画する
	if (eDownWard.graphFlag == true)
	{
		DrawGraph((int)eDownWard.object.x, (int)eDownWard.object.y, eDownWard.object.graph, true);
	}

	//敵のダメージフラグをオンの時平常時表示フラグをオフにしてダメージ表示カウントを１ずつ増やす
	if (eDownWard.damagedFlag == true)
	{
		eDownWard.graphFlag = false;

		++eDownWard.drawDamagedCounter;

		//ダメージ画像を描画する
		DrawGraph((int)eDownWard.object.x, (int)eDownWard.object.y, eDownWard.damagedGraph, true);

		//敵のダメージ表示カウントが１５以上の時ダメージフラグをオフにしてダメージ表示カウントを０にする
		if (eDownWard.drawDamagedCounter >= ENEMY_DRAW_DAMAGED_COUNTER)
		{
			eDownWard.damagedFlag = false;
			eDownWard.drawDamagedCounter = 0;
		}
	}
}
