#pragma once
#include "AbstractScene.h"
#include"common.h"
#include"Mario.h"
#include"Item.h"
#include"UI.h"
#define BSIZE_X 32
#define BSIZE_Y 32
#define BNUM_CHIP_X 1
#define BNUM_CHIP_Y 1
#define BNUM_MAP_X 40
#define BNUM_MAP_Y 22
#define BNUM_CHIP_ALL 1

class Map : public AbstractScene
{
private:
	
	int chip[BNUM_CHIP_ALL];

	int data[1000];
	static  int bh;

	Mario player;

public:
	//�f�X�g���N�g
	virtual ~Map()
	{
		//delete player;//new���������delete�����
	};
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�����������
	virtual void Draw()const override;

	 Map();
};