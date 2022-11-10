
#include"Player.h"
#include"Enemy.h"

void Configuration()
{
	//基本設定
	ChangeWindowMode(TRUE);
	SetMainWindowText("GAME１");
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(SCREEN_W, SCREEN_H, 32);

}

//自機が受ける弾、ブロック、または敵本体との当たり判定関数
bool CollisionSmallRect(const Object& player, const Object& rect2, const bool hitFlag)
{
	if (((player.x + PLAYER_SHORT_COLLISION > rect2.x && player.x + PLAYER_SHORT_COLLISION < rect2.x + rect2.w) && hitFlag == true ||
		(rect2.x > player.x - PLAYER_SHORT_COLLISION && rect2.x < player.x + player.w - PLAYER_SHORT_COLLISION) && hitFlag == true) &&
		((player.y + PLAYER_SHORT_COLLISION > rect2.y && player.y + PLAYER_SHORT_COLLISION < rect2.y + rect2.h) && hitFlag == true ||
			(rect2.y > player.y - PLAYER_SHORT_COLLISION && rect2.y < player.y + player.h - PLAYER_SHORT_COLLISION) && hitFlag == true))
	{
		return true;
	}

	return false;
}

//自機以外が受ける弾、ブロック、または敵本体との当たり判定関数
bool CollisionHitFlagRect(const Object& rect1, const Object& rect2, const bool hitFlag)
{
	if (((rect1.x > rect2.x && rect1.x < rect2.x + rect2.w) && hitFlag == true ||
		(rect2.x > rect1.x && rect2.x < rect1.x + rect1.w) && hitFlag == true) &&
		((rect1.y > rect2.y && rect1.y < rect2.y + rect2.h) && hitFlag == true ||
			(rect2.y > rect1.y && rect2.y < rect1.y + rect1.h) && hitFlag == true))
	{
		return true;
	}

	return false;
}

//弾が敵、またはブロックに当たる当たり判定
bool CollisionRect(const Object& rect1, const Object& rect2)
{
	if (((rect1.x > rect2.x && rect1.x < rect2.x + rect2.w) ||
		(rect2.x > rect1.x && rect2.x < rect1.x + rect1.w)) &&
		((rect1.y > rect2.y && rect1.y < rect2.y + rect2.h) ||
			(rect2.y > rect1.y && rect2.y < rect1.y + rect1.h)))
	{
		return true;
	}

	return false;

}
