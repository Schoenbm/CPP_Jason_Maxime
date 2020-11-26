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
  //using point2d      = typename box2d::point2d;
  //using box_iterator = typename box2d::box_iterator;
  //using n_iterator   = typename box2d::neighb2d_iterator;

  explicit image2d(const domain_type& d);
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
  static_assert(!std::is_same_v<value_type, bool>, "value_type cannot be bool");
};
