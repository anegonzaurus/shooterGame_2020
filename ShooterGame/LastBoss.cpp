
/*
* ラスボスの処理関数
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"
#include"Map.h"

//ラスボスの画像読み込み関数
void LoadBoss(Enemy& boss)
{
	boss.object.graph = LoadGraph("img/Boss.png");

	boss.damagedGraph = LoadGraph("img/DamagedBoss.png");
}

//ラスボスの初期関数
void InitBoss(Enemy& boss)
{
	boss.graphFlag = true;

	boss.damagedFlag = false;

	boss.drawDamagedCounter = 0;

	boss.DieCounter = 0;

	//ラスボスの画像サイズを読み込む
	GetGraphSize(boss.object.graph, &boss.object.w, &boss.object.h);

	//ラスボスのダメージ画像サイズを読み込む
	GetGraphSize(boss.damagedGraph, &boss.object.w, &boss.object.h);

	//敵の座標の初期設定
	boss.object.x = 190 * MAP_CHIP_SIZE;
	boss.object.y = 2 * MAP_CHIP_SIZE;
}

//ラスボスのアップデート関数
void UpdateBoss(Enemy& boss, Map& map, Player& player, int& remainP)
{
	if (boss.graphFlag == true || boss.damagedFlag == true)
	{
		if (map.mapChipMoveFlag == true)
		{
			boss.object.x -= MAP_SCREEN_SPEEDX;
		}

		//自機本体とラスボス本体の当たり判定関数
		if (CollisionSmallRect(boss.object, player.object, player.hitFlag) && 
			map.mapChipMoveFlag == false)
		{
			player.damagedFlag = true;

			player.graphFlag = false;

			player.damagedCount = 0;

			player.hitFlag = false;

			UpdateRemainPlayer(remainP);
		}
	}
}

//ラスボスの描画関数
void DrawBoss(Enemy& boss)
{
	if (boss.graphFlag == true)
	{
		DrawGraph((int)boss.object.x, (int)boss.object.y, boss.object.graph, true);
	}

	if (boss.damagedFlag == true)
	{
		boss.graphFlag = false;

		++boss.drawDamagedCounter;

		//ダメージ画像を描画する
		DrawGraph((int)boss.object.x, (int)boss.object.y, boss.damagedGraph, true);

		if (boss.drawDamagedCounter >= BOSS_DRAW_DAMAGED_COUNTER)
		{
			boss.damagedFlag = false;

			boss.graphFlag = true;

			++boss.DieCounter;

			boss.drawDamagedCounter = 0;

			if (boss.DieCounter >= 25)
			{
				boss.graphFlag = false;
			}
		}
	}
}