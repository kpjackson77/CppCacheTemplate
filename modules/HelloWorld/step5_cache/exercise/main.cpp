#include <iostream>
#include "caches.h"
template<typename T>
void do_output(const T& sc) {
	std::cout << "Square of 3: " << sc.get_square(3) << std::endl;
	std::cout << "Square of 12: " << sc.get_square(12) << std::endl;
	std::cout << "Square of 3: " << sc.get_square(3) << std::endl;
	std::cout << "Square of 17: " << sc.get_square(17) << std::endl;
	std::cout << "Square of 12: " << sc.get_square(12) << std::endl;
	std::cout << "Square of 37: " << sc.get_square(37) << std::endl;
}
int main()
{
	using caches::SquareCache;
	{
		try {
			SquareCache<int> sc{};
			std::cout << "Square of 3: " << sc.get_square(3) << std::endl;
			std::cout << "Square of 12: " << sc.get_square(12) << std::endl;
			std::cout << "Square of 3: " << sc.get_square(3) << std::endl;
			std::cout << "Square of 17: " << sc.get_square(17) << std::endl;
			std::cout << "Square of 12: " << sc.get_square(12) << std::endl;
			std::cout << "Power of 999: " << sc.get_square(999) << std::endl;
			do_output(sc);
		}
		catch (const std::out_of_range& oor) {
			std::cout << "Out of range: " << oor.what() << std::endl;
		}
	}
	std::cout << "Hello World!\n";
	return 0;
}
