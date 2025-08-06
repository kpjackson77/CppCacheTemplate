#pragma once
#include <iostream>
#include <algorithm>
namespace caches
{
	template<typename T, size_t SIZE = 100000>
	class MemoryPool{
		char *_data;
		T *_next;
	public:
		MemoryPool():_data{new char[SIZE]},_next{reinterpret_cast<T*>(_data)}{}
		void *get_next(){  return _next++;}
	};
	template<typename T, size_t SIZE = 10000>
	class SquareCache {
		mutable T *_data[SIZE];
		mutable MemoryPool<T, SIZE*sizeof(T)> _pool;
	public:
		SquareCache()  {
			std::fill(std::begin(_data), std::end(_data), nullptr);
		}
		T get_square(size_t ind) const {
			//if (ind >= sizeof(_data) / sizeof(T*))throw std::out_of_range{ "Too many items" };
			if (ind >= 10000) throw std::out_of_range{ "Outside range for data!" };
			//if (_data[ind] == nullptr) {
			if( !_data[ind] ){
				_data[ind] = new (_pool.get_next()) T(ind * ind);
				std::cout << "Computing the square of " << ind << std::endl;
			}
			return *_data[ind];
		}
	};
}