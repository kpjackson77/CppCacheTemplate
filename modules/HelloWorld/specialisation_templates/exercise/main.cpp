#include <iostream>


// auto my_max(auto a, auto b) {
//     return (a > b) ? a : b;
// }
template<typename T>
T my_max(T a, T b) {
    return (a > b) ? a : b;
}
const char* my_max(const char* a, const char* b) {
    return (std::string(a) > std::string(b)) ? a : b;
}
int main() {
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

