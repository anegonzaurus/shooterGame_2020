
/*
* 固定敵の弾の関数
*/

#include"Enemy.h"
#include"Event.h"
#include"Player.h"

//下向きの固定敵の弾の画像読み込み関数
void LoadEnemyDownShot(Enemy& eDownWard)
{
	//敵の弾の画像読み込み
	//黒の弾
	eDownWard.downShot[0].object.graph = LoadGraph("img/DownTakoShot.png");
	//白の弾
	eDownWard.downShot[1].object.graph = LoadGraph("img/WhiteShot.png");

}

//下向きの固定敵の弾の初期関数
void InitEnemyDownShot(Enemy& eDownWard)
{

	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//敵の弾の表示フラグをオフにする
		eDownWard.downShot[i].graphFlag = false;

		//敵の弾の画像サイズを読み込む
		//黒の弾
		GetGraphSize(eDownWard.downShot[0].object.graph, &eDownWard.downShot[i].object.w, &eDownWard.downShot[i].object.h);
		//白の弾
		GetGraphSize(eDownWard.downShot[1].object.graph, &eDownWard.downShot[i].object.w, &eDownWard.downShot[i].object.h);

	}

	//敵の弾を出すフレームカウントの初期化
	eDownWard.downShot[0].shotCounter = 0;

}

//下向きの固定敵の弾のアップデート関数
void UpdateEnemyDownShot(Enemy& eDownWard, Player& player, int& remainP)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//windowの画面内に入ってきたら弾を表示する
		if (eDownWard.object.x >= 0 && eDownWard.object.x <= SCREEN_W &&
			eDownWard.object.y >= 0 && eDownWard.object.y <= SCREEN_H)
		{
			//敵の弾のカウントを数える
			eDownWard.downShot[0].shotCounter++;

			//敵の弾のカウントが5フレーム以上になったら処理を行う
			if (eDownWard.downShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				if (eDownWard.graphFlag == true)
				{
					//表示フラグがオフだった時フラグをオンにする
					if (eDownWard.downShot[i].graphFlag == false)
					{
						//敵の弾の座標の初期設定
						eDownWard.downShot[i].object.x = (eDownWard.object.w - eDownWard.downShot[0].object.w) / 2 + eDownWard.object.x;
						eDownWard.downShot[i].object.y = eDownWard.object.h + eDownWard.object.y;

						eDownWard.downShot[i].graphFlag = true;

						//敵の弾のフレームカウントを０にする
						eDownWard.downShot[0].shotCounter = 0;

					}
				}
			}
		}

		//表示フラグがオンだった時の処理
		if (eDownWard.downShot[i].graphFlag == true)
		{
			//敵の弾の移動速度処理
			eDownWard.downShot[i].object.x -= SCREEN_SPEEDX;
			eDownWard.downShot[i].object.y += ENEMY_SHOT_SPEEDY;

			//windowの左側から出たときに表示フラグをオフにする
			if (eDownWard.downShot[i].object.y > SCREEN_H)
			{
				eDownWard.downShot[i].graphFlag = false;
			}

			//自機の表示フラグがtrueの時
			if (player.graphFlag == true)
			{
				//敵の弾と自機の当たり判定処理
				if (CollisionSmallRect(eDownWard.downShot[i].object, player.object, remainP))
				{
					//敵の弾の表示フラグをオフにする
					eDownWard.downShot[i].graphFlag = false;

					//自機のダメージを受けているフラグをオンにする
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

//下向きの固定敵の弾の描画関数
void DrawEnemyDownShot(const Enemy& eDownWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//敵の弾の表示フラグがオンの時に描画する
		if (eDownWard.downShot[i].graphFlag == true)
		{
			DrawGraph((int)eDownWard.downShot[i].object.x, (int)eDownWard.downShot[i].object.y, eDownWard.downShot[0].object.graph, true);
		}
	}
}