#pragma once
#define SIZE_W 32
#define SIZE_H 32
class Mario
{
private:
	int Walk;
	bool Move;	//���͎�t
	int MarioImage[4];
	int Marioimage;
	float speedinit;	//�ړ����x�ő�
	float Speed;	//�ړ����x
	float JumpPower;
	int Width, Height;
	int x, y;
	float MarioX, MarioY;
	int JoypadX, JoypadY;	//�p�b�h���͒l
	float PadangL;			//�p�b�h���͊p�x
	int TriggerL, TriggerR;	//�g���K�[���͒l

	float fall; //�������x
	float fallinit;
	float vy, ga;
	int jump;	//�W�����v��
	bool jumping; //�W�����v
	bool TurnFlg;
	bool MoveFlg;
	bool DAFlag;

public:
	bool GetMoveFlg()const {return MoveFlg; }
	bool GetDA()const { return DAFlag; }
	float GetX()const { return x; }
	float GetY()const { return y; }
	void InitPad();
	Mario();
	void Update();
	void Draw() const;

};

