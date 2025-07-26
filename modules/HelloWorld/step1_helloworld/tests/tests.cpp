#include <algorithm>
#include <cctype>
#include <gtest/gtest.h>

std::string getStdoutFromCommand(const std::string &command) {
  std::string result = "";
  char buffer[128];

#ifdef _WIN32
  std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command.c_str(), "r"),
                                                 _pclose);
#else
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"),
                                                pclose);
#endif

  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }

  while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
    result += buffer;
  }

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
TEST(HelloTest, HelloWorld) {
  std::string program_path = "hello_world";
  std::string output = getStdoutFromCommand(program_path);

  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    std::cout << "Current working directory: " << cwd << std::endl;
  } else {
    perror("getcwd() error");
  }

  ASSERT_EQ(trim(output), "Hello World!")
      << "Program output should contain 'Hello World!'. Actual output:\n"
      << output;
}
} // namespace Test
