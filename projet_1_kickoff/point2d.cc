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

		int getX() const;
		int getY() const;

	private:
		int x{0};
		int y{0};
};