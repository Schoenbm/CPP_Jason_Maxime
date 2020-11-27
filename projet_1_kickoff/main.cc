#include "distance_map.hh"
#include "image2d.hh"

#include <iostream> // std::cout


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


int main()
{
  box2d my_domain;
  my_domain.rows = 22;
  my_domain.cols = 18;

  image2d<int>         input_image(my_domain);
  input_image.fill_with(input_image_buffer, my_domain.rows, my_domain.cols);

  image2d<int> expected_output_image(my_domain);
  expected_output_image.fill_with(expected_output_image_buffer, my_domain.rows, my_domain.cols);

  //std::cout << input_image << "---\n";
  //std::cout << expected_output_image << "---\n";

  image2d<unsigned> dmap = distance_map<int>(input_image);
  //std::cout << dmap << "---\n";

  //std::cout << "Distance map OK ? " << (expected_output_image == dmap ? "yes" : "no") << std::endl;

  return 0;
}
