#pragma once

class Mario
{
private:
	int Walk;
	bool Move;	//���͎�t
	int MarioImage[4];
	int Marioimage;
	float speedinit;	//�ړ����x�ő�
	float Speed;	//�ړ����x

	int Width, Height;
	int x, y;

	int JoypadX, JoypadY;	//�p�b�h���͒l
	float PadangL;			//�p�b�h���͊p�x
	int TriggerL, TriggerR;	//�g���K�[���͒l

	float fall; //�������x
	float fallinit;
	float vy, ga;
	int jump;	//�W�����v��
	bool jumping; //�W�����v
	bool TurnFlg;

public:

	void InitPad();
	Mario();
	void Update();
	void Draw() const;

};

