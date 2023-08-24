#pragma once
#include "AbstractScene.h"
#include "Mario.h"
#include "UI.h"
#include "Enemy.h"



class GameMain : public AbstractScene
{
private:
	
	Mario Mario; //プレイヤー
	UI Ui;
	Enemy Enemy;
	int Haikei;
	int MapX;
	int Count;
public:
	GameMain();
	//デストラクト
	virtual ~GameMain()
	{
		//delete player;//newを作ったらdeleteを作る
	};
	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	virtual void Draw()const override;




};