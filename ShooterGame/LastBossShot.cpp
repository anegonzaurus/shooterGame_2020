
/*
*ラスボスの弾の関数 
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"
#include"Map.h"

//ラスボスの弾の画像読み込み関数
void LoadBossShot(Enemy& boss)
{
	//弾1の画像を読み込む
	boss.bossFirstShot[0].object.graph = LoadGraph("img/LeftTakoShot.png");

	//弾２の画像を読み込む
	boss.bossSecondShot[0].object.graph = LoadGraph("img/ikaShot.png");
}

//ラスボスの弾の初期関数
void InitBossShot(Enemy& boss)
{
	//ボスの弾の数分for文を回す
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		/*
		*ボスの弾１の初期化
		*/
		//弾1の表示フラグをオフにする
		boss.bossFirstShot[i].graphFlag = false;

		//弾1の画像サイズを読み込む
		GetGraphSize(boss.bossFirstShot[0].object.graph, &boss.bossFirstShot[i].object.w, &boss.bossFirstShot[i].object.h);

		//弾1の移動速度変数を設定
		boss.bossFirstShot[i].object.vx = ENEMY_SHOT_SPEEDX;
		boss.bossFirstShot[i].object.vy = BOSS_MOVE_SHOT;

		/*
		*ボスの弾２の初期化
		*/
		//弾２の表示フラグがオフする
		boss.bossSecondShot[i].graphFlag = false;

		//弾2の画像サイズを読み込む
		GetGraphSize(boss.bossSecondShot[0].object.graph, &boss.bossSecondShot[i].object.h, &boss.bossSecondShot[i].object.h);

		//弾2の移動速度変数を設定
		boss.bossSecondShot[i].object.vx = ENEMY_SHOT_SPEEDX;
		boss.bossSecondShot[i].object.vy = BOSS_MOVE_SHOT;
	}

	//ボスの弾1を出すフレームカウントの初期化
	boss.bossFirstShot[0].shotCounter = 0;

	//ボスの弾２を出すフレームカウントの初期化
	boss.bossSecondShot[0].shotCounter = 0;
}

//ラスボスの弾のアップデート関数
void UpdateBossShot(Enemy& boss, const Map& map, Player& player, int& remainP)
{
	//ボスの弾の数分for文を回す
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//マップチップの移動フラグがオフになったとき
		if (map.mapChipMoveFlag == false)
		{
			//それぞれの弾の発射カウントを1ずつ増やす
			boss.bossFirstShot[0].shotCounter++;
			boss.bossSecondShot[0].shotCounter++;

			//弾１の発射カウントが80フレーム以上のとき
			if (boss.bossFirstShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				//弾1の座標の初期設定
				boss.bossFirstShot[i].object.x = boss.object.x;
				boss.bossFirstShot[i].object.y = boss.object.y + (boss.bossFirstShot[i].object.vy * i);

				//もしボスより上に座標が設定、またはボスより下に座標が設定されたとき移動の方向を反転する
				if (boss.bossFirstShot[i].object.y <= boss.object.y ||
					(boss.bossFirstShot[i].object.y + boss.bossFirstShot[i].object.h) >= (boss.object.y + boss.object.h))
				{
					boss.bossFirstShot[i].object.vy *= -1;
				}

				//弾１の表示フラグをオンにする
				boss.bossFirstShot[i].graphFlag = true;

				//弾1の発射カウントを０にする
				boss.bossFirstShot[0].shotCounter = 0;
			}
			
			if (boss.bossSecondShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				boss.bossSecondShot[i].object.x = boss.object.x;
				boss.bossSecondShot[i].object.y = (boss.object.y + boss.object.h) - (boss.bossSecondShot[i].object.vy * i);

				if (boss.bossSecondShot[i].object.y <= boss.object.y ||
					(boss.bossSecondShot[i].object.y + boss.bossSecondShot[i].object.h) >= (boss.object.y + boss.object.h))
				{
					boss.bossSecondShot[i].object.vy *= -1;
				}

				boss.bossSecondShot[i].graphFlag = true;

				boss.bossSecondShot[0].shotCounter = 0;
			}

		}

		//ボスの弾１の表示フラグがオンだった時の処理
		if (boss.bossFirstShot[i].graphFlag == true)
		{
			boss.bossFirstShot[i].object.x -= boss.bossFirstShot[i].object.vx;

			if (boss.bossFirstShot[i].object.x < 0)
			{
				boss.bossFirstShot[i].graphFlag = false;
			}

			if (player.graphFlag == true)
			{
				if (CollisionSmallRect(player.object, boss.bossFirstShot[i].object, player.hitFlag))
				{
					boss.bossFirstShot[i].graphFlag = false;

					player.damagedFlag = true;

					player.graphFlag = false;

					UpdateRemainPlayer(remainP);
				}
			}
		}
		
		//ボスの弾2の表示フラグがオンだった時の処理
		if (boss.bossSecondShot[i].graphFlag == true)
		{
			boss.bossSecondShot[i].object.x -= boss.bossSecondShot[i].object.vx;

			if (boss.bossSecondShot[i].object.x < 0)
			{
				boss.bossSecondShot[i].graphFlag = false;
			}

			if (player.graphFlag == true)
			{
				if (CollisionSmallRect(player.object, boss.object, player.hitFlag))
				{
					boss.bossSecondShot[i].graphFlag = false;

					player.damagedFlag = true;

					player.graphFlag = false;

					UpdateRemainPlayer(remainP);
				}
			}
		}
	}
}

//ラスボスの弾の描画関数
void DrawBossShot(const Enemy& boss)
{
	//ボスの弾の数分for文を回す
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (boss.bossFirstShot[i].graphFlag == true)
		{
			DrawGraph((int)boss.bossFirstShot[i].object.x, (int)boss.bossFirstShot[i].object.y, boss.bossFirstShot[0].object.graph, true);
		}

		if (boss.bossSecondShot[i].graphFlag == true)
		{
			DrawGraph((int)boss.bossSecondShot[i].object.x, (int)boss.bossSecondShot[i].object.y, boss.bossSecondShot[0].object.graph, true);
		}
	}
}