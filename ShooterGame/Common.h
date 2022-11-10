#pragma once

#include "DxLib.h"

//自機のグローバル変数
const float PLAYER_SPEED = 5.0f;							//自機の移動速度
const int PLAYER_SHOT_MAX = 10;								//自機の弾の数
const float PLAYER_SHOT_SPEED = 5.0f;						//自機の弾の速度
const int PLAYER_SHOT_COUNTER = 30;							//スペースキーを押した時の自機の弾を出すまでのフレームカウント
const int PLAYER_DAMAGED_COUNTER = 100;						//自機のダメージを受けるまでのフレームカウント
const int PLAYER_DRAW_DAMAGED_COUNTER = 100;				//自機のダメージを受けたときの画像表示フレームカウント
const int PLAYER_REMAIN = 100;								//自機の残機の数
const int PLAYER_SHORT_COLLISION = 16;						//自機の当たり判定を短縮するドット範囲数


//固定敵のグローバル変数
const int ENEMY_LEFT_WARD_MAX = 3;							//左向きの敵の数
const int ENEMY_DOWN_WARD_MAX = 10;							//下向きの敵の数
const int ENEMY_WAVE_MAX = 1;								//波の動きをする敵の数
const float ENEMY_FIX_SPEED = 2.5f;							//固定敵の移動速度
const float ENEMY_WAVE_SPEED = 3.0f;						//波の動作をする敵の移動速度
const int ENEMY_SHOT_MAX = 15;								//敵の弾の数
const float ENEMY_SHOT_SPEEDX = 5.0f;						//敵の弾のx軸の速さ
const float ENEMY_SHOT_SPEEDY = 5.0f;						//敵の弾のy軸の速さ
const int ENEMY_SHOT_COUNTER = 80;							//敵が弾を発射するまでのフレームカウント
const int ENEMY_WAVE_SHOT_COUNTER = 150;					//波の動作をする敵の弾が発射するまでのフレームカウント
const int ENEMY_DRAW_DAMAGED_COUNTER = 15;					//敵のダメージ画像表示フレームカウント数
const float ENEMY_RAD = 0.03f;								//敵のラジアンの増加数
const int BOSS_DRAW_DAMAGED_COUNTER = 10;
const float BOSS_MOVE_SHOT = 5;

//マップチップのグローバル変数
const int MAP_CHIP_SIZE = 32;								//マップチップのサイズ
const int MAP_WIDTH = 20;									//マップチップの横幅
const int MAP_HEIGHT = 15;									//マップチップの縦幅
const int MAP_SCROLL_MAX = 10;								//マップチップの最大スクロール数
const float MAP_SCREEN_SPEEDX = 2.0f;						//マップチップのスクロール速度
const int MAX_OVERLAP_CAPACITY = 10;						// 壁最大めり込み量

//スクリーンのグローバル変数
const int SCREEN_W = MAP_CHIP_SIZE * MAP_WIDTH;				//スクリーンの幅
const int SCREEN_H = MAP_CHIP_SIZE * MAP_HEIGHT;			//スクリーンの高さ
const float SCREEN_SPEEDX = 1.0f;							//背景の移動速度


////イベントのグローバル変数
//const int CLEAR_SCORE = 20000;								//スコアの上限

enum { LOAD, INIT, TITLE, PLAY, OVER, CLEAR };				//ゲーム状態管理

//共有変数構造体
struct Object
{
	//座標変数
	float x;
	float y;

	//画像サイズ変数
	int w, h;

	//画像変数
	int graph;

	//移動速度変数
	float vx, vy;
};

//プロトタイプ宣言起動用のストラクト
struct Player;
struct Enemy;
struct Shot;
struct Map;
struct Block;

//基本設定関数
void Configuration();

//自機が受ける弾、ブロック、または敵本体との当たり判定関数
bool CollisionSmallRect(const Object& player, const Object& rect2, const bool hitFlag);

//自機以外が受ける弾、ブロック、または敵本体との当たり判定関数
bool CollisionHitFlagRect(const Object& rect1, const Object& rect2, const bool hitFlag);

//弾が敵、またはブロックに当たる当たり判定
bool CollisionRect(const Object& rect1, const Object& rect2);
