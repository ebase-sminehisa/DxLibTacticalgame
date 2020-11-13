#pragma once
#include <climits>
#include <list>
#include "DxLib.h"
#include "Controller.h"
#include "Entity/Object.h"
#include "Entity/Shape.h"

using namespace std;

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
		
		//! �e�X�g�p
		Entity::Object obj;

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

		//! �e�X�g�p
		bool isInit = true;
	};
}