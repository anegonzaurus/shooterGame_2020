#pragma once
#include "Common.h"

struct BackGround
{
	//共有構造体呼び出し
	Object object;
};

struct DrawImg
{
	//共有構造体呼び出し
	Object object;
};


/*
* 背景１
*/

//画像読み込み関数
void LoadLeftBackGround(BackGround& back1);

//初期関数
void InitLeftBackGround(BackGround& back1);

//アップデート関数
void UpdateLeftBackGround(BackGround& back1);

//描画関数
void DrawLeftBackGround(const BackGround& back1);

/*
* 背景２
*/

//画像読み込み関数
void LoadRightBackGround(BackGround& back2);

//初期関数
void InitRightBackGround(BackGround& back2, BackGround& back1);

//アップデート関数
void UpdateRightBackGround(BackGround& back2);

//描画関数
void DrawRightBackGround(const BackGround& back2);

/*
* ゲーム開始時
*/

//画像読み込み関数
void LoadStart(DrawImg& start);

//初期関数
void InitStart(DrawImg& start);

//描画関数
void DrawStart(const DrawImg& start);

/*
* ゲームクリア時
*/

//画像読み込み関数
void LoadClear(DrawImg& clear);

//初期関数
void InitClear(DrawImg& clear);

//描画関数
void DrawClear(const DrawImg& clear);

/*
* ゲームオーバー時
*/

//画像読み込み関数
void LoadLose(DrawImg& lose);

//初期関数
void InitLose(DrawImg& lose);

//描画関数
void DrawLose(const DrawImg& lose);