#pragma once
#include "common.h"

/*
* スコアのプロトタイプ宣言
*/

//スコアの初期関数
void InitScore(int& score);

//スコアのアップデート関数
void UpdateScore(int& score);

//スコアの描画関数
void DrawScore(const int score);

/*
* 自機の残機のプロトタイプ宣言
*/

//自機の残機の初期関数
void InitRemainPlayer(int& pRemain);

//自機の残機のアップデート関数
void UpdateRemainPlayer(int& pRemain);

//自機の残機の描画関数
void DrawRemainPlayer(const int pRemain);