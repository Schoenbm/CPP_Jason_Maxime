#pragma once

#include "box2d.hh"
#include "box2d_iterator.hh"
#include "utils.hh"

#include <cassert>     // assert
#include <cstddef>     // std::size_t
#include <type_traits> // std::is_same
#include <vector>      // std::vector


template <typename T>
class image2d {
public:
  using value_type      = T;

  explicit image2d(const box2d& d);
  explicit image2d(unsigned nrows, unsigned ncols);

  T& operator()(const point2d& p);
  T operator()(const point2d& p) const;

  const box2d& box() const;
  box2d bounding_box() const;

  template<typename U, unsigned n>
  void fill_with(U ( &vals)[n]);


private:
  box2d box_;
  std::vector<T> data_;
};
