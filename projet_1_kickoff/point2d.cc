#include <iosfwd> // std::ostream fwd declaration


class point2d{
	public:
		point2d(){}

		point2d(const point2d& pPoint)
		{
			x = pPoint.getX();
			y = pPoint.getY();
		}
		explicit point2d(const int pX, const int pY): x(pX), y(pY)
		{}

		unsigned getX() const {return x;}
		unsigned getY() const {return y;}

		void setX(unsigned pX){ x = pX;}
		void setY(unsigned pY){ y = pY;}

	private:
		unsigned x{0};
		unsigned y{0};
};