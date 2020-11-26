#pragma once

#include <cstddef> // std::size_t

struct point2d;
class box2d;

class box2d_iterator {
public:
  explicit box2d_iterator(const box2d& d);

  void start();
  bool is_valid() const;
  void next();

  operator point2d() const;

private:
  point2d current_p;
  box2d box;
};
