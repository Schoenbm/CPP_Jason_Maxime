#pragma once

#include "box2d_iterator.hh"
#include "image2d.hh"
#include "neighb2d_iterator.hh"

#include <cstddef> // std::size_t
#include <limits>  // std::numeric_limits
#include <queue>   // std::queue


template <typename T>
inline image2d<unsigned> distance_map(const image2d<T>& input);
