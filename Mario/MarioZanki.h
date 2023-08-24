#pragma once
#include "AbstractScene.h"
class MarioZanki :public AbstractScene
{
private:
	int MarioName_Image;
	int Coin_Image[4];
	int World_Image;
	int Time_Image;
	int Number_Image[15];
	int Select_Image;
	int Select2_Image;
	int MarioImage[4];

	int ICount;

public:
	MarioZanki();
	~MarioZanki() {};
	AbstractScene* Update()override;


	void Draw()const override;
};

