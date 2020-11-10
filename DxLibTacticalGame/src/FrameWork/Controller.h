#pragma once
#include <climits>
#include "DxLib.h"

namespace
{
	const int	KEY_LEN = 256;
}

namespace FrameWork
{
	class Controller
	{
	public:
		// for singleton
		Controller(const Controller&) = delete;
		Controller& operator=(const Controller&) = delete;
		Controller(Controller&&) = delete;
		Controller& operator=(Controller&&) = delete;

		static Controller& getInstance();

		/**
		 * @enum KeyState
		 * �L�[�̓��͏��
		 */
		enum KeyState {
			NOT_PRESSED = 0,
			PRESSED = 1,
			PRESSED_NOW = 2
		};

		bool isKeyPressed(int input) const;
		bool isKeyPressedNow(int input) const;

		int getAllKeyPressed();
		void adjustKeyState();

	private:
		Controller() {};
		~Controller() {};

		char getKey(int input) const;

		//! �e�L�[�̓��͏��
		char key_[KEY_LEN];

		//! �e�L�[�̓��͏�ԁi�P�t���[���O�j
		char prevKey_[KEY_LEN];
	};
}