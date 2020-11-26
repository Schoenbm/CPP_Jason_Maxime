#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"

struct box2d {

  bool has(const point2d& p) const
  {
	  return( p.x < rows && p.y < cols);
  }

  unsigned rows;
  unsigned cols;
};

