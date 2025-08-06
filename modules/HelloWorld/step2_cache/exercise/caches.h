#pragma once
#include <iostream>
#include <algorithm>
namespace caches
{
	class MemoryPool{
		char *_data;
		int *_next;
	public:
		MemoryPool():_data{new char[100000]},_next{reinterpret_cast<int*>(_data)}{}
		void *get_next(){  return _next++;}
	};
	class SquareCache {
		mutable int *_data[10000];
		mutable MemoryPool _pool;
	public:
		SquareCache()  {
			std::fill(std::begin(_data), std::end(_data), nullptr);
		}
		int get_square(size_t ind) const {
			//if (ind >= sizeof(_data) / sizeof(T*))throw std::out_of_range{ "Too many items" };
			if (ind >= 10000) throw std::out_of_range{ "Outside range for data!" };
			//if (_data[ind] == nullptr) {
			if( !_data[ind] ){
				_data[ind] = new (_pool.get_next()) int(ind * ind);
				std::cout << "Computing the square of " << ind << std::endl;
			}
			return *_data[ind];
		}
	};
}