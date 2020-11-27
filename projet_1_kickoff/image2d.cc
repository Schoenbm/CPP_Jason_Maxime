#include "box2d.hh"


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

  explicit image2d(const box2d& d): box_(d){}
  explicit image2d(unsigned nrows, unsigned ncols)
  {
  	  box_.setRowsandCols(nrows, ncols);
  }

  T& operator()(const point2d& p)
  {
	if(box_.has(p))
		 return data_[p.x + p.y * box_.getRows()];
	return data_[0];
  }

  T operator()(const point2d& p) const
  {
  	if(box_.has(p))
		 return data_[p.x + p.y * box_.getRows()];
	return data_[0];
  }

  const box2d& box() const
  {
  	  return box_;
  }

  box2d bounding_box() const
  {
	  return box_;
  }

  void fill_with(const T vals[], const int pRows, const int pCols){
  	  for(int i = 0; i < pCols; ++i){
		for(int j = 0; j < pRows; j++){
			data_[i + j * pCols] = vals[i + j * pCols];
		}
	  }
  }




private:
  box2d box_;
  std::vector<T> data_;
};

template class image2d<int>;
template class image2d<unsigned>;
