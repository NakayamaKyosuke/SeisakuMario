#include "MarioZanki.h"
#include"GameMain.h"
#include"AbstractScene.h"
#include"DxLib.h"


MarioZanki::MarioZanki()
{
	ICount = 0;
	MarioName_Image = LoadGraph("image/UI/name_mario.png");
	World_Image = LoadGraph("image/UI/world.png");
	Time_Image = LoadGraph("image/UI/time.png");
	Select_Image = LoadGraph("image/UI/Select.png");
	Select2_Image = LoadGraph("image/UI/Select2.png");
	LoadDivGraph("image/Mario/mario.png", 4, 4, 1, 32, 32, MarioImage);
	LoadDivGraph("image/UI/uicoin.png", 4, 4, 1, 16, 16, Coin_Image);
	LoadDivGraph("image/UI/num.png", 15, 15, 1, 16, 16, Number_Image);
}

AbstractScene* MarioZanki::Update()
{

	ICount++;


	if (ICount > 180)
	{
		return new GameMain();
	}
	return this;
}

void MarioZanki::Draw() const
{
	//マリオの名前
	DrawGraph(90, 5, MarioName_Image, true);
	//スコア表示
	DrawGraph(90, 20, Number_Image[0], true);
	DrawGraph(105, 20, Number_Image[0], true);
	DrawGraph(120, 20, Number_Image[0], true);
	DrawGraph(135, 20, Number_Image[0], true);
	DrawGraph(150, 20, Number_Image[0], true);
	DrawGraph(165, 20, Number_Image[0], true);
	//ステージ表記画像
	DrawGraph(360, 5, World_Image, true);
	//ステージ2表記画像
	DrawGraph(220, 150, World_Image, true);
	//1-1
	DrawGraph(375, 25, Number_Image[1], true);
	DrawGraph(393, 25, Number_Image[10], true);
	DrawGraph(410, 25, Number_Image[1], true);
	//1-1真ん中
	DrawGraph(320, 150, Number_Image[1], true);
	DrawGraph(335, 150, Number_Image[10], true);
	DrawGraph(350, 150, Number_Image[1], true);
	//残り時間表記画像
	DrawGraph(490, 5, Time_Image, true);
	//コイン画像
	DrawGraph(230, 20, Coin_Image[0], true);
	DrawGraph(245, 20, Number_Image[11], true);
	DrawGraph(260, 22, Number_Image[0], true);
	DrawGraph(275, 22, Number_Image[0], true);
	//残機表示
	DrawGraph(240, 190, MarioImage[0], true);
	DrawGraph(280, 200, Number_Image[11], true);
	DrawGraph(320, 200, Number_Image[3], true);


}
