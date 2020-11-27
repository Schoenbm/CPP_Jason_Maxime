#include "neighb2d_iterator.hh"
#include "box2d_iterator.hh"
#include "image2d.hh"

#include <iostream> // std::cout
#include <queue>

constexpr int input_image_buffer[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, //
                                      0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
                                      0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
                                      0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, //
                                      0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, //
                                      0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, //
                                      0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, //
                                      0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, //
                                      0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, //
                                      0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, //
                                      0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, //
                                      0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, //
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1};

constexpr int expected_output_image_buffer[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 3, 4, 4, 4, 5, 6, 7, //
                                                        12, 11, 10, 9,  8, 7, 6, 5, 4, 3, 2, 2, 3, 3, 3, 4, 5, 6, //
                                                        11, 10, 9,  8,  7, 6, 5, 4, 3, 2, 1, 1, 2, 2, 2, 3, 4, 5, //
                                                        10, 9,  8,  7,  6, 5, 4, 3, 2, 1, 0, 0, 1, 1, 1, 2, 3, 4, //
                                                        9,  8,  7,  6,  5, 4, 3, 2, 3, 2, 1, 0, 0, 0, 0, 1, 2, 3, //
                                                        8,  7,  6,  5,  4, 3, 2, 1, 2, 1, 1, 0, 0, 0, 0, 1, 2, 3, //
                                                        7,  6,  5,  4,  3, 2, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 2, 3, //
                                                        6,  5,  4,  3,  3, 2, 1, 0, 1, 0, 0, 0, 0, 0, 1, 2, 3, 4, //
                                                        5,  4,  3,  2,  3, 2, 1, 0, 1, 1, 0, 0, 0, 0, 1, 2, 2, 3, //
                                                        4,  3,  2,  1,  2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, //
                                                        3,  2,  1,  0,  1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, //
                                                        3,  2,  1,  0,  1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, //
                                                        3,  2,  1,  0,  0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, //
                                                        2,  1,  0,  0,  0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 2, //
                                                        1,  0,  0,  0,  0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 2, //
                                                        1,  0,  0,  0,  0, 1, 1, 2, 1, 0, 1, 1, 2, 2, 1, 1, 2, 3, //
                                                        2,  1,  0,  0,  0, 1, 2, 2, 1, 0, 1, 1, 2, 2, 1, 0, 1, 2, //
                                                        3,  2,  1,  0,  1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 2, //
                                                        3,  2,  1,  1,  1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, //
                                                        2,  1,  0,  0,  0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, //
                                                        1,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, //
                                                        2,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};


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

int main()
{
  box2d my_domain;
  my_domain.setRowsandCols(22, 18);

  image2d<int>         input_image(my_domain);
  input_image.fill_with(input_image_buffer, my_domain.getRows(), my_domain.getCols());

  image2d<int> expected_output_image(my_domain);
  expected_output_image.fill_with(expected_output_image_buffer, my_domain.getRows(), my_domain.getCols());

  //std::cout << input_image << "---\n";
  //std::cout << expected_output_image << "---\n";

  const auto dmap = distance_map(input_image);
  //std::cout << dmap << "---\n";

  //std::cout << "Distance map OK ? " << (expected_output_image == dmap ? "yes" : "no") << std::endl;

  return 0;
}
