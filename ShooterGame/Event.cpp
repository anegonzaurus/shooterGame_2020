
#include"event.h"

//スコアの初期関数
void InitScore(int& score)
{
	score = 0;
}

//スコアのアップデート関数
void UpdateScore(int& score)
{
	score += 50;
}


//スコアの描画関数
void DrawScore(const int score)
{
	DrawFormatString(0, 0, GetColor(0, 0, 0), "SCORE : %d", score);
}

//自機の残機の初期関数
void InitRemainPlayer(int& pRemain)
{
	pRemain = PLAYER_REMAIN;
}

//自機の残機のアップデート関数
void UpdateRemainPlayer(int& pRemain)
{
	pRemain--;
}

//自機の残機の描画関数
void DrawRemainPlayer(const int pRemain)
{
	DrawFormatString(SCREEN_W / 3, 0, GetColor(0, 0, 0), "残機：%d", pRemain);
}