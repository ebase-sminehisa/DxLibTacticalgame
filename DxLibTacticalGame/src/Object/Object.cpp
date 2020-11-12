#include "Object.h"
using namespace FrameWork;

namespace Entity {

	Object::Object (Shape* shape)
	{
		shape_ = shape;
		isMouseDown_ = false;
		isMouseOver_ = false;
	}

	/**
	 * @fn
	 * �����蔻��i��Ƀ}�E�X�C�x���g�p�Ɏg�p�j
	 */
	bool Object::isHit(int x, int y, int mouseStatus)
	{
		if (shape_ != nullptr) 
		{
			bool isHit = shape_->isHit(x, y);

			// �}�E�X�|�C���^���ڐG
			if (isHit) 
			{
				if (mouseStatus == Controller::MOUSE_LEFT_DOWN)
				{
					onMouseLeftDown(); // ��������
				}
				else if (mouseStatus == Controller::MOUSE_LEFT_UP)
				{
					onMouseLeftUp(); // ��������
				}
				else if (mouseStatus == Controller::MOUSE_RIGHT_DOWN)
				{
					onMouseRightDown(); // �E������
				}
				else if (mouseStatus == Controller::MOUSE_RIGHT_UP)
				{
					onMouseRightUp(); // �E������
				}
				else if (mouseStatus == Controller::MOUSE_WHEEL_DOWN)
				{
					onMouseWheelDown(); // �z�C�[��������
				}
				else if (mouseStatus == Controller::MOUSE_WHEEL_UP)
				{
					onMouseWheelUp(); // �z�C�[��������
				}
				isMouseOver_ = true;
			}
			else if (isMouseOver_)
			{
				// �}�E�X�|�C���^��ڐG���@���@1�t���[���O�܂ŐڐG���Ă����ꍇ
				onMouseOut(); // �z�o�[�A�E�g
				isMouseOver_ = false;
				isMouseDown_ = false;
			}
		}
		return false;
	}

	/**
	 * @fn
	 * �f�X�g���N�^
	 */
	Object::~Object()
	{
		delete shape_;
	}
}