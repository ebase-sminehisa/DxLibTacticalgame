#include "Rect.h"

namespace Entity
{
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
	 * �T�C�Y�Z�b�g
	 */
	void Shape::setSize(int w, int h)
	{
		w_ = w;
		h_ = h;
	}
}