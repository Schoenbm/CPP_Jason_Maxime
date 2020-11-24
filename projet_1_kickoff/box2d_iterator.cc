#include <cstddef> // std::size_t
#include "point2d.hh"
#include "box2d.hh"

class point2d;
class box2d;

class box2d_iterator {
public:
  box2d_iterator(){}
  explicit box2d_iterator(const box2d& b) : box(b){}

  void start()
  {
	delete(current_p*);
	current_p = new point2d(0,0);
  }

  bool is_valid() const
  {
	return box.has(current_p);
  }
  void next()
  {
	unsigned x,y;
	if (current_p.getX() >= box.cols())
	{
		x = 0;
		y = current_p.getY() + 1;
	}
	else{
		 x = current_p.getX() + 1;
		 y = current_p.getY();
	}

	delete(current_p*);
	current_p = new point2d(x,y);
  }

  operator point2d() const
  {
	current_p;
  }

private:
  point2d current_p;
  box2d box;
};
