#pragma once
#include "AbstractScene.h"
#include "Mario.h"
#include "Map.h"


class GameMain : public AbstractScene
{
private:
	
	Mario Mario;				//�v���C���[
	Map Map;
	int Haikei;
public:
	GameMain();
	//�f�X�g���N�g
	virtual ~GameMain()
	{
		//delete player;//new���������delete�����
	};
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	virtual void Draw()const override;


};