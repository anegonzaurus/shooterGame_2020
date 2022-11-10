
/*
* 左向きの固定敵の処理関数
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"

//左向きの固定敵の画像読み込み関数
void LoadEnemyLeftWard(Enemy& eLeftWard)
{
	//敵の画像読み込み
	eLeftWard.object.graph = LoadGraph("img/enemyTako.png");

	//敵のダメージ画像読み込み
	eLeftWard.damagedGraph = LoadGraph("img/enemyDamagedTako.png");

}

//左向きの固定敵の初期関数
void InitEnemyLeftWard(Enemy& eLeftWard, int forSize)
{
	//敵の平常の表示フラグをオフにする
	eLeftWard.graphFlag = true;

	//敵のダメージフラグをオフにする
	eLeftWard.damagedFlag = false;

	//ダメージ画像表示カウント
	eLeftWard.drawDamagedCounter = 0;

	//敵の画像サイズを読み込む
	GetGraphSize(eLeftWard.object.graph, &eLeftWard.object.w, &eLeftWard.object.h);

	//敵のダメージ画像サイズを読み込む
	GetGraphSize(eLeftWard.damagedGraph, &eLeftWard.object.w, &eLeftWard.object.h);

	//敵の座標の初期設定
	eLeftWard.object.x = SCREEN_W;
	eLeftWard.object.y = (float)(200 + eLeftWard.object.h * forSize);
}


//左向きの固定敵のアップデート関数
void UpdateEnemyLeftWard(Enemy& eLeftWard, Player& player, int& remainP)
{
	//敵の表示フラグまたはダメージフラグがオンの時
	if (eLeftWard.graphFlag == true || eLeftWard.damagedFlag == true)
	{
		//移動処理
		eLeftWard.object.x -= MAP_SCREEN_SPEEDX;

		//敵本体と自機本体の当たり判定
		if (CollisionSmallRect(eLeftWard.object, player.object, player.hitFlag))
		{
			//自機のダメージフラグをオンにする
			player.damagedFlag = true;

			//自機の平常時フラグをオフにする
			player.graphFlag = false;

			//自機の残機の処理を行う
			UpdateRemainPlayer(remainP);

			//自機のダメージを受けるまでのフレームカウントを０にする
			player.damagedCount = 0;

			//自機の当たり判定フラグをオフにする
			player.hitFlag = false;
		}
	}
}


//左向きの固定敵の描画関数
void DrawEnemyLeftWard(Enemy& eLeftWard)
{
	//敵の表示フラグがオンの時画像を描画する
	if (eLeftWard.graphFlag == true)
	{
		DrawGraph((int)eLeftWard.object.x, (int)eLeftWard.object.y, eLeftWard.object.graph, true);
	}

	//ダメージを受けたときはDamageFlagをオンにして普通の表示フラグをオフにしてダメージ表示カウントを数える
	if (eLeftWard.damagedFlag == true)
	{
		eLeftWard.graphFlag = false;

		++eLeftWard.drawDamagedCounter;

		//ダメージ画像を描画する
		DrawGraph((int)eLeftWard.object.x, (int)eLeftWard.object.y, eLeftWard.damagedGraph, true);

		//敵のダメージカウントが１５以上の時ダメージフラグをオフにしてダメージカウントを０にする
		if (eLeftWard.drawDamagedCounter >= ENEMY_DRAW_DAMAGED_COUNTER)
		{
			eLeftWard.graphFlag = false;
			eLeftWard.damagedFlag = false;
			eLeftWard.drawDamagedCounter = 0;
		}
	}
}
