#include <iostream>


auto my_max(auto a, auto b) {
    return (a > b) ? a : b;
}
// template<typename T>
// T my_max(T a, T b) {
//     return (a > b) ? a : b;
// }

int main() {
    {
        auto result = my_max("Hello", "Greetings");
        std::cout << "Max of Hello and Greetings is: " << result << std::endl;
    }
    {
        auto result = my_max(1, 2);
        std::cout << "Max of 1 and 2 is: " << result << std::endl;
    }
    {
        auto result = my_max<int>(1, 2);
        std::cout << "Max of 1 and 2 is: " << result << std::endl;
    }
    std::cout << "Hello World!" << std::endl;

    return 0;
}

