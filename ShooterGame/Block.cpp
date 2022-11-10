
/*
* ブロックの処理関数
*/

#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include"Event.h"

//ブロックの初期関数
void InitBlock(Block* block, int blockNum, int graph, float x, float y, int w, int h)
{
	//ブロックの配列に座標を読み込む
	block[blockNum].object.x = x;
	block[blockNum].object.y = y;

	//ブロックの配列にサイズを読み込む
	block[blockNum].object.w = w;
	block[blockNum].object.h = h;

	//ブロックの配列に画像を読み込む
	block[blockNum].object.graph = graph;

}

//ブロックのアップデート関数
void UpdateBlock(Block* block, Map& map, Enemy* eLeftWard, Enemy* eDownWard,
	Enemy* eWave, Player& player, int& remainP)
{
	for (int i = 0; i < map.blockCounter; i++)
	{
		//マップチップが右端に来るまでスクロールさせる
		if (block[0].object.x >= -(SCREEN_W * MAP_SCROLL_MAX - SCREEN_W) && map.mapChipMoveFlag == true)
		{
			block[i].object.x -= MAP_SCREEN_SPEEDX;
		}
		else
		{
			map.mapChipMoveFlag = false;
		}

		if (CollisionRect(player.object, block[i].object))
		{
			//ブロックの上部分とぶつかった
			if (((player.object.y + player.object.h) - block[i].object.y > 0) &&
				((player.object.y + player.object.h) - block[i].object.y <=
					MAX_OVERLAP_CAPACITY) && player.object.vy > 0.0f)
			{
				player.object.y = block[i].object.y - player.object.h;
			}

			//ブロックの下部分とぶつかった
			if ((block[i].object.y + block[i].object.h) - player.object.y <=
				MAX_OVERLAP_CAPACITY && player.object.vy > 0.0f)
			{
				player.object.y = block[i].object.y + block[i].object.h;
			}

			//ブロックの左部分とぶつかった
			if ((player.object.x + player.object.w) - block[i].object.x <
				MAX_OVERLAP_CAPACITY && player.object.vx > 0.0f)
			{
				player.object.x = block[i].object.x - player.object.w;

				player.crushFlag = true;
			}

			//ブロックの右側とぶつかった
			if ((block[i].object.x + block[i].object.w) - player.object.x <
				MAX_OVERLAP_CAPACITY && player.object.vx > 0.0f)
			{
				player.object.x = block[i].object.x + block[i].object.w;
			}
		}

		HitPlayerShot(block[i], player);

		for (int j = 0; j < ENEMY_LEFT_WARD_MAX; j++)
		{
			HitEnemyLeftWardShot(block[i], eLeftWard[j]);
		}

		for (int j = 0; j < ENEMY_DOWN_WARD_MAX; j++)
		{
			HitEnemyDownWardShot(block[i], eDownWard[j]);
		}

		for (int j = 0; j < ENEMY_WAVE_MAX; j++)
		{
			HitEnemyWaveShot(block[i], eWave[j]);
		}
	}
}

//自機の弾とブロックの当たり判定関数
void HitPlayerShot(Block& block, Player& player)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, player.playerShot[i].object))
		{
			player.playerShot[i].graphFlag = false;
		}
	}
}

//左向きの固定敵の弾とブロックの当たり判定関数
void HitEnemyLeftWardShot(Block& block, Enemy& eLeftWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, eLeftWard.leftShot[i].object))
		{
			eLeftWard.leftShot[i].graphFlag = false;
		}
	}
}

//下向きの固定敵の弾とブロックの当たり判定関数
void HitEnemyDownWardShot(Block& block, Enemy& eDownWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, eDownWard.downShot[i].object))
		{
			eDownWard.downShot[i].graphFlag = false;
		}
	}
}

//波の動作をする敵の弾とブロックの当たり判定関数
void HitEnemyWaveShot(Block& block, Enemy& eWave)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, eWave.waveShot[i].object))
		{
			eWave.waveShot[i].graphFlag = false;
		}
	}
}

//ボスの弾とブロックの当たり判定関数
void HitBossShot(Block& block, Enemy& boss)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, boss.bossFirstShot[i].object))
		{
			boss.bossFirstShot[i].graphFlag = false;
		}

		if (CollisionRect(block.object, boss.bossSecondShot[i].object))
		{
			boss.bossSecondShot[i].graphFlag = false;
		}
	}
}

//ブロックの描画関数
void DrawBlock(const Block* block, const int blockNum)
{
	//ブロックの描画をする
	DrawGraph((int)block[blockNum].object.x, (int)block[blockNum].object.y, block[blockNum].object.graph, true);
}