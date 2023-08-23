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

//#define DEBUG

GameMain::GameMain()
{
	MapX = 3376;
	Haikei = LoadGraph("image/Stage/MarioWorld.png");
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

void GameMain::Draw()const
{
	//DrawGraph(MAP_WIDHT, SCREEN_HEIGHT, Haikei, FALSE);
	DrawRotaGraph(MapX, SCREEN_HEIGHT, 2.0, 0.0, Haikei, TRUE, FALSE);
	Mario.Draw();
}