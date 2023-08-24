#pragma once
#include "SceneManager.h"

#define HEIGHT 15
#define WIDTH 20
#define STAGE 11
#define CELL_SIXE_X 32
#define CELL_SIZE_Y 32

class map:public AbstractScene
{
private:
	int MapBlock_Image[23];
	int x;
	int y;
	int w;
	int h;

public:
	map();
	virtual ~map() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

};

