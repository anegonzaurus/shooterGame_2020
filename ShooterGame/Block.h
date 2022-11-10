#pragma once
#include"Common.h"

//ブロックの構造体変数
struct Block
{
	//共有構造体呼び出し
	Object object;
};

/*
* マップチップのブロックの関数のプロトタイプ宣言
*/

//ブロックの初期関数
void InitBlock(Block* block, int blockNum, int graph, float x, float y, int w, int h);

//ブロックのアップデート関数
void UpdateBlock(Block* block, Map& map, Enemy* eLeftWard, Enemy* eDownWard, Enemy* eWave, Player& player, int& remainP);

/*
* ブロックの当たり判定関数
*/

////自機本体とブロックの当たり判定関数
//void HitPlayer(Block& block, Player& player, int& remainP);

//自機の弾とブロックの当たり判定関数
void HitPlayerShot(Block& block, Player& player);

//左向きの固定敵の弾とブロックの当たり判定関数
void HitEnemyLeftWardShot(Block& block, Enemy& eLeftWard);

//下向きの固定敵の弾とブロックの当たり判定関数
void HitEnemyDownWardShot(Block& block, Enemy& eDownWard);

//波の動作をする敵の弾とブロックの当たり判定関数
void HitEnemyWaveShot(Block& block, Enemy& eWave);

//ボスの弾とブロックの当たり判定関数
void HitBossShot(Block& block, Enemy& boss);

//ブロックの描画関数
void DrawBlock(const Block* block, const int blockNum);