#pragma once
#include <climits>
#include "DxLib.h"
#include "FrameWork/Controller.h"
#include "Shape.h"

namespace Entity
{
	class Object
	{
	public:
		Object() : isMouseDown_(false), isMouseOver_(false) {};
		Object(Shape* shape);
		~Object();

		bool isHit(int x, int y, int mouseStatus);
	private:
		/**
		 * @fn
		 * �}�E�X�����{�^���ŉ������ꂽ�u�Ԃ̏���
		 */
		void onMouseLeftDown() {};
		/**
		 * @fn
		 * �}�E�X�̍��{�^���������グ��ꂽ�u�Ԃ̏���
		 */
		void onMouseLeftUp() {};
		/**
		 * @fn
		 * �}�E�X�Ƀz�o�[���ꂽ�u�Ԃ̏���
		 */
		void onMouseOver() {};
		/**
		 * @fn
		 * �}�E�X���z�o�[��Ԃ��痣�ꂽ�Ƃ��̏���
		 */
		void onMouseOut() {};

		/**
		 * @fn
		 * �}�E�X���E�{�^���ŉ������ꂽ�u�Ԃ̏���
		 */
		void onMouseRightDown() {};
		/**
		 * @fn
		 * �}�E�X�̉E�{�^���������グ��ꂽ�u�Ԃ̏���
		 */
		void onMouseRightUp() {};

		/**
		 * @fn
		 * �}�E�X���z�C�[���{�^���ŉ������ꂽ�u�Ԃ̏���
		 */
		void onMouseWheelDown() {};
		/**
		 * @fn
		 * �}�E�X�̃z�C�[���{�^���������グ��ꂽ�u�Ԃ̏���
		 */
		void onMouseWheelUp() {};

		//! �I�u�W�F�N�g�̌`��(�ʒu��T�C�Y)
		Shape* shape_;

		//! �}�E�X�ɍ��{�^���ŉ�������Ă��邩�i�Ƃ肠�������{�^�������j
		bool isMouseDown_;

		//! �}�E�X�Ƀz�o�[����Ă��邩
		bool isMouseOver_;
	};
}