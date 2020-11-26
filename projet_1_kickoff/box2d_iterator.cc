#include <cstddef> // std::size_t
#include "point2d.hh"
#include "box2d.hh"


class box2d_iterator {
public:

  explicit box2d_iterator(const box2d& b)
  {
	box = b;
  }

  void start()
  {
	current_p.x = 0;
	current_p.y = 0;
  }

  bool is_valid() const
  {
	return box.has(current_p);
  }
  void next()
  {
	if (current_p.x >= box.cols)
	{
		current_p.x = 0;
		current_p.y ++;
	}
	else{
		 current_p.x ++;
	}
  }

  operator point2d() const
  {
	return current_p;
  }

private:
  point2d current_p;
  box2d box;
};
