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
  using domain_type     = box2d;
  using point_type      = typename domain_type::point_type;
  using p_iterator_type = typename domain_type::p_iterator_type;
  using n_iterator_type = typename domain_type::n_iterator_type;

  template <typename U>
  using with_value_type = image2d<U>;

  image2d()               = default;
  image2d(const image2d&) = default;
  image2d& operator=(const image2d&) = default;

  explicit image2d(const domain_type& d);
  template <std::size_t N>
  image2d(const domain_type& d, const value_type (&data)[N]);
  image2d(const domain_type& d, value_type v);
  image2d(std::size_t nrows, std::size_t ncols);
  template <std::size_t N>
  image2d(std::size_t nrows, std::size_t ncols, const value_type (&data)[N]);
  image2d(std::size_t nrows, std::size_t ncols, value_type v);

  value_type& operator()(const point_type& p);
  value_type  operator()(const point_type& p) const;

  const domain_type& domain() const;

  template <std::size_t N>
  void fill_with(const value_type (&data)[N]);

private:
  // todo

  static_assert(!std::is_same_v<value_type, bool>, "value_type cannot be bool");
};
