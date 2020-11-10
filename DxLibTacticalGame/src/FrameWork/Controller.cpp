#include "Controller.h"

namespace FrameWork
{
	/**
	 * @fn
	 * �V���O���g���ɂ��邽�߂̃C���X�^���X�֐�
	 */
	Controller& Controller::getInstance()
	{
		static Controller instance;
		return instance;
	}

	/**
	 * @fn
	 * �ΏۃL�[��������������
	 * @return true:������
	 */
	bool Controller::isKeyPressed(int input) const
	{
		return getKey(input) != KeyState::NOT_PRESSED;
	}

	/**
	 * @fn
	 * �ΏۃL�[�����������u�Ԃ�����
	 * @return true:���������u��
	 */
	bool Controller::isKeyPressedNow(int input) const
	{
		return getKey(input) == KeyState::PRESSED_NOW;
	}

	/**
	 * @fn
	 * �S�ẴL�[�̏�Ԃ��擾
	 */
	int Controller::getAllKeyPressed()
	{
		return DxLib::GetHitKeyStateAll(key_);
	}

	/**
	 * @fn
	 * �L�[�̉�����Ԃ𒲐��i���������u�Ԃ̃L�[�̒l��ύX�j
	 */
	void Controller::adjustKeyState()
	{
		for (int i = 0; i < KEY_LEN; i++)
		{
			// compare previous state with current state
			if (prevKey_[i] == NOT_PRESSED && key_[i] == PRESSED)
			{
				key_[i] = PRESSED_NOW;  // if change state, set pressed state
			}
			prevKey_[i] = key_[i];
		}
	}

	/**
	 * @fn
	 * �ΏۃL�[�̏�Ԏ擾
	 */
	char Controller::getKey(int input) const
	{
		return key_[input];
	}
}