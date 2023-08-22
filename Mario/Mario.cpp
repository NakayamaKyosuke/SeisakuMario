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
//���ړ�
if (Move)
{
	//�X�e�B�b�N���͎�
	if (JoypadX >= MARGIN && Move) {
		Speed += 0.5;	//�ړ��ʂ����Z
		x = x + 3;
		TurnFlg = FALSE;				//������ς���
		Walk++;							//���s�A�j���[�V�����i�s
	}
	else if (JoypadX <= -MARGIN && Move) {
		Speed -= 0.5;	//�ړ��ʂ����Z
		x = x - 3;
		TurnFlg = TRUE;				//������ς���
	Walk++;							//���s�A�j���[�V�����i�s
	}
	//��X�e�B�b�N���͎�
	else
	{
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



//if (jumping == TRUE)
//{
//	vy = y;
//}




if (y <= SCREEN_HEIGHT - 100)
{
	y += fall;	//�㉺�ړ�

	//�����ƃW�����v
	float fallinit = 16;
	//A�{�^���E�W�����v
	//&& jumping == TRUE
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		//jumping = FALSE;
		fall = -fallinit;
	}

	//�������x�Ǘ�
	if (fall < fallinit)
	{
		//�������x�𑝂₷
		fall += (fallinit * 2) / 45;
		if (fall > fallinit)
		{
			fall = fallinit;	//�������x�̍ő�l
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