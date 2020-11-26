#pragma once

#include <cstddef> // std::size_t
#include <vector>  // std::vector

#include "point2d.hh"

class neighb2d_iterator {
public:
  neighb2d_iterator(){}
  
  neighb2d_iterator(const neighb2d_iterator& n)
  	:neighb2d_iterator{n.p_}
  {
  	delta_ = std::vector<point2d>(n.delta_);
  }
  
  neighb2d_iterator& operator=(const neighb2d_iterator& n)
  {
  	if (&n != this)
  	{
  		delta_ = std::vector<point2d>(n.delta_);
  		i_ = n.i_;
  		center_at(n.p_);
  	}
  	return *this;
  }

  explicit neighb2d_iterator(const point2d& p)
  {
  	unsigned x = p.getX();
  	unsigned y = p.getY();
  	delta_.push_back(*new point2d(x-1, y-1));
  	delta_.push_back(*new point2d(x-1, y));
  	delta_.push_back(*new point2d(x-1, y+1));
  	delta_.push_back(*new point2d(x, y-1));
  	delta_.push_back(*new point2d(x, y+1));
  	delta_.push_back(*new point2d(x+1, y-1));
  	delta_.push_back(*new point2d(x+1, y));
  	delta_.push_back(*new point2d(x+1, y+1));
  	i_ = 0;
  	center_at(p);
  }

  void center_at(const point2d& p)
  {
  	p_ = p;
  }

  void start()
  {
  }
  bool is_valid() const
  {
  	return (i_ < 8);
  }
  void next()
  {
  	i_+=1;
  	while (!is_valid())
  		i_+=1;
  	center_at(delta_[i_]);
  }

  operator point2d() const	
  {
  	point2d p;
  	p.setX(p_.getX() + delta_[i_].getX());
  	p.setY(p_.getY() + delta_[i_].getY());
  	return p;
  }

private:
  std::vector<point2d> delta_;
  unsigned i_;
  point2d p_;
};
