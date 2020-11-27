#pragma once
#include "point2d.hh"
#include <cstddef> // std::size_t
#include <vector>  // std::vector

struct point2d;

class neighb2d_iterator {
public:
  neighb2d_iterator();
  neighb2d_iterator(const neighb2d_iterator&);
  neighb2d_iterator& operator=(const neighb2d_iterator&);

  explicit neighb2d_iterator(const point2d& p);

  void center_at(const point2d& p);

  void start();
  bool is_valid() const;
  void next();

  operator point2d() const;

private:
  std::vector<point2d> delta_;
  unsigned i_;
  point2d p_;
};
