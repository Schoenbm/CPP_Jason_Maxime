#include "distance_map.hh"

#include <cstddef> // std::size_t
#include <limits>  // std::numeric_limits
#include <queue>   // std::queue


template <typename T>
inline image2d<unsigned> distance_map(const image2d<T>& input)
{
  const box2d box = input.box();
  const unsigned max = unsigned(-1);
  image2d<unsigned> dmap(input.bounding_box());

  box2d_iterator box_iterator(box);
  for(box_iterator.start(); box_iterator.is_valid(); box_iterator.next())
	dmap(box_iterator) = max;

  std::queue<point2d> q;
  neighb2d_iterator n_iterator;

  for(box_iterator.start(); box_iterator.is_valid(); box_iterator.next()){
  	  if(input(box_iterator) == true)
	  {
		dmap(box_iterator) = 0;
		n_iterator.center_at(box_iterator);
		for(n_iterator.start(); n_iterator.is_valid(); n_iterator.next()){
			if(box.has(n_iterator) && (input(n_iterator) == false))
			{
				q.push(box_iterator);
				break;
			}
		}
	  }
  }

  while (not q.empty())
  {
  	  point2d p = q.front();
	  q.pop();
	  n_iterator.center_at(p);
	  for(n_iterator.start(); n_iterator.is_valid(); n_iterator.next()){
	  	  if(box.has(n_iterator) && (dmap(n_iterator) == max)){
		  	  dmap(n_iterator) = dmap(p) + 1;
			  q.push(n_iterator);
		  }
	  }
  }
  return dmap;
}

