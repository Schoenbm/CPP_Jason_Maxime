#pragma once

#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"

// Fwd declarations
class box2d_iterator;
class neighb2d_iterator;


struct box2d {
public:

  bool has(const point2d& p) const;

  unsigned rows;
  unsigned cols;
};
