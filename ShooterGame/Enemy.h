#pragma once
#include "common.h"
#include"Shot.h"

//敵の構造体
struct Enemy
{
	//共有構造体呼び出し
	Object object;

	//それぞれの弾の構造体の呼び出し
	Shot leftShot[ENEMY_SHOT_MAX];
	Shot downShot[ENEMY_SHOT_MAX];
	Shot waveShot[ENEMY_SHOT_MAX];
	Shot bossFirstShot[ENEMY_SHOT_MAX];
	Shot bossSecondShot[ENEMY_SHOT_MAX];

	//画像変数
	int damagedGraph;

	//画像表示フラグ
	bool graphFlag, damagedFlag;

	//敵のダメージ画像表示フレームカウント
	int drawDamagedCounter;

	//敵が死ぬまでのダメージフレームカウント
	int DieCounter;

	//波の動作をする敵の移動radian
	float rad;
};

/*
* 
* 敵関数群プロトタイプ宣言
* 
*/

/*
* 左向きの固定敵
*/

//左向きの固定敵の画像読み込み関数
void LoadEnemyLeftWard(Enemy& eLeftWard);

//左向きの固定敵の初期関数
void InitEnemyLeftWard(Enemy& eLeftWard, int forSize);

//左向きの固定敵のアップデート関数
void UpdateEnemyLeftWard(Enemy& eLeftWard, Player& player, int& remainP);

//左向きの固定敵の描画関数
void DrawEnemyLeftWard(Enemy& eLeftWard);

/*
* 下向きの固定敵
*/

//下向きの固定敵の画像読み込み関数
void LoadEnemyDownWard(Enemy& eDownWard);

//下向きの固定敵の初期関数
void InitEnemyDownWard(Enemy& eDownWard, int forSize);

//下向きの固定敵のアップデート関数
void UpdateEnemyDownWard(Enemy& eDownWard, Player& player, int& remainP);

//下向きの固定敵の描画関数
void DrawEnemyDownWard(Enemy& eDownWard);

/*
* 波の動作をする敵
*/

//波の動作をする敵の画像読み込み関数
void LoadEnemyWave(Enemy& eWave);

//波の動作をする敵の初期関数
void InitEnemyWave(Enemy& eWave);

//波の動作をする敵のアップデート関数
void UpdateEnemyWave(Enemy& eWave, Player& player, int& remainP);

//波の動作をする敵の描画関数
void DrawEnemyWave(Enemy& eWave);

/*
* ラスボス
*/

//ラスボスの画像読み込み関数
void LoadBoss(Enemy& boss);

//ラスボスの初期関数
void InitBoss(Enemy& boss);

//ラスボスのアップデート関数
void UpdateBoss(Enemy& boss, Map& map, Player& player, int& remainP);

//ラスボスの描画関数
void DrawBoss(Enemy& boss);