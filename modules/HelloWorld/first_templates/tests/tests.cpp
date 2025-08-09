#include <algorithm>
#include <cctype>
#include <gtest/gtest.h>
#include <sstream>
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
TEST(TemplateTests, step1_templates) {
  {
    auto result = local::my_max(1, 2);

    ASSERT_EQ(result, 2)
        << "my_max does not return correct value for int.\n";
  }
  {
    auto result = local::my_max(10.2, 2.5);

    ASSERT_TRUE(result <= 10.2 + 0.0001 && result >= 10.2 - 0.0001)
        << "my_max does not return correct value for double.\n";
  }
}
  auto test_max(auto a, auto b) {
    return (a > b) ? a : b;
  }
  TEST(TemplateTests, step1_check_templates) {
    {
      bool result = std::is_same_v<decltype(local::my_max<double>(1.4, 2.2)), decltype(test_max<double>(1.4, 2.2))  >;

      ASSERT_TRUE(result)
          << "my_max is not a template function!\n";
    }
  }

  // {
  // auto result = local::my_max(1, 2);

  // ASSERT_EQ(result, 2)
  //     << "my_max does not return correct value for int:\n"
  //     << output;
  // }

// TEST(TemplateTests, second_templates) {
//   std::string program_path = "hello_world";
//   std::string output = getStdoutFromCommand(program_path);

//   char cwd[PATH_MAX];
//   if (getcwd(cwd, sizeof(cwd)) != NULL) {
//     std::cout << "Current working directory: " << cwd << std::endl;
//   } else {
//     perror("getcwd() error");
//   }

//   ASSERT_EQ(trim(output), "Hello World!")
//       << "Program output should contain 'Hello World!'. Actual output:\n"
//       << output;
// }
} // namespace Test
