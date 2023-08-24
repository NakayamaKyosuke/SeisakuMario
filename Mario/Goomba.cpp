#include "Goomba.h"
#include"DxLib.h"
#include"common.h"
#include"GameMain.h"

#include<math.h>

#define MAX_SPPED 3
#define MIM_SPPED -3

Goomba::Goomba()
{
	 //GoombaImage[3];       //クリボー画像

	//座標
	Enemy_x = 0;
	Enemy_y = 0;

	//マップデータ
	//MapData[Enemy_x][Enemy_y];

	//サイズ
	Width = 32;
	Height = 32;

	Anim = 0;
	Turnflg = false;

	MakeEnemy = FALSE;

	Speed = 0;

	LoadDivGraph("image/Enemy/kuribo.png", 3, 3, 1, 32, 32, GoombaImage);
	
}

void Goomba::Update()
{
	////移動
	//if (Turnflg)
	//{
	//	Enemy_x -= 3;
	//	//壁に当たった時
	//	if (!MapData[Enemy_y / BLOCK_SIZE][(Enemy_x - Width / 2) / BLOCK_SIZE] ||
	//		MapData[(Enemy_y + Height / 2 + 1) / BLOCK_SIZE][(Enemy_x - Width / 2) / BLOCK_SIZE])
	//	{
	//		Turnflg = !Turnflg;
	//	}
	//}
	//else
	//{
	//	Enemy_x += 3;
	//	if (!MapData[Enemy_y / BLOCK_SIZE][(Enemy_x - Width / 2) / BLOCK_SIZE] ||
	//		MapData[(Enemy_y + Height / 2 + 1) / BLOCK_SIZE][(Enemy_x - Width / 2) / BLOCK_SIZE])
	//	{
	//		Turnflg = !Turnflg;
	//	}
	//}



}
//void Goomba::makeEnemy()
//{
//	MakeEnemy = FALSE;
//	while (MakeEnemy == FALSE)
//	{
//
//	}
//}

void Goomba::Draw()const
{
	if (MakeEnemy == TRUE)
	{

	}
}