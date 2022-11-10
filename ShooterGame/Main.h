#pragma once

#include"BackGround.h"
#include"Player.h"
#include"Enemy.h"
#include"Event.h"
#include"Map.h"

/*
* 各構造体変数定義
*/

//自機変数定義
Player player;

//左向きの固定敵変数定義
Enemy eLeftWard[ENEMY_LEFT_WARD_MAX];

//下向きの固定敵変数定義
Enemy eDownWard[ENEMY_DOWN_WARD_MAX];

//波の動作をする敵変数定義
Enemy eWave[ENEMY_WAVE_MAX];

Enemy boss;

//背景変数定義
BackGround leftBack;
BackGround rightBack;

Map map;
Block block[1500];

//それぞれのゲームステータス変数定義
DrawImg startImg;
DrawImg loseImg;
DrawImg clearImg;

//イベント
//スコア変数定義
int score = 0;

//自機の残機変数定義
int remainPlayer = PLAYER_REMAIN;

//ゲームステータス保持変数定義
int gameStatus = LOAD;

