
/*
* マップの処理関数
*/

#include"Map.h"

//マップの画像読み込み関数
void LoadMap(Map& map)
{
	//マップの画像読み込み
	map.object.graph = LoadGraph("img/darkDirtBlock.png");
}

//マップの初期関数
void InitMap(Map& map, Block* block)
{
	//ブロックカウントの初期化
	map.blockCounter = 0;

	map.mapChipMoveFlag = true;

	//マップのy座標のfor文
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		//マップのx座標のfor文
		for (int x = 0; x < MAP_WIDTH * MAP_SCROLL_MAX; x++)
		{
			//マップチップの二次元配列の値読み込み
			int mapChipBlockNum = mapChipBlock[y][x];

			//マップチップの値が０以外だった場合
			if (mapChipBlockNum != 0)
			{
				//ブロックの座標を取得する
				float blockPosX = (float)(x * MAP_CHIP_SIZE);
				float blockPosY = (float)(y * MAP_CHIP_SIZE);

				//ブロックの初期関数を呼び出す
				InitBlock(block, map.blockCounter, map.object.graph, blockPosX, blockPosY, MAP_CHIP_SIZE, MAP_CHIP_SIZE);
				//ブロックカウントを１増やす
				++map.blockCounter;
			}
		}
	}
}

//マップのアップデート関数
void UpdateMap(Block* block, Map& map, Enemy* eLeftWard, Enemy* eDownWard, Enemy* eWave, Player& player, int& remainP)
{
	UpdateBlock(block, map, eLeftWard, eDownWard, eWave, player, remainP);
}

//マップの描画関数
void DrawMap(const Map& map, Block* block)
{
	//for文でブロック一つ一つに関数を呼び出す
	for (int i = 0; i < map.blockCounter; i++)
	{
		//ブロックの描画関数を呼び出す
		DrawBlock(block, i);
	}
}