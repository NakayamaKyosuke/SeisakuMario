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
#include "UI.h"
#include "Title.h"
#include "Enemy.h"
//#define DEBUG

GameMain::GameMain()
{
	Count = 0;
	MapX = 3376;
	Haikei = LoadGraph("image/Stage/MarioWorld.png");
}

AbstractScene* GameMain::Update()
{
	Count++;
	Ui.Update();
	Enemy.Update();
	Mario.Update();
	if (Mario.GetX() > 323 && Mario.GetMoveFlg() == TRUE)
	{

		MapX = MapX - 3;
	}
	if (Mario.GetX() > 323 && Mario.GetMoveFlg() == TRUE&& Mario.GetDA() == TRUE)
	{
		MapX = MapX - 4;
	}
	return this;
	if (Count >= 24000)
	{
		return new Title();
	}
}

void GameMain::Draw()const
{
	//DrawGraph(MAP_WIDHT, SCREEN_HEIGHT, Haikei, FALSE);
	DrawRotaGraph(MapX, SCREEN_HEIGHT, 2.0, 0.0, Haikei, TRUE, FALSE);
	Mario.Draw();
	Enemy.Draw();
	Ui.Draw();
}