#pragma once
#include <iostream>
#include <algorithm>
namespace caches
{
	class SquareCache {
		mutable int _data[10000];

	public:
		SquareCache()  {
			std::fill(std::begin(_data), std::end(_data), -1);
		}
		int get_square(size_t ind) const {
			//if (ind >= sizeof(_data) / sizeof(T*))throw std::out_of_range{ "Too many items" };
			if (ind >= 10000) throw std::out_of_range{ "Outside range for data!" };
			//if (_data[ind] == nullptr) {
			if( _data[ind] == -1){
				_data[ind] = ind * ind;
				std::cout << "Computing the square of " << ind << std::endl;
			}
			return _data[ind];
		}
	};
}