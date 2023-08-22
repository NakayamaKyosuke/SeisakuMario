#pragma once
#include "AbstractScene.h"
#include "Mario.h"
#include "Map.h"


class GameMain : public AbstractScene
{
private:
	
	Mario Mario;				//プレイヤー
	Map Map;
	int Haikei;
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