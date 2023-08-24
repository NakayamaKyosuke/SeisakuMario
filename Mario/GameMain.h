#pragma once
#include "AbstractScene.h"
#include "Mario.h"



class GameMain : public AbstractScene
{
private:
	
	Mario Mario;				//プレイヤー
	int Haikei;
	int MapX;
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