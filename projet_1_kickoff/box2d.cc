#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"

// Fwd declarations
//class point2d;

class box2d {
public:
  using point = point2d;

  box2d(){}

  box2d(const box2d& pBox)
  {
	nrows = pBox.rows();
	ncols = pBox.cols();
  }

  box2d(unsigned prows, unsigned pcols) : nrows(prows), ncols(pcols)
  {}

  unsigned rows() const
  {
  	  return nrows;
  }
  unsigned cols() const
  {
  	  return ncols;
  }

  bool has(const point& p) const
  {
	  return( p.getX() < nrows && p.getY() < ncols);
  }

private:
  unsigned nrows;
  unsigned ncols;
};

//std::size_t
//bool          operator==(const box2d& lhs, const box2d& rhs);
//bool          operator!=(const box2d& lhs, const box2d& rhs);
//std::ostream& operator<<(std::ostream& oss, const box2d& rhs);
