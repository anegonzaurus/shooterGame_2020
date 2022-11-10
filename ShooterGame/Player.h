#pragma once
#include "Common.h"
#include"Shot.h"

//自機の構造体変数
struct Player
{
	//共有構造体呼び出し
	Object object;

	//弾の構造体呼び出し
	Shot playerShot[PLAYER_SHOT_MAX];

	//画像変数
	int damagedGraph;

	//画像表示フラグ
	bool damagedFlag;

	//画像表示のためのプログラムデバック用変数
	bool graphFlag;

	//ダメージ画像表示フレームカウント
	int drawDamagedCounter;

	//ダメージを受けるまでのフレームカウント
	int damagedCount;

	//当たり判定フラグ
	bool hitFlag;

	bool crushFlag;

	bool dieFlag;

};


/*
*自機の関数群プロトタイプ宣言
*/

//自機の画像読み込み関数
void LoadPlayer(Player& player);

//自機の初期関数
void InitPlayer(Player& player);

//自機のアップデート関数
void UpdatePlayer(Player& player);

//自機の描画関数
void DrawPlayer(Player& player);