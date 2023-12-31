#include "DxLib.h"
#include "common.h"
#include "Fps.h"
#include "PadInput.h"
#include "SceneManager.h"
#include "GameMain.h"
#include "Title.h"

#define FLAME 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetMainWindowText("マリオ");  //タイトル設定
    
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    ChangeWindowMode(TRUE);		//ウィンドウモードで起動
    SetWindowIconID(01);

    if (DxLib_Init() == -1) return -1;	//DXライブラリの初期化処理

    SetDrawScreen(DX_SCREEN_BACK);  //描画先画面を裏にする

    SetFontSize(20);  //文字サイズを設定

    Fps fps;

    SceneManager sceneMng((AbstractScene*)new Title());
    //ゲームループ
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();  //画面の初期化

        sceneMng.Draw();

        ScreenFlip();  //裏画面の培養を表画面に反映

        PAD_INPUT::UpdateKey();

        fps.Wait();		//待機
    }

    DxLib_End();  //DXライブラリ使用の終了処理

    return 0;
}