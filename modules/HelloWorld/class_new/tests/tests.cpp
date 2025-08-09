#include <algorithm>
#include <cctype>
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "../../../include/utilities.h"
namespace local
{
#include "../exercise/main.cpp"
}
std::string getStdoutFromCommand(const std::string &command) {
  std::string result = "";
  //char buffer[128];

// #ifdef _WIN32
//   std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command.c_str(), "r"),
//                                                  _pclose);
// #else
//   std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"),
//                                                 pclose);
// #endif

//   if (!pipe) {
//     throw std::runtime_error("popen() failed!");
//   }

//   while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
//     result += buffer;
//   }
std::stringstream buffer;
        std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf()); // Redirect cout

        local::main();

        std::cout.rdbuf(oldCout); // Restore original cout
        result = buffer.str();
  
  return result;
}

// Trim leading whitespace
std::string trimLeft(const std::string &str) {
  size_t start = str.find_first_not_of(" \t\n\r");
  return (start == std::string::npos) ? "" : str.substr(start);
}

// Trim trailing whitespace
std::string trimRight(const std::string &str) {
  size_t end = str.find_last_not_of(" \t\n\r");
  return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

// Trim leading and trailing whitespace
std::string trim(const std::string &str) { return trimRight(trimLeft(str)); }

namespace Test {
  using local::SomeData;
    TEST(MemoryTests, test_call_new)
    {
      {
          SomeData *psd1 = new SomeData{ 5,6 };
          ASSERT_TRUE( psd1);
          delete psd1;
      }
    }
    TEST(MemoryTests, test_check_new_and_delete)
    {

      {
        SomeData *psd;

        psd = new SomeData{4,4};

        psd->operator delete(psd);
      }
    }
  
} // namespace Test
