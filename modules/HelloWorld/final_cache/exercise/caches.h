#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
namespace caches
{
	template<typename T, size_t SIZE = 10000>
	class MemoryPool {
		char _pool[SIZE]{};
		mutable char* _next;
	public:
		MemoryPool() :_next{ _pool } {}
		void* get_next()const {

			void* temp = _next;
			if (temp > (_pool + sizeof(_pool)))throw std::out_of_range{ "Beyond end of pool!" };
			_next += sizeof(T);
			return temp;
		}
	};
	template<typename T>	class SquarePolicy {
	public:
		static T get_power(T val) { return val * val; }
	};
	template<typename T>	class CubePolicy {
	public:
		static T get_power(T val) { return val * val * val; }
	};
	void my_deleter(void*);
	struct MyDeleter {
		void operator()(void*){}
	};
	template<typename T, template<typename> class Policy = SquarePolicy, size_t SIZE = 1000>
	class PowerCache {
		mutable std::map<size_t,std::shared_ptr<T>> _data;
		MemoryPool<T, SIZE * sizeof(T)> _pool;
	public:
		PowerCache()  {
			//_data.reserve(SIZE);
			//for (size_t i = 0; i < SIZE; ++i) {//sizeof(_data) / sizeof(int*); i++) {
			//	_data.push_back(nullptr);
			//}
		}
		T get_power(size_t ind) const {
			//if (ind >= sizeof(_data) / sizeof(T*))throw std::out_of_range{ "Too many items" };
			//if (_data[ind] == nullptr) {
			if( _data.find(ind) == _data.end()){
				//const_cast<int&>(_data[ind]) = ind * ind;
				_data[ind] = std::shared_ptr<T>{ new (_pool.get_next()) T { Policy<T>::get_power(static_cast<int>(ind))},[](T* p){p->~T();}};//MyDeleter{}};//my_deleter };
				std::cout << "Computing the square of " << ind << std::endl;
			}
			return *_data[ind];
		}
		//int get_something();
	};
}