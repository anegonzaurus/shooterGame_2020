
/*
* 波の動作をする敵の弾の関数
*/

#include"Player.h"
#include"Enemy.h"
#include"Event.h"

//波の動作をする敵の弾の画像読み込み関数
void LoadEnemyWaveShot(Enemy& eWave)
{
	//敵の弾の画像読み込み
	//黒の弾
	eWave.waveShot[0].object.graph = LoadGraph("img/LeftTakoShot.png");
	//白の弾
	eWave.waveShot[1].object.graph = LoadGraph("img/WhiteShot.png");

}

//波の動作をする敵の弾の初期関数
void InitEnemyWaveShot(Enemy& eWave)
{
	//波の動作をする敵の弾数分for文を回す
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//敵の弾の表示フラグをオフにする
		eWave.waveShot[i].graphFlag = false;
	}

	//敵の弾を出すフレームカウントの初期化
	eWave.waveShot[0].shotCounter = 0;

	//敵の弾の画像サイズを読み込む
	//黒の弾
	GetGraphSize(eWave.waveShot[0].object.graph, &eWave.waveShot[0].object.w, &eWave.waveShot[0].object.h);
	//白の弾
	GetGraphSize(eWave.waveShot[1].object.graph, &eWave.waveShot[1].object.w, &eWave.waveShot[1].object.h);

}

//波の動作をする敵の弾のアップデート関数
void UpdateEnemyWaveShot(Enemy& eWave, Player& player, int& remainP)
{
	//波の動作をする敵の弾数分for文を回す
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//windowの画面内に入ってきたら弾を表示する
		if (eWave.object.x >= 0 && eWave.object.x <= SCREEN_W &&
			eWave.object.y >= 0 && eWave.object.y <= SCREEN_H)
		{
			//敵の弾の発射カウントを１ずつ増やす
			++eWave.waveShot[0].shotCounter;

			//敵の弾のカウントが30フレーム以上の時
			if (eWave.waveShot[0].shotCounter >= ENEMY_WAVE_SHOT_COUNTER)
			{
				//敵の表示フラグがオンの時
				if (eWave.graphFlag == true)
				{
					//弾の表示フラグがオフの時初期位置を設定して表示フラグをオンにする
					if (eWave.waveShot[i].graphFlag == false)
					{
						//敵の弾の座標の初期設定
						eWave.waveShot[i].object.x = eWave.object.x;
						eWave.waveShot[i].object.y = (eWave.object.h - eWave.waveShot[0].object.h) / 2 + eWave.object.y;

						eWave.waveShot[i].graphFlag = true;

						//敵の弾のフレームカウントを０にする
						eWave.waveShot[0].shotCounter = 0;
					}
				}
			}
		}

		//表示フラグがオンだった時の処理
		if (eWave.waveShot[i].graphFlag == true)
		{
			//敵の弾の移動速度処理
			eWave.waveShot[i].object.x -= (ENEMY_SHOT_SPEEDX + SCREEN_SPEEDX);

			//windowの左側から出たときに表示フラグをオフにする
			if (eWave.waveShot[i].object.x < 0)
			{
				eWave.waveShot[i].graphFlag = false;
			}

			//自機の表示フラグがオンの時
			if (player.graphFlag == true)
			{
				//敵の弾と自機の当たり判定処理
				if (CollisionSmallRect(eWave.waveShot[i].object, player.object, remainP))
				{
					//敵の弾の表示フラグをオフにする
					eWave.waveShot[i].graphFlag = false;

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


//波の動作をする敵の弾の描画関数
void DrawEnemyWaveShot(const Enemy& eWave)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//敵の弾の表示フラグがオンの時に描画する
		if (eWave.waveShot[i].graphFlag == true)
		{
			DrawGraph((int)eWave.waveShot[i].object.x, (int)eWave.waveShot[i].object.y, eWave.waveShot[0].object.graph, true);
		}
	}
}
