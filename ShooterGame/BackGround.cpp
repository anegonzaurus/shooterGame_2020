
/*
* 背景関数処理
*/

#include"backGround.h"

/*
* 背景１
*/

//画像読み込み関数
void LoadLeftBackGround(BackGround& back1)
{
	//画像読み込み
	back1.object.graph = LoadGraph("img/bgsea.png");

}

//初期関数
void InitLeftBackGround(BackGround& back1)
{
	//背景初期位置
	back1.object.x = 0;
	back1.object.y = 0;

	//画像のサイズを読み込む
	GetGraphSize(back1.object.graph, &back1.object.w, &back1.object.h);

}

//アップデート関数
void UpdateLeftBackGround(BackGround& back1)
{
	//背景の移動速度
	back1.object.x -= SCREEN_SPEEDX;

	//横スクロール処理
	if (back1.object.x <= -back1.object.w)
	{
		back1.object.x = (float)back1.object.w;
	}
}

//描画関数
void DrawLeftBackGround(const BackGround& back1)
{
	DrawGraph((int)back1.object.x, (int)back1.object.y, back1.object.graph, true);

}

/*
* 背景２
*/

//画像読み込み関数
void LoadRightBackGround(BackGround& back2)
{
	//画像読み込み
	back2.object.graph = LoadGraph("img/bgsea.png");

}

//初期化関数
void InitRightBackGround(BackGround& back2, BackGround& back1)
{
	//初期位置
	back2.object.x = (float)back1.object.w;
	back2.object.y = 0;

	//画像のサイズを読み込む
	GetGraphSize(back2.object.graph, &back2.object.w, &back2.object.h);

}

//アップデート関数
void UpdateRightBackGround(BackGround& back2)
{
	//移動速度
	back2.object.x -= SCREEN_SPEEDX;

	//全ての
	if (back2.object.x <= -back2.object.w)
	{
		back2.object.x = (float)back2.object.w;
	}
}

//描画関数
void DrawRightBackGround(const BackGround& back2)
{
	DrawGraph((int)back2.object.x, (int)back2.object.y, back2.object.graph, true);
}

/*
* ゲーム開始時
*/

//画像読み込み関数
void LoadStart(DrawImg& start)
{
	start.object.graph = LoadGraph("img/start.png");
}

//初期関数
void InitStart(DrawImg& start)
{
	start.object.x = 0;
	start.object.y = 0;
}

//描画関数
void DrawStart(const DrawImg& start)
{
	DrawGraph((int)start.object.x, (int)start.object.y, start.object.graph, true);
	DrawString(SCREEN_W / 3, SCREEN_H / 2, "イカタコ大戦争",GetColor(255, 255, 255));
}

/*
* ゲームクリア時
*/

//画像読み込み関数
void LoadClear(DrawImg& clear)
{
	clear.object.graph = LoadGraph("img/win.png");
}

//初期関数
void InitClear(DrawImg& clear)
{
	clear.object.x = 0;
	clear.object.y = 0;
}

////アップロード関数
//void UpdataClear(ClearImg& clear)
//{
//}

//描画関数
void DrawClear(const DrawImg& clear)
{
	DrawGraph((int)clear.object.x, (int)clear.object.y, clear.object.graph, true);
	DrawString(340, 230, "GAME CLEAR", GetColor(255, 0, 0));
	DrawString(280, 360, "スペースキーでタイトルへ", GetColor(255, 255, 255));
}

/*
* ゲームオーバー時
*/

//画像読み込み関数
void LoadLose(DrawImg& lose)
{
	lose.object.graph = LoadGraph("img/loose.png");
}

//初期関数
void InitLose(DrawImg& lose)
{
	lose.object.x = 0;
	lose.object.y = 0;
}

////アップロード関数
//void UpdataLose(LoseImg& lose)
//{
//	
//}

//描画関数
void DrawLose(const DrawImg& lose)
{
	DrawGraph((int)lose.object.x, (int)lose.object.y, lose.object.graph, true);
	DrawString(340, 230, "GAME OVER", GetColor(255, 0, 0));
	DrawString(280, 360, "スペースキーでタイトルへ", GetColor(255, 255, 255));
}