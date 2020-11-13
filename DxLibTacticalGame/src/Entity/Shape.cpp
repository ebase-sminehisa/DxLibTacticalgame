#include "Shape.h"

namespace Entity
{
	/**
	 * @fn
	 * �����蔻��i��Ƀ}�E�X�C�x��W�g�p�Ɏg�p�j
	 */
	bool Shape::isHit(int x, int y) const
	{
		if (type_ == RECT) 
		{
			return x_ <= x && x <= (x_ + w_) && y_ <= y && y <= y_ + h_;
		}
		return false;
	}

	/**
	 * @fn
	 * �ʒu�Z�b�g
	 */
	void Shape::set(int x, int y)
	{
		x_ = x;
		y_ = y;
	}

	/**
	 * @fn
	 * �ʒu�ƃT�C�Y�Z�b�g
	 */
	void Shape::set(int x, int y, int w, int h)
	{
		x_ = x;
		y_ = y;
		w_ = w;
		h_ = h;
	}

	/**
	 * @fn
	 * �ʒu�ƃT�C�Y�ƌ`��Z�b�g
	 */
	void Shape::set(int x, int y, int w, int h, int type)
	{
		x_ = x;
		y_ = y;
		w_ = w;
		h_ = h;
		type_ = type;
	}

	/**
	 * @fn
	 * �T�C�Y�Z�b�g
	 */
	void Shape::setSize(int w, int h)
	{
		w_ = w;
		h_ = h;
	}

	/**
	 * @fn
	 * �`��Z�b�g
	 */
	void Shape::setType(int type)
	{
		type_ = type;
	}
}