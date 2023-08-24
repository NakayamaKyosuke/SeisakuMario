#pragma once
class Enemy 
{

private:
	int Walk;
	int EnemyWalk;
	int EnemyImage[3];
	int x, y;
public:
	Enemy();
	~Enemy() {};
	void Update();
	void Draw() const;
};

