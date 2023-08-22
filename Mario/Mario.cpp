#include "Mario.h"
#include "PadInput.h"
#include "common.h"
#include <math.h>

Mario::Mario(){
	Walk = 0;
	Speed = 0;
	Move = true;

	TurnFlg = false;

	Width = 32;
	Height = 32;
	vy = 0;
	TriggerL = 0;
	TriggerR = 0;
	fall = 0;
	jump = 0;
	jumping = false;
	x = (SCREEN_WIDTH - Width) / 2;
	y = 0;
	JoypadX = 0;
	JoypadY = 0;
	//Marioimage=LoadGraph("image/Mario/mario.png");
	LoadDivGraph("image/Mario/mario.png", 9, 9, 1, 32, 32,MarioImage);
}

void Mario::Update() {
InitPad();
//横移動
if (Move)
{
	//スティック入力時
	if (JoypadX >= MARGIN && Move) {
		Speed += 0.5;	//移動量を加算
		x = x + 3;
		TurnFlg = FALSE;				//向きを変える
		Walk++;							//歩行アニメーション進行
	}
	else if (JoypadX <= -MARGIN && Move) {
		Speed -= 0.5;	//移動量を減算
		x = x - 3;
		TurnFlg = TRUE;				//向きを変える
	Walk++;							//歩行アニメーション進行
	}
	//非スティック入力時
	else
	{
		//移動速度を0に近づける
		if (Speed < 0 && 0 < ++Speed) {
			Speed = 0;
		}

		if (0 < Speed && --Speed < 0) {
			Speed = 0;
		}
		Walk = 0;	//歩行アニメーショリセット
	}
	if (40 <= Walk)Walk = 0;
}



//if (jumping == TRUE)
//{
//	vy = y;
//}




if (y <= SCREEN_HEIGHT - 100)
{
	y += fall;	//上下移動

	//落下とジャンプ
	float fallinit = 16;
	//Aボタン・ジャンプ
	//&& jumping == TRUE
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		//jumping = FALSE;
		fall = -fallinit;
	}

	//落下速度管理
	if (fall < fallinit)
	{
		//落下速度を増やす
		fall += (fallinit * 2) / 45;
		if (fall > fallinit)
		{
			fall = fallinit;	//落下速度の最大値
		}

	}
	//y = y + 5;

	/*if (y == SCREEN_HEIGHT - 100)
	{
		jumping = TRUE;
	}*/
}



if (12 <= Walk)Walk = 0;
	
}

void Mario::Draw()const
{
	int fix = 0;
	DrawRotaGraph(x,y, 1.0f, 0, MarioImage[Walk/3], TRUE, TurnFlg);
}

void Mario::InitPad()
{
	//スティック
	JoypadX = PAD_INPUT::GetPadThumbLX();
	JoypadY = PAD_INPUT::GetPadThumbLY();

	//トリガー
	TriggerL = PAD_INPUT::GetPadLeftTrigger();
	TriggerR = PAD_INPUT::GetPadRightTrigger();

	//入力角度
	float angle = atan2((float)JoypadX, (float)JoypadY);
	if (angle < 0)angle += 3.14;

	angle = angle / 2 / 3.14 * 360;
	if (JoypadX < 0)angle -= 180;
	
	PadangL = angle;
}