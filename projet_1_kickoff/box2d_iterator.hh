#pragma once

#include <cstddef> // std::size_t

struct point2d;
struct box2d;
class box2d_iterator {
public:
  box2d_iterator()                      = default;
  box2d_iterator(const box2d_iterator&) = default;
  box2d_iterator& operator=(const box2d_iterator&) = default;

  explicit box2d_iterator(const box2d& d);

  void start();
  bool is_valid() const;
  void next();

  operator point2d() const;

private:
  // todo
};
