#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"
#include "neighb2d_iterator.hh"
#include "box2d_iterator.hh"

class box2d {

  bool has(const point2d& p) const
  {
	  return( p.getX() < rows && p.getY() < cols);
  }

  unsigned rows;
  unsigned cols;
};

