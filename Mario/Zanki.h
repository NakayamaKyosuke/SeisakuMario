#pragma once
#include "AbstractScene.h"
class Zanki :public AbstractScene
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

	int Count;

public:
	Zanki();
	~Zanki() {};
	virtual AbstractScene* Update()override;


	virtual void Draw()const override;
};

