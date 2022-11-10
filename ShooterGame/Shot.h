#pragma once
#include "Common.h"

//弾の構造体
struct Shot
{
	//共有構造体呼び出し
	Object object;

	//画像表示フラグ
	bool graphFlag;

	//弾発射カウント
	int shotCounter;
};

/*
* 自機の弾の関数のプロトタイプ宣言
*/

//自機の弾の画像読み込み関数
void LoadPlayerShot(Player& player);

//自機の弾の初期関数
void InitPlayerShot(Player& player);

//自機の弾のアップデート関数
//対左向きの固定敵
void UpdatePlayerShotVSEnemyLeftWard(Player& player, Enemy* eLeftWard, int& score);

//対下向きの固定敵
void UpdatePlayerShotVSEnemyDownWard(Player& player, Enemy* eDownWard, int& score);

//対波の動作をする敵
void UpdatePlayerShotVSEnemyWave(Player& player, Enemy* eWave, int& score);

//対ラスボス
void UpdatePlayerShotVSboss(Player& player, Enemy& boss, const Map& map, int& score);

//自機の弾の描画関数
void DrawPlayerShot(const Player& player);



/*
* 固定敵の弾の関数のプロトタイプ宣言
*/


////////左向き//////////

//左向きの固定敵の弾の画像読み込み関数
void LoadEnemyLeftShot(Enemy& eLeftWard);

//左向きの固定敵の弾の初期関数
void InitEnemyLeftShot(Enemy& eLeftWard);

//左向きの固定敵の弾のアップデート関数
void UpdateEnemyLeftShot(Enemy& eLeftWard, Player& player, int& remainP);

//左向きの固定敵の弾の描画関数
void DrawEnemyLeftShot(const Enemy& eLeftWard);


//////////下向き//////////

//下向きの固定敵の弾の画像読み込み関数
void LoadEnemyDownShot(Enemy& eDownWard);

//下向きの固定敵の弾の関初期関数
void InitEnemyDownShot(Enemy& eDownWard);

//下向きの固定敵の弾のアップデート関数
void UpdateEnemyDownShot(Enemy& eDownWard, Player& player, int& remainP);

//下向きの固定敵の弾の描画関数
void DrawEnemyDownShot(const Enemy& eDownWard);



/*
* 波の動作をする敵の弾の関数
*/

//波の動作をする敵の弾の画像読み込み関数
void LoadEnemyWaveShot(Enemy& eWave);

//波の動作をする敵の弾の初期関数
void InitEnemyWaveShot(Enemy& eWave);

//波の動作をする敵の弾のアップデート関数
void UpdateEnemyWaveShot(Enemy& eWave, Player& player, int& remainP);

//波の動作をする敵の弾の描画関数
void DrawEnemyWaveShot(const Enemy& eWave);

/*
* ラスボスの弾の関数
*/

//ラスボスの弾の画像読み込み関数
void LoadBossShot(Enemy& boss);

//ラスボスの弾の初期関数
void InitBossShot(Enemy& boss);

//ラスボスの弾のアップデート関数
void UpdateBossShot(Enemy& boss, const Map& map, Player& player, int& remainP);

//ラスボスの弾の描画関数
void DrawBossShot(const Enemy& boss);