#pragma once

#include "box2d_iterator.hh"
#include "image2d.hh"
#include "neighb2d_iterator.hh"

#include <cstddef> // std::size_t
#include <limits>  // std::numeric_limits
#include <queue>   // std::queue


template <typename T>
image2d<std::size_t> distance_map(const image2d<T>& input)
{
  const box2d box = input.box();
  const unsigned max = unsigned(-1);
  image2d<unsigned> dmap(input.bounding_box());

  box2d_iterator box_iterator(box);
  for(box_iterator.start(); box_iterator.is_valid(); box_iterator.next())
	dmap(box_iterator) = max;

  std::queue<point2d> q;
  neighb2d_iterator n_iterator;

  for(p.start(); p.is_valid(); p.next()){
  	  if(input(p) == true)
  }
  return dmap;
}
