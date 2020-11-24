#pragma once

#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration


// Fwd declarations
struct point2d;
class box2d_iterator;
class neighb2d_iterator;


class box2d {
public:
  using point      = point2d;

  box2d();
  box2d(const box2d& pBox);
  box2d(unsigned prows, unsigned pcols);

  unsigned rows() const;
  unsigned cols() const;

  bool has(const point& p) const;

private:
  unsigned nrows;
  unsigned ncols;
};
