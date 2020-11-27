#include <cstddef> // std::size_t
#include "box2d_iterator.hh"


    box2d_iterator::box2d_iterator(const box2d& b)
    : box_(b)
  {
  }

  void box2d_iterator::start()
  {
      p_.x = 0;
      p_.y = 0;
  }

  bool box2d_iterator::is_valid() const
  {
	return box_.has(p_);
  }
  void box2d_iterator::next()
  {
	if (p_.x >= box_.getCols())
	{
		p_.x = 0;
		p_.y ++;
	}
	else{
		 p_.x ++;
	}
  }

  box2d_iterator::operator point2d() const
  {
	return p_;
  }

