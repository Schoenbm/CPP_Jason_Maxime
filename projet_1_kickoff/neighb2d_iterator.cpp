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
  	for(unsigned i = 0; i<delta_.size(); i++) {}
  	return false;
  }
  void next()
  {
  	
  }

  operator point2d() const	
  {
  	point2d p;
  	p.setX(p_.getX() + delta_[i_].getX());
  	p.setY(p_.getY() + delta_[i_].getY());
  	return p;
  }

private:
  const static std::vector<point2d> delta_;
  unsigned i_;
  point2d p_;
};
