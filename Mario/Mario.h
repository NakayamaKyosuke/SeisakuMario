#pragma once

class Mario
{
private:
	int Walk;
	bool Move;	//入力受付
	int MarioImage[4];
	int Marioimage;
	float speedinit;	//移動速度最大
	float Speed;	//移動速度
	float JumpPower;
	int Width, Height;
	int x, y;
	float MarioX, MarioY;
	int JoypadX, JoypadY;	//パッド入力値
	float PadangL;			//パッド入力角度
	int TriggerL, TriggerR;	//トリガー入力値

	float fall; //落下速度
	float fallinit;
	float vy, ga;
	int jump;	//ジャンプ回数
	bool jumping; //ジャンプ
	bool TurnFlg;
	bool MoveFlg;

public:
	bool GetMoveFlg()const {return MoveFlg; }
	float GetX()const { return x; }
	void InitPad();
	Mario();
	void Update();
	void Draw() const;

};

