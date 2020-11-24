#pragma once

#include <cstddef> // std::size_t
#include <vector>  // std::vector

class point2d;

class neighb2d_iterator {
public:
  neighb2d_iterator();
  neighb2d_iterator(const neighb2d_iterator&) = default;
  neighb2d_iterator& operator=(const neighb2d_iterator&) = default;

  explicit neighb2d_iterator(const point2d& p);

  void center_at(const point2d& p);

  void start();
  bool is_valid() const;
  void next();

  operator point2d() const;

private:
  const static std::vector<point2d> delta_;
  unsigned i_;
  point2d p_;
};
