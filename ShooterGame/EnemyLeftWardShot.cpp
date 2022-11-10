
/*
* 固定敵の弾の処理関数
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"

//左向きの固定敵の弾の画像読み込み関数
void LoadEnemyLeftShot(Enemy& eLeftWard)
{
	//敵の弾の画像読み込み
	eLeftWard.leftShot[0].object.graph = LoadGraph("img/LeftTakoShot.png");
}

//左向きの固定敵の弾の初期関数
void InitEnemyLeftShot(Enemy& eLeftWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//敵の弾の表示フラグをオフにする
		eLeftWard.leftShot[i].graphFlag = false;

		//敵の弾の画像サイズを読み込む
		GetGraphSize(eLeftWard.leftShot[0].object.graph, &eLeftWard.leftShot[i].object.w, &eLeftWard.leftShot[i].object.h);
	}

	//敵の弾を出すフレームカウントの初期化
	eLeftWard.leftShot[0].shotCounter = 0;
}


//左向きの固定敵の弾のアップデート関数
void UpdateEnemyLeftShot(Enemy& eLeftWard, Player& player, int& remainP)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//windowの画面内に入ってきたら弾を表示する
		if (eLeftWard.object.x >= 0 && eLeftWard.object.x <= SCREEN_W &&
			eLeftWard.object.y >= 0 && eLeftWard.object.y <= SCREEN_H)
		{
			//敵の弾のカウントを１ずつ増やす
			eLeftWard.leftShot[0].shotCounter++;

			//敵の弾のカウントが80フレーム以上の時
			if (eLeftWard.leftShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				//敵の表示フラグがオンの時
				if (eLeftWard.graphFlag == true)
				{
					//弾の表示フラグがオフの時初期位置を設定して表示フラグをオンにする
					if (eLeftWard.leftShot[i].graphFlag == false)
					{
						//敵の弾の座標の初期設定
						eLeftWard.leftShot[i].object.x = eLeftWard.object.x;
						eLeftWard.leftShot[i].object.y = (eLeftWard.object.h - eLeftWard.leftShot[0].object.h) / 2 + eLeftWard.object.y;

						eLeftWard.leftShot[i].graphFlag = true;

						//敵の弾のフレームカウントを０にする
						eLeftWard.leftShot[0].shotCounter = 0;
					}
				}
			}
		}

		//表示フラグがオンだった時の処理
		if (eLeftWard.leftShot[i].graphFlag == true)
		{
			//敵の弾の移動速度処理
			eLeftWard.leftShot[i].object.x -= ENEMY_SHOT_SPEEDX;

			//windowの左側から出たときに表示フラグをオフにする
			if (eLeftWard.leftShot[i].object.x < 0)
			{
				eLeftWard.leftShot[i].graphFlag = false;
			}

			//自機の表示フラグがオンの時
			if (player.graphFlag == true)
			{
				//敵の弾と自機の当たり判定処理
				if (CollisionSmallRect(player.object, eLeftWard.leftShot[i].object, player.hitFlag))
				{
					//敵の弾の表示フラグをオフにする
					eLeftWard.leftShot[i].graphFlag = false;

					//自機のダメージフラグをオンにする
					player.damagedFlag = true;

					//自機の表示フラグをオフにする
					player.graphFlag = false;

					//自機の残機の処理を行う
					UpdateRemainPlayer(remainP);

				}
			}
		}
	}
}

//左向きの固定敵の弾の描画関数
void DrawEnemyLeftShot(const Enemy& eLeftWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//敵の弾の表示フラグがオンの時に描画する
		if (eLeftWard.leftShot[i].graphFlag == true)
		{
			DrawGraph((int)eLeftWard.leftShot[i].object.x, (int)eLeftWard.leftShot[i].object.y, eLeftWard.leftShot[0].object.graph, true);
		}
	}
}
