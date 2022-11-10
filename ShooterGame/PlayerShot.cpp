/*
* 自機の弾の関数処理
*/

#include"Player.h"
#include"Enemy.h"
#include"Event.h"
#include"Map.h"

//自機の弾の画像読み込み関数
void LoadPlayerShot(Player& player)
{
	//自機の弾の画像読み込み
	//黒の弾
	player.playerShot[0].object.graph = LoadGraph("img/IkaShot.png");
	//白の弾
	player.playerShot[1].object.graph = LoadGraph("img/RightTakoShot.png");

}

//自機の弾の初期関数
void InitPlayerShot(Player& player)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//自機の弾の表示フラグをオフにする
		player.playerShot[i].graphFlag = false;

		//自機の弾の画像サイズを読み込む
		//黒の弾
		GetGraphSize(player.playerShot[0].object.graph, &player.playerShot[i].object.w, &player.playerShot[i].object.h);
		//白の弾
		GetGraphSize(player.playerShot[1].object.graph, &player.playerShot[i].object.w, &player.playerShot[i].object.h);
	}

	//次の弾を出すまでのフレームカウント初期化
	player.playerShot[0].shotCounter = PLAYER_SHOT_COUNTER;

}

//自機の弾のアップデート関数
//当たり判定相手：左向きの敵
void UpdatePlayerShotVSEnemyLeftWard(Player& player, Enemy* eLeftWard, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//プレイヤーがスペースキーを押した時の処理
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			//自機の弾の表示フラグがオフの時弾の位置を設定する
			if (player.playerShot[i].graphFlag == false)
			{
				player.playerShot[i].object.x = player.object.w + player.object.x;
				player.playerShot[i].object.y = (player.object.h - player.playerShot[0].object.h) / 2 + player.object.y;

				//自機の弾発射カウントを１ずつ増やす
				player.playerShot[0].shotCounter++;

				//自機の弾発射カウントが30以上の時に表示フラグをオンにしてカウントを０にする
				if (player.playerShot[0].shotCounter >= PLAYER_SHOT_COUNTER)
				{
					player.playerShot[i].graphFlag = true;
					player.playerShot[0].shotCounter = 0;
				}
			}
		}

		//自機の弾の平常時のフラグがオンの時
		if (player.playerShot[i].graphFlag == true)
		{
			//自機の弾の移動速度処理
			player.playerShot[i].object.x += PLAYER_SHOT_SPEED;

			//windowの右側から出たときにフラグをオフにする
			if (player.playerShot[i].object.x > SCREEN_W)
			{
				player.playerShot[i].graphFlag = false;
			}

			for (int j = 0; j < ENEMY_LEFT_WARD_MAX; j++)
			{
				//敵の表示フラグがオンの時
				if (eLeftWard[j].graphFlag == true)
				{
					//自機の弾と左向き固定敵の当たり判定処理
					if (CollisionRect(player.playerShot[i].object, eLeftWard[j].object))
					{
						//当たったので自機の弾を表示をするフラグをオフにする(存在しない)
						player.playerShot[i].graphFlag = false;

						//敵がダメージを受けたのでダメージを受けたことを表示するフラグをオンにする
						eLeftWard[j].damagedFlag = true;

						//ダメージフラグを立てたので普通のフラグをオフにする
						eLeftWard[j].graphFlag = false;

						//スコアのアップデート関数を呼び出す
						UpdateScore(score);

					}
				}
			}
		}
	}
}

//自機の弾のアップデート関数
//当たり判定相手：下向きの敵
void UpdatePlayerShotVSEnemyDownWard(Player& player, Enemy* eDownWard, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//自機の弾の表示フラグがオンの時
		if (player.playerShot[i].graphFlag == true)
		{
			//自機の弾の移動速度処理
			player.playerShot[i].object.x += PLAYER_SHOT_SPEED;

			//windowの右側から出たときに表示フラグをオフにする
			if (player.playerShot[i].object.x > SCREEN_W)
			{
				player.playerShot[i].graphFlag = false;
			}

			//下向きの敵の数分for文でまわす
			for (int j = 0; j < ENEMY_DOWN_WARD_MAX; j++)
			{
				//敵の平常時表示フラグがオンの時
				if (eDownWard[j].graphFlag == true)
				{
					//自機の弾と下向き固定敵の当たり判定処理
					if (CollisionRect(player.playerShot[i].object, eDownWard[j].object))
					{
						//自機の弾の表示フラグをオフにする
						player.playerShot[i].graphFlag = false;

						//敵のダメージフラグをオンにする
						eDownWard[j].damagedFlag = true;

						//敵の表示フラグをオフにする
						eDownWard[j].graphFlag = false;

						//スコアのアップデート関数を呼び出す
						UpdateScore(score);

					}
				}
			}
		}
	}
}

//自機の弾のアップデート関数
//当たり判定相手：波の動作をする敵
void UpdatePlayerShotVSEnemyWave(Player& player, Enemy* eWave, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//自機の弾の表示フラグがオンの時
		if (player.playerShot[i].graphFlag == true)
		{
			//波の動作をする敵の数分for文でまわす
			for (int j = 0; j < ENEMY_WAVE_MAX; j++)
			{
				//敵の表示フラグがオンの時
				if (eWave[j].graphFlag == true)
				{
					//自機の弾と波の動作をする敵の当たり判定処理
					if (CollisionRect(player.playerShot[i].object, eWave[j].object))
					{
						//自機の弾の表示フラグをオフにする
						player.playerShot[i].graphFlag = false;

						//敵のダメージフラグをオンにする
						eWave[j].damagedFlag = true;

						//平城時表示フラグをオフにする
						eWave[j].graphFlag = false;

						//スコアのアップデート関数を呼び出す
						UpdateScore(score);

					}
				}
			}
		}
	}
}

//自機の弾のアップデート関数
//当たり判定相手：ラスボス
void UpdatePlayerShotVSboss(Player& player, Enemy& boss, const Map& map, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//自機の弾の表示フラグがオンの時
		if (player.playerShot[i].graphFlag == true)
		{
			//ラスボスの表示フラグがオンの時
			if (boss.graphFlag == true)
			{
				//自機の弾とラスボスの当たり判定処理
				if (CollisionRect(player.playerShot[i].object, boss.object) &&
					map.mapChipMoveFlag == false)
				{
					if (map.mapChipMoveFlag == true)
					{
						//自機の弾の表示フラグをオフにする
						player.playerShot[i].graphFlag = false;
					}

					//自機の弾の表示フラグをオフにする
					player.playerShot[i].graphFlag = false;

					//ラスボスのダメージフラグをオンにする
					boss.damagedFlag = true;

					//ラスボス平常時表示フラグをオフにする
					boss.graphFlag = false;

					//スコアのアップデート関数を呼び出す
					UpdateScore(score);

				}
			}
		}
	}
}


//自機の弾の描画関数
void DrawPlayerShot(const Player& player)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//自機の弾の表示フラグがオンの時画像を描画する
		if (player.playerShot[i].graphFlag == true)
		{
			DrawGraph((int)player.playerShot[i].object.x, (int)player.playerShot[i].object.y, player.playerShot[0].object.graph, true);
		}
	}
}
