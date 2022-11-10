
/*
* 自機の関数処理
*/

#include"Player.h"

//自機の画像読み込み関数
void LoadPlayer(Player& player)
{
	player.object.graph = LoadGraph("img/playerIka.png");
	player.damagedGraph = LoadGraph("img/playerDamagedIka.png");
}

//自機の初期関数
void InitPlayer(Player& player)
{
	//自機の座標の初期設定
	player.object.x = SCREEN_W / 2;
	player.object.y = SCREEN_H / 2;

	//自機の画像サイズを読み込む
	GetGraphSize(player.object.graph, &player.object.w, &player.object.h);

	//自機の平常時画像フラグをオンにする
	player.graphFlag = true;

	//自機のダメージフラグをオフにする
	player.damagedFlag = false;

	//自機のダメージ画像表示カウントを初期設定
	player.drawDamagedCounter = 0;

	//自機の速度ベクトルの初期設定
	player.object.vx = PLAYER_SPEED;
	player.object.vy = PLAYER_SPEED;

	//自機のダメージを受けるまでのフレームカウント初期値設定
	player.damagedCount = PLAYER_DAMAGED_COUNTER;

	//当たり判定フラグをオンにする
	player.hitFlag = true;

	//自機の潰されるフラグをオフにする
	player.crushFlag = false;

	player.dieFlag = false;
}

//自機のアップデート関数
void UpdatePlayer(Player& player)
{
	//自機の当たり判定フラグがオフの時
	if (player.hitFlag == false)
	{
		//ダメージを受けるまでのフレームカウントを１増やす
		++player.damagedCount;

		//ダメージを受けるまでのカウントが480以上の時に当たり判定フラグをオンにする
		if (player.damagedCount >= PLAYER_DAMAGED_COUNTER)
		{
			player.hitFlag = true;
		}
	}


	//それぞれのキーをプレイヤーが押していたら自機を動かす
	//上キー
	if (CheckHitKey(KEY_INPUT_UP) == true /*&& player.moveFlag == true*/)
	{
		player.object.y -= player.object.vy;
	}
	//下キー
	if (CheckHitKey(KEY_INPUT_DOWN) == true /*&& player.moveFlag == true*/)
	{
		player.object.y += player.object.vy;
	}
	//左キー
	if (CheckHitKey(KEY_INPUT_LEFT) == true /*&& player.moveFlag == true*/)
	{
		player.object.x -= player.object.vx;
	}
	//右キー
	if (CheckHitKey(KEY_INPUT_RIGHT) == true /*&& player.moveFlag == true*/)
	{
		player.object.x += player.object.vx;
	}



	//自機がはみ出そうになったら画面の中に戻す処理
	//windowの左端
	if (player.object.x < 0 && player.crushFlag == false)
	{
		player.object.x = 0;

	}

	if (player.object.x < -(MAP_CHIP_SIZE * 2) && player.crushFlag)
	{
		player.dieFlag = true;
	}
	else
	{
		player.crushFlag = false;
	}

	//windowの右端
	if (player.object.x > SCREEN_W - player.object.w)
	{
		player.object.x = (float)(SCREEN_W) - player.object.w;
	}
	//windowの上
	if (player.object.y < 0)
	{
		player.object.y = 0;
	}
	//windowの下
	if (player.object.y > SCREEN_H - player.object.h)
	{
		player.object.y = (float)(SCREEN_H) - player.object.h;
	}

}


//自機の描画関数
void DrawPlayer(Player& player)
{
	//自機の平常時表示フラグがオンの時平常時の画像を描画する
	if (player.graphFlag == true)
	{
		DrawGraph((int)player.object.x, (int)player.object.y, player.object.graph, true);
	}

	//自機のダメージフラグがオンの時ダメージを受けている画像を描画する
	if (player.damagedFlag == true)
	{
		player.graphFlag = false;

		++player.drawDamagedCounter;

		//ダメージ画像を描画する
		DrawGraph((int)player.object.x, (int)player.object.y, player.damagedGraph, true);

		//自機のダメージカウントが５以上の時ダメージフラグをオフにしてダメージカウントを０にして平常時の表示フラグをオンにする
		if (player.drawDamagedCounter >= PLAYER_DRAW_DAMAGED_COUNTER)
		{
			player.damagedFlag = false;
			player.drawDamagedCounter = 0;
			player.graphFlag = true;
		}
	}
}