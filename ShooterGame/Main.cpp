
//強制右スクロールシューティングゲーム

#include"main.h"

/*
* main.cppに使用する関数プロトタイプ宣言
*/

//全体の画像読み込み関数
void Load();

//全体の初期関数
void Init();

//タイトル時実行関数
void Title();

//プレイ時実行関数
void Play();

//クリア時実行関数
void Clear();

//ゲームオーバー時実行関数
void Over();

//全体のアップデート関数
void Update();

//全体の描画関数
void Draw();


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//基本設定関数
	Configuration();

	//ゲームステータスがLOADの時
	Load();

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !ProcessMessage())
	{
		switch (gameStatus)
		{
		case INIT:
			Init();
			break;

		//ゲームステータスがタイトルの時
		case TITLE:
			Title();

			break;

		//ゲームステータスがプレイの時
		case PLAY:
			Play();

			break;

		//ゲームステータスがオーバーの時
		case OVER:
			Over();

			break;

		//ゲームステータスがクリアの時
		case CLEAR:
			Clear();

			break;

		default:
			break;
		}

	}

	DxLib_End();
	return 0;
}

//全体の画像読み込み関数
void Load()
{
	//ゲームステータスがLOADの時
	if (gameStatus == LOAD)
	{
		//背景の画像読み込み関数
		LoadLeftBackGround(leftBack);
		LoadRightBackGround(rightBack);

		//それぞれのゲームステータス時の画像読み込み関数
		LoadStart(startImg);
		LoadClear(clearImg);
		LoadLose(loseImg);

		//自機の画像読み込み関数
		LoadPlayer(player);

		//自機の弾の画像読み込み関数
		LoadPlayerShot(player);

		//マップの画像読み込み関数
		LoadMap(map);

		//左向きの固定敵のfor文
		for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
		{
			//左向きの固定敵の画像読み込み関数
			LoadEnemyLeftWard(eLeftWard[i]);

			//左向きの固定敵の弾の画像読み込み関数
			LoadEnemyLeftShot(eLeftWard[i]);
		}

		//下向きの固定敵のfor文
		for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
		{
			//下向きの固定敵の画像読み込み関数
			LoadEnemyDownWard(eDownWard[i]);

			//下向きの固定敵の弾の画像読み込み関数
			LoadEnemyDownShot(eDownWard[i]);
		}

		//波の動作をする敵のfor文
		for (int i = 0; i < ENEMY_WAVE_MAX; i++)
		{
			//波の動作をする敵の画像読み込み関数
			LoadEnemyWave(eWave[i]);

			//波の動作をする敵の弾の画像読み込み関数
			LoadEnemyWaveShot(eWave[i]);
		}

		LoadBoss(boss);
		LoadBossShot(boss);

		//ゲームステータスをINITにする
		gameStatus = INIT;
	}
}

//全体の初期関数
void Init()
{
	//自機初期関数
	InitPlayer(player);

	//自機の弾初期関数
	InitPlayerShot(player);

	//左向きの固定敵
	for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
	{
		//左向きの固定敵初期関数
		InitEnemyLeftWard(eLeftWard[i], i);

		//左向きの固定敵の弾初期関数
		InitEnemyLeftShot(eLeftWard[i]);
	}

	//下向きの固定敵
	for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
	{
		//下向きの固定敵初期関数
		InitEnemyDownWard(eDownWard[i], i);

		//下向きの固定敵の弾初期関数
		InitEnemyDownShot(eDownWard[i]);
	}

	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		//波の動作をする敵の初期関数
		InitEnemyWave(eWave[i]);

		//波の動作をする敵の弾の初期関数
		InitEnemyWaveShot(eWave[i]);
	}

	InitBoss(boss);
	InitBossShot(boss);

	//背景初期関数
	InitLeftBackGround(leftBack);
	InitRightBackGround(rightBack, leftBack);

	//マップの初期関数
	InitMap(map, block);

	//ゲームステータス画面初期関数
	InitStart(startImg);
	InitClear(clearImg);
	InitLose(loseImg);

	//スコア初期関数
	InitScore(score);

	//自機の残機初期関数
	InitRemainPlayer(remainPlayer);

	//ゲームステータスをタイトルへ
	gameStatus = TITLE;
}

//タイトル時実行関数
void Title()
{
		ClearDrawScreen();

		//スタート画面表示
		DrawStart(startImg);
		SetFontSize(24);


		//エンターキーを押したらゲームステータスをPLAYにする
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			gameStatus = PLAY;

			WaitTimer(300);
		}

		ScreenFlip();

}

//プレイ時実行関数
void Play()
{
		//全体のアップデート関数
		Update();

		//全体の描画関数
		Draw();
}

//ゲームオーバー時実行関数
void Over()
{
		ClearDrawScreen();

		//ゲームオーバー画面表示
		DrawLose(loseImg);

		//スペースキーを押したらゲームステータスをINITにする
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			gameStatus = INIT;

			WaitTimer(300);

		}

		ScreenFlip();

}

