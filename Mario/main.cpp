#include "DxLib.h"
#include "common.h"
#include "Fps.h"
#include "PadInput.h"
#include "SceneManager.h"
#include "GameMain.h"
#include "Title.h"

#define FLAME 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetMainWindowText("�}���I");  //�^�C�g���ݒ�
    
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    ChangeWindowMode(TRUE);		//�E�B���h�E���[�h�ŋN��
    SetWindowIconID(01);

    if (DxLib_Init() == -1) return -1;	//DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);  //�`����ʂ𗠂ɂ���

    SetFontSize(20);  //�����T�C�Y��ݒ�

    Fps fps;

    SceneManager sceneMng((AbstractScene*)new Title());
    //�Q�[�����[�v
    while (ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();  //��ʂ̏�����

        sceneMng.Draw();

        ScreenFlip();  //����ʂ̔|�{��\��ʂɔ��f

        PAD_INPUT::UpdateKey();

        fps.Wait();		//�ҋ@
    }

    DxLib_End();  //DX���C�u�����g�p�̏I������

    return 0;
}