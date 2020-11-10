#include "FrameWork/Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	{
		DxLib::SetWindowTextA("DxLibTacticalGame");

		if (DxLib::ChangeWindowMode(true) != DX_CHANGESCREEN_OK
			|| DxLib::DxLib_Init() == -1
			|| DxLib::SetWindowSizeExtendRate(1.0) == -1
			)
		{
			return -1;
		}

		if (DxLib::SetDrawScreen(DX_SCREEN_BACK) == -1)
		{
			return -1;
		}

		FrameWork::Game& game = FrameWork::Game::getInstance();

		// int img = DxLib::LoadGraph("resource/test1.bmp");

		// �G�X�P�[�v�L�[�������ꂽ��I��
		while (DxLib::ProcessMessage() == 0
			&& DxLib::ClearDrawScreen() == 0)
		{
			// DxLib::DrawGraph (game.getFrame(), 0, img, TRUE);

			// ���C���̏���
			if (game.process() == -1) {
				break;
			}

			// ����ʂ�\�Ɏ����Ă���
			DxLib::ScreenFlip();
		}

		DxLib::DxLib_End();				// �c�w���C�u�����g�p�̏I������
	}

	return 0;					// �\�t�g�̏I��
}
