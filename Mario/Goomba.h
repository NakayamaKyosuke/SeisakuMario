#pragma once
#include"DxLib.h"
#include"common.h"

class  Player;

class Goomba
{
	int GoombaImage[3];       //クリボー画像
	int Anim;
	int Enemy_x, Enemy_y;     //XYの座標
	int Width, Height;	      //敵の高さ


	bool Turnflg;             //敵の向き

	bool MakeEnemy;           //敵を作る

	int Speed;                //敵の速度

	//int MapData[MAP_HEIGHT][MWIDTH];   //マップデータ
public:
	Goomba();

	virtual void Update();
	virtual void Draw()const;

	//座標取得
	virtual int E_GetX()const { return Enemy_x; }
	virtual int E_GetY()const { return Enemy_y; }

	//幅、高さ取得
	virtual int GetWidth()const { return Width; }
	virtual int GetHeight()const { return Height; }

	////敵配置
	//virtual void SetMapData(int MapData[MAP_HEIGHT][MAP_WIDTH]);
	//virtual void makeEnemy();

};

