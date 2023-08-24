#include "Mario.h"
#include "PadInput.h"
#include "common.h"
#include <math.h>

#define JUMP_POWER 25
#define GRAVITY 2

Mario::Mario(){
	Walk = 0;
	Speed = 0;
	Move = true;

	DAFlag = false;
	TurnFlg = false;
	MoveFlg = false;
	Width = 32;
	Height = 32;
	vy = 0;
	TriggerL = 0;
	TriggerR = 0;
	fall = 0;
	jump = 0;
	jumping = false;
	JumpPower = 0;
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT - 80;
	MarioX = 0;
	MarioY = 0;
	JoypadX = 0;
	JoypadY = 0;
	//Marioimage=LoadGraph("image/Mario/mario.png");
	LoadDivGraph("image/Mario/mario.png", 9, 9, 1, 32, 32,MarioImage);
}

void Mario::Update() {
InitPad();
//���ړ�
if (Move)
{
	//�X�e�B�b�N���͎�
	if (JoypadX >= MARGIN && Move&& !PAD_INPUT::OnPressed(XINPUT_BUTTON_A)) {
		DAFlag = FALSE;
		MoveFlg = TRUE;
		Speed += 0.5;	//�ړ��ʂ����Z
		//x = x + 3;
		if (x <= 323&& MoveFlg == TRUE)
		{
			x = x + 3;
		}
		TurnFlg = FALSE;				//������ς���
		Walk++;							//���s�A�j���[�V�����i�s
	}
	else if (JoypadX <= -MARGIN && Move&& !PAD_INPUT::OnPressed(XINPUT_BUTTON_A)) {
		MoveFlg = TRUE;
		Speed -= 0.5;	//�ړ��ʂ����Z
		x = x - 3;
		TurnFlg = TRUE;				//������ς���
	Walk++;							//���s�A�j���[�V�����i�s
	}
	//����
	else if (JoypadX >= MARGIN && Move&& PAD_INPUT::OnPressed(XINPUT_BUTTON_A)) {
		MoveFlg = TRUE;
		DAFlag = TRUE;
		Speed += 1.5;	//�ړ��ʂ����Z
		//x = x + 3;
		if (x <= 323 && MoveFlg == TRUE)
		{
			x = x + 6;
		}
		TurnFlg = FALSE;				//������ς���
		Walk++;							//���s�A�j���[�V�����i�s
		
	}
	else if (JoypadX <= -MARGIN && Move&& PAD_INPUT::OnPressed(XINPUT_BUTTON_A)) {
		MoveFlg = TRUE;
		Speed -= 1.5;	//�ړ��ʂ����Z
		x = x - 3;
		TurnFlg = TRUE;				//������ς���
		Walk++;							//���s�A�j���[�V�����i�s
		
	}
	//��X�e�B�b�N���͎�
	else
	{
		MoveFlg = FALSE;
		//�ړ����x��0�ɋ߂Â���
		if (Speed < 0 && 0 < ++Speed) {
			Speed = 0;
		}

		if (0 < Speed && --Speed < 0) {
			Speed = 0;
		}
		Walk = 0;	//���s�A�j���[�V�����Z�b�g
	}
	if (40 <= Walk)Walk = 0;
}


	//�����ƃW�����v
	float fallinit = 16;
	//A�{�^���E�W�����v
	//&& jumping == TRUE
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)&&jumping==false)
	{
		JumpPower = JUMP_POWER;
		jumping = true;
	}

	if (jumping)
	{
		JumpPower -= GRAVITY;
		y -= JumpPower;
	}
	

	if (y >= SCREEN_HEIGHT - 80)
	{
		y= SCREEN_HEIGHT - 80;
		jumping = false;
	}
	else
	{
		y += GRAVITY;
	}

	if (x  <= 20)
	{
		x = 20;
	}


if (12 <= Walk)Walk = 0;
	
}

void Mario::Draw()const
{
	int fix = 0;
	DrawRotaGraph(x,y, 1.0f, 0, MarioImage[Walk/3], TRUE, TurnFlg);
	DrawFormatString(0, 0, 0x000000, "%d",x);
}

void Mario::InitPad()
{
	//�X�e�B�b�N
	JoypadX = PAD_INPUT::GetPadThumbLX();
	JoypadY = PAD_INPUT::GetPadThumbLY();

	//�g���K�[
	TriggerL = PAD_INPUT::GetPadLeftTrigger();
	TriggerR = PAD_INPUT::GetPadRightTrigger();

	//���͊p�x
	float angle = atan2((float)JoypadX, (float)JoypadY);
	if (angle < 0)angle += 3.14;

	angle = angle / 2 / 3.14 * 360;
	if (JoypadX < 0)angle -= 180;
	
	PadangL = angle;
}