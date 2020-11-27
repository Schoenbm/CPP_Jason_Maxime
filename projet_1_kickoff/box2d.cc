#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"
#include "box2d.hh"


  bool box2d::has(const point2d& p) const
  {
	  return( p.x < this->rows && p.y < this->cols);
  }


