#include <iostream>
#include "caches.h"
template<typename T>
void do_output(const T& sc) {
	std::cout << "Square of 3: " << sc.get_power(3).value_or(-1) << std::endl;
	std::cout << "Square of 12: " << sc.get_power(12).value_or(-1) << std::endl;
	std::cout << "Square of 3: " << sc.get_power(3).value_or(-1)  << std::endl;
	std::cout << "Square of 17: " << sc.get_power(17).value_or(-1)  << std::endl;
	std::cout << "Square of 12: " << sc.get_power(12).value_or(-1)  << std::endl;
	std::cout << "Square of 37: " << sc.get_power(37).value_or(-1)  << std::endl;
}
int main()
{
	using caches::PowerCache;
	using caches::CubePolicy;
	using caches::SquarePolicy;
	{

		try {
			PowerCache<long,SquarePolicy,1000> sc{};
			std::cout << "Square of 3: " << sc.get_power(3).value_or(-1)  << std::endl;
			std::cout << "Square of 12: " << sc.get_power(12).value_or(-1)  << std::endl;
			std::cout << "Square of 3: " << sc.get_power(3).value_or(-1)  << std::endl;
			std::cout << "Square of 17: " << sc.get_power(17).value_or(-1)  << std::endl;
			std::cout << "Square of 12: " << sc.get_power(12).value_or(-1)  << std::endl;
			std::cout << "Power of 999: " << sc.get_power(999).value_or(-1)  << std::endl;
			do_output(sc);
		}
		catch (const std::out_of_range& oor) {
			std::cout << "Out of range: " << oor.what() << std::endl;
		}
	}
	std::cout << "Hello World!\n";
	return 0;
}
