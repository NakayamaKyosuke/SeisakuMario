#pragma once
#include"DxLib.h"
#include"common.h"

class  Player;

class Goomba
{
	int GoombaImage[3];       //�N���{�[�摜
	int Anim;
	int Enemy_x, Enemy_y;     //XY�̍��W
	int Width, Height;	      //�G�̍���


	bool Turnflg;             //�G�̌���

	bool MakeEnemy;           //�G�����

	int Speed;                //�G�̑��x

	//int MapData[MAP_HEIGHT][MWIDTH];   //�}�b�v�f�[�^
public:
	Goomba();

	virtual void Update();
	virtual void Draw()const;

	//���W�擾
	virtual int E_GetX()const { return Enemy_x; }
	virtual int E_GetY()const { return Enemy_y; }

	//���A�����擾
	virtual int GetWidth()const { return Width; }
	virtual int GetHeight()const { return Height; }

	////�G�z�u
	//virtual void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);
	//virtual void makeEnemy();

};