//クリア時実行関数
void Clear()
{
		ClearDrawScreen();

		//ゲームクリア画面表示
		DrawClear(clearImg);

		//スペースキーを押したらゲームステータスをINITにする
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			gameStatus = INIT;

			WaitTimer(300);
		}

		ScreenFlip();
}

//全体のアップデート関数
void Update()
{
	/*
	各アップデート関数を呼び出す
	*/

	//背景アップデート関数
	UpdateLeftBackGround(leftBack);
	UpdateRightBackGround(rightBack);

	//マップのアップデート関数
	UpdateMap(block, map, eLeftWard, eDownWard, eWave, player, remainPlayer);

	//自機アップデート関数
	UpdatePlayer(player);

	//自機の弾アップデート関数
	//対左向きの固定敵
	UpdatePlayerShotVSEnemyLeftWard(player, eLeftWard, score);

	//対下向きの固定敵
	UpdatePlayerShotVSEnemyDownWard(player, eDownWard, score);

	//対波の動作をする敵
	UpdatePlayerShotVSEnemyWave(player, eWave, score);

	//UpdatePlayerShotVSEnemies(player,elef)

	//対ラスボス
	UpdatePlayerShotVSboss(player, boss, map, score);
	

	//左向きの敵と弾のアップデート関数
	for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
	{
		//左向きの固定敵
		UpdateEnemyLeftWard(eLeftWard[i], player, remainPlayer);

		//左向きの固定敵の弾
		UpdateEnemyLeftShot(eLeftWard[i], player, remainPlayer);
	}

	//下向きの敵と弾のアップデート関数
	for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
	{
		//下向きの固定敵
		UpdateEnemyDownWard(eDownWard[i], player, remainPlayer);

		//下向きの固定敵の弾
		UpdateEnemyDownShot(eDownWard[i], player, remainPlayer);
	}

	//波の動作をする敵と弾のアップデート関数
	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		//波の動作をする敵
		UpdateEnemyWave(eWave[i], player, remainPlayer);

		//波の動作をする敵の弾
		UpdateEnemyWaveShot(eWave[i], player, remainPlayer);

	}

	UpdateBoss(boss, map, player, remainPlayer);
	UpdateBossShot(boss, map, player, remainPlayer);

	//ボスを倒したときにゲームステータスをCLEARにする
	if (boss.graphFlag == false && boss.damagedFlag == false)
	{
		WaitTimer(300);

		gameStatus = CLEAR;
	}

	if (player.dieFlag)
	{
		WaitTimer(300);

		gameStatus = OVER;
	}

	//自機の残機が０より下でゲームステータスをOVERにする
	if (remainPlayer <= 0)
	{
		WaitTimer(300);

		gameStatus = OVER;
	}

}

//全体の描画関数
void Draw()
{
	ClearDrawScreen();

	/*
	描画関数を呼び出す
	*/

	//背景描画関数
	DrawLeftBackGround(leftBack);
	DrawRightBackGround(rightBack);

	//マップの描画関数
	DrawMap(map, block);

	////画面スクロール座標説明用プログラム
	//DrawFormatString(0, 100, GetColor(0, 0, 0), "プレイヤー：%f、%f", player.object.x, player.object.y);
	//DrawFormatString(0, 150, GetColor(0, 0, 0), "背景１：%f", leftBack.object.x);
	//DrawFormatString(0, 200, GetColor(0, 0, 0), "背景２：%f", rightBack.object.x);
	//DrawFormatString(0, 250, GetColor(0, 0, 0), "左向き敵１：%f", eLeftCannon[0].object.x);
	//DrawFormatString(0, 50, GetColor(0, 0, 0), "波の動作をする敵：%f", eWave.object.x);
	//DrawFormatString(0, 100, GetColor(0, 0, 0), "マップチップ[0]：%f", block[0].object.x);
	DrawFormatString(0, 100, GetColor(0, 0, 0), "ラスボスの座標：(%f,%f)", boss.object.x, boss.object.y);

	//自機描画関数
	DrawPlayer(player);

	//自機の弾描画関数
	DrawPlayerShot(player);

	//敵描画関数
	for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
	{
		//左向きの固定敵
		DrawEnemyLeftWard(eLeftWard[i]);

		//左向きの固定敵の弾
		DrawEnemyLeftShot(eLeftWard[i]);
	}

	//敵描画関数
	for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
	{
		//下向きの固定敵
		DrawEnemyDownWard(eDownWard[i]);

		//下向きの固定敵の弾
		DrawEnemyDownShot(eDownWard[i]);
	}

	//敵描画関数
	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		//波の動作をする敵
		DrawEnemyWave(eWave[i]);

		//波の動作をする敵の弾
		DrawEnemyWaveShot(eWave[i]);

	}

	DrawBoss(boss);
	DrawBossShot(boss);

	////スコア描画関数
	//DrawScore(score);

	//自機の残機描画関数
	DrawRemainPlayer(remainPlayer);

	ScreenFlip();

}