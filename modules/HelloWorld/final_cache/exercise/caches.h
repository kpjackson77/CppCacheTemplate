#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <optional>
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
	template<typename T> class SquarePolicy {
	public:
		static T get_power(T val) { return val * val; }
	};
	template<typename T> class CubePolicy {
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
		PowerCache()  {	}
		std::optional<T> get_power(size_t ind) const {
		
			if (ind >= SIZE) throw std::out_of_range{ "Outside range for data!" };

			if( _data.find(ind) == _data.end()){

				_data[ind] = std::shared_ptr<T>{ new (_pool.get_next()) T { Policy<T>::get_power(static_cast<int>(ind))},[](T* p){p->~T();}};//MyDeleter{}};//my_deleter };
				std::cout << "Computing the square of " << ind << std::endl;
			}
			return *_data[ind];
		}
	};
}