#pragma once

#include <iosfwd> // std::ostream fwd declaration


class point2d{
	public:
		point2d();
		point2d(const point2d& pPoint);
		explicit point2d(const int pX, const int pY);

		unsigned getX() const;
		unsigned getY() const;

	private:
		unsigned x;
		unsigned y;
};