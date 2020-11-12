#pragma once

namespace Entity
{
	class Shape
	{
	public:
		Shape() : x_(0), y_(0), w_(0), h_(0) {};
		virtual ~Shape() {};
		virtual bool isHit(int x, int y) const = 0;

		void set(int x, int y);
		void set(int x, int y, int w, int h);
		void setSize(int w, int h);

	protected:
		//! 左座標
		int x_;
		//! 上座標
		int y_;
		//! 幅
		int w_;
		//! 高さ
		int h_;
	};
}