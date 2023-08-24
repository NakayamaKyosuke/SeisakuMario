#include "GameMain.h"
#include"DxLib.h"
#include"GameMain.h"
#include"KeyManager.h"
#include "Mario.h"
#include"AbstractScene.h"
#include"UI.h"
#include"Item.h"
#include"common.h"
#include "Mario.h"
#include "MapChip.h"

//#define DEBUG

GameMain::GameMain()
{
	MapX = 3376;


	Haikei = LoadGraph("image/Stage/MarioWorld.png");
	LoadDivGraph("image/MapBlocks.png", 23, 23, 1, 32, 32, MapBlock_Image);
}

AbstractScene* GameMain::Update()
{

	Mario.Update();
	if (Mario.GetX() > 323 && Mario.GetMoveFlg() == TRUE)
	{

		MapX = MapX - 3;
	}
	return this;
}

bool GameMain::HitCheck(int i, int j)
{
	//Ž©•ª‚Ì“–‚½‚è”»’è‚Ì‚â‚Â
	int left, top, right, bottom;
	int retval = 0;
	left = CELL_SIZE_X * j;
	top = CELL_SIZE_Y * i;
	right = left + CELL_SIZE_X;
	bottom = top + CELL_SIZE_Y;
	int ax1 = Mario.GetX() - (SIZE_W / 2);
	int ay1 = Mario.GetY() - (SIZE_H / 2);
	int ax2 = Mario.GetX() + (SIZE_W);
	int ay2 = Mario.GetY() + (SIZE_H);
	if ((ax1 < right) && (ax2 > left) && (ay1 < bottom) && (ay2 > top)) {
		retval = TRUE;
	}

	return retval;
}

void GameMain::Draw()const
{
	//DrawGraph(MAP_WIDHT, SCREEN_HEIGHT, Haikei, FALSE);

	

	//DrawRotaGraph(MapX, SCREEN_HEIGHT, 2.0, 0.0, Haikei, TRUE, FALSE);
	Mario.Draw();
}