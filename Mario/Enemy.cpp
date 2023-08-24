#include "Enemy.h"
#include "DxLib.h"
#include "common.h"
Enemy::Enemy()
{
	Walk = 0;
	EnemyWalk = 0;
	x = 640;
	y = SCREEN_HEIGHT - 95;
	LoadDivGraph("image/Enemy/kuribo.png", 3, 3, 1, 32, 32, EnemyImage);
}

void Enemy::Update()
{
	
	Walk++;
	if (Walk == 30)
	{
		EnemyWalk = 1;
	}
	if (Walk == 60)
	{
		EnemyWalk = 0;
		Walk = 0;
	}
	x = x - 1;
}

void Enemy::Draw() const
{
	DrawGraph(x, y, EnemyImage[EnemyWalk], true);
}

