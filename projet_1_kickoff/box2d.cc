#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"
#include "box2d_iterator.hh"
#include "box2d.hh"

// Fwd declarations
struct point2d;
class box2d_iterator;
class neighb2d_iterator;


class box2d {
public:
  using point      = point2d;
  using p_iterator = box2d_iterator;
  using n_iterator = neighb2d_iterator;

  box2d(){}

  box2d(const box2d& pBox)
  {
    iterator = new p_iterator(this);
	nrows = pBox.rows();
	ncols = pBox.cols();
  }

  box2d& operator=(const box2d& pBox)
  {
    iterator = new p_iterator(this);
  	nrows = pBox.rows();
	ncols = pBox.cols();
  }

  box2d(std::size_t prows, std::size_t pcols) : nrows(prows), ncols(pcols)
  {
	iterator = new p_iterator(this);
  }

  std::size_t rows() const
  {
  	  return nrows;
  }
  std::size_t cols() const
  {
  	  return ncols;
  }

  bool has(const point& p) const
  {
	  return(p.getX() < nrows && p.getY() < ncols);
  }

private:
  std::size_t nrows;
  std::size_t ncols;
  p_iterator iterator;
};


//bool          operator==(const box2d& lhs, const box2d& rhs);
//bool          operator!=(const box2d& lhs, const box2d& rhs);
//std::ostream& operator<<(std::ostream& oss, const box2d& rhs);
