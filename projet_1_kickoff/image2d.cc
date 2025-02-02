#include "image2d.hh"

#include <ostream>
#include <cassert>     // assert
#include <cstddef>     // std::size_t
#include <type_traits> // std::is_same
#include <vector>      // std::vector

template <typename T>
image2d<T>::image2d(const box2d& d): box_(d) , data_(box_.getRows()*box_.getCols())
{}

template <typename T>  
image2d<T>::image2d(unsigned nrows, unsigned ncols)
{
	  box_.setRowsandCols(nrows, ncols);
}

template <typename T>
  T& image2d<T>::operator()(const point2d& p)
  {
	if(box_.has(p))
		 return data_[p.x + p.y * box_.getRows()];
	return data_[0];
  }
template <typename T>
  T image2d<T>::operator()(const point2d& p) const
  {
  	if(box_.has(p))
		 return data_[p.x + p.y * box_.getRows()];
	return data_[0];
  }
  
  template <typename T>
  const box2d& image2d<T>::box() const
  {
  	  return box_;
  }

  template <typename T>
  box2d image2d<T>::bounding_box() const
  {
	  return box_;
  }

  template <typename T>
  void image2d<T>::fill_with(const T vals[], const int pRows, const int pCols){
  	  for(int i = 0; i < pCols; ++i){
		for(int j = 0; j < pRows; j++){
			data_[i + j * pCols] = vals[i + j * pCols];
		}
	  }
  }

 // template <typename T>
 // std::ostream& operator<<(std::ostream& oss, const image2d<T>& rhs)
//{
 // box2d& pBox = rhs.bounding_box();
 // for (unsigned i = 0; i < pBox.getCols(); ++i) {
 //   oss << "|";
 //   for (unsigned j = 0; j < pBox.getRows() - 1; ++j) {
 //     oss << rhs(i, j) << ", ";
 //   }
 //   oss << rhs(i, pBox.getRows() - 1) << "|\n";
 // }

 // return oss;
//}

template class image2d<int>;
template class image2d<unsigned>;
