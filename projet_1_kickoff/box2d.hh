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
  using p_iterator = box2d_iterator;
  using n_iterator = neighb2d_iterator;

  box2d()             = default;
  box2d(const box2d&) = default;
  box2d& operator=(const box2d&) = default;

  box2d(std::size_t nrows, std::size_t ncols);

  std::size_t rows() const;
  std::size_t cols() const;

  bool has(const point_type& p) const;

private:
  std::size_t rows{0};
  std::size_t cols{0};
  p_iterator iterator;
};


bool          operator==(const box2d& lhs, const box2d& rhs);
bool          operator!=(const box2d& lhs, const box2d& rhs);
std::ostream& operator<<(std::ostream& oss, const box2d& rhs);
