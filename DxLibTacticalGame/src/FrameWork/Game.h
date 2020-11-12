#pragma once
#include <climits>
#include "DxLib.h"
#include "Controller.h"
#include "Object/Object.h"

using namespace Entity;

namespace
{
	const int FPS = 60;				// FPS
	const int ONE_FRAME_MS = 16;	// millsec per frame (16ms)
}

namespace FrameWork
{
	class Game
	{
	public:
		// for singleton
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		Game(Game&&) = delete;
		Game& operator=(Game&&) = delete;

		static Game& getInstance();
		int process();
		int getFrame() const;
		void increaseFrame();

	private:
		Game() : frame_(0), prevTime_(0) {};
		~Game() {};
		void controlFps();

		//! �t���[���J�E���g
		int frame_;

		//! ��������
		int waitTime_;

		//! �O�񎞍�
		int prevTime_;
	};
}