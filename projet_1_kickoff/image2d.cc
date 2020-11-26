#include "box2d.hh"
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

  explicit image2d(const box2d& d): box_(d){}
  explicit image2d(unsigned nrows, unsigned ncols)
  {
  	  box_.rows = nrows;
	  box_.cols = ncols;
  }

  T& operator()(const point2d& p)
  {
	if(box_.has(p))
		 return data_[p.x + p.y * box_.rows];
	return data_[0];		
  }

  T operator()(const point2d& p) const
  {
  	if(box_.has(p))
		 return data_[p.x + p.y * box_.rows];
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

  template<typename U, unsigned n>
  void fill_with(U ( &vals)[n]){
  	  for(unsigned i = 0; i < n; ++i)
		data_[i] = vals[i];
  }


private:
  box2d box_;
  std::vector<T> data_;
};
