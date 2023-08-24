#include "UI.h"
#include"GameMain.h"
#include"AbstractScene.h"
#include <DxLib.h>

UI::UI() {

	CTime = 0;
	Coin_Count = 0;

	Time = 0;
	Time2 = 0;
	Time3 = 1;
	Time_Count = 0;
	MarioName_Image = LoadGraph("image/UI/name_mario.png");
	World_Image = LoadGraph("image/UI/world.png");
	Time_Image = LoadGraph("image/UI/time.png");
	Select_Image = LoadGraph("image/UI/Select.png");
	Select2_Image = LoadGraph("image/UI/Select2.png");
	Carsol_Image = LoadGraph("image/Item/mushroom.png");
	LoadDivGraph("image/UI/uicoin.png", 4, 4, 1, 16, 16, Coin_Image);
	LoadDivGraph("image/UI/num.png", 15, 15, 1, 16, 16, Number_Image);
	LoadDivGraph("image/UI/num2.png", 10, 10, 1, 16, 16, Number2_Image);
	LoadDivGraph("image/UI/num2-22.png", 10, 10, 1, 16, 16, Number3_Image);
	LoadDivGraph("image/UI/num3.png", 5, 5, 1, 16, 16, Number4_Image);
}

void UI::Update()
{

	CTime++;
	if (CTime % 12 == 0)
	{
		Coin_Count++;
	}

	Time_Count++;
	if (Time_Count % 60 == 0)
	{
		Time++;
	}

	if (Time == 10)
	{
		Time2++;
		Time = 0;
	}
	if (Time2 == 10)
	{
		Time3++;
		Time2 = 0;
	}
	
	if (Time == 10)
	{
		Time = 0;
	}
}

void UI::Draw() const
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
	//1-1
	DrawGraph(375, 25, Number_Image[1], true);
	DrawGraph(393, 25, Number_Image[10], true);
	DrawGraph(410, 25, Number_Image[1], true);
	//残り時間表記画像
	DrawGraph(490, 5, Time_Image, true);
	DrawGraph(537, 20, Number2_Image[Time], true);
	DrawGraph(522, 20, Number3_Image[Time2], true);
	DrawGraph(506, 20, Number4_Image[Time3], true);
	//コイン画像
	DrawGraph(230, 20, Coin_Image[Coin_Count % 4], true);
	DrawGraph(245, 20, Number_Image[11], true);
	DrawGraph(260, 22, Number_Image[0], true);
	DrawGraph(275, 22, Number_Image[0], true);
	
}
