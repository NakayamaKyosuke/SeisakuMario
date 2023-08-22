#include "GameMain.h"
#include"DxLib.h"
#include"GameMain.h"
#include"KeyManager.h"
#include "Mario.h"
#include"AbstractScene.h"
#include"UI.h"
#include"Item.h"
#include "Map.h"

//#define DEBUG

GameMain::GameMain()
{
	Haikei = LoadGraph("image/Stage/MarioWorld.png");
}

AbstractScene* GameMain::Update()
{
	Mario.Update();
	Map.Update();
	return this;
}

void GameMain::Draw()const
{
	DrawGraph(0,0,Haikei,TRUE);
	Mario.Draw();
	Map.Draw();
}