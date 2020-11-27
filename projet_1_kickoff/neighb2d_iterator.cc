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

  neighb2d_iterator& neighb2d::operator=(const neighb2d_iterator& n)
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
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	delta_.push_back(*new point2d());
  	i_ = 0;
  	center_at(p);
  }

  void center_at(const point2d& p)
  {
  	p_ = p;
  }

  void start()
  {
		i_ = 0;
		int p_x = p_.x;
		int p_y = p_.y;
		for(int i = 0; i <= 2; i++){
			for(int j = 0; j <= 2; j++){
				delta_[i + 3 * j].x = i - 1 + p_x;
				delta_[i + 3 * j].y = j - 1 + p_y;
			}
		}
  }

  bool is_valid() const
  {
  	return (i_ < 8);
  }
  void next()
  {
  	i_++;
  }

  operator point2d() const
  {
  	point2d p;
  	p.x = p_.x + delta_[i_].x;
  	p.y = p_.y + delta_[i_].y;
  	return p;
  }

private:
  static std::vector<point2d> delta_;
  unsigned i_;
  point2d p_;
};
