#include "Game.h"

namespace FrameWork
{
	/**
	 * @fn
	 * �V���O���g���ɂ��邽�߂̃C���X�^���X�֐�
	 */
	Game& Game::getInstance()
	{
		static Game instance;
		return instance;
	}

	/**
	 * @fn
	 * FPS�Ǘ��p
	 */
	void Game::controlFps()
	{
		waitTime_ = DxLib::GetNowCount() - prevTime_; // calculate 1 loop time
		if (prevTime_ == 0)
		{
			waitTime_ = ONE_FRAME_MS;
		}
		prevTime_ = DxLib::GetNowCount();  // set current time
		// adjust to 60 fps
		if (ONE_FRAME_MS > waitTime_)
		{
			Sleep(static_cast<DWORD>(ONE_FRAME_MS - waitTime_));
		}
	}

	/**
	 * @fn
	 * �t���[�����J�E���g(int�ő�l�Ń��[�v)
	 */
	void Game::increaseFrame()
	{
		frame_++;
		if (frame_ >= INT_MAX)
		{
			frame_ = 0;
		}
	}

	/**
	 * @fn
	 * �t���[���J�E���g�����擾
	 * @return �t���[���J�E���g��
	 */
	int Game::getFrame() const
	{
		return frame_;
	}

	/**
	 * @fn
	 * �t���[���Ǘ��p�Ƀ��[�v�ŌĂ΂�鏈��
	 */
	void Game::control()
	{
		controlFps();  // keep 60 fps
		increaseFrame();
	}
}