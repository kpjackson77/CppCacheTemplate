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
  // TEST(CacheTests, test_copy_from_input_to_output)
  //   {
  //    // std::ofstream ofs("../../../../HelloWorld/final_cache/exercise/test_output.txt");
  //    std::ifstream ifs("../../../../../../modules/HelloWorld/final_cache/exercise/test_input.txt");
  //    std::ofstream ofs("../../../../../../modules/HelloWorld/final_cache/exercise/test_output.txt");
  //     if (!ofs) {
  //       FAIL() << "Failed to open output file.";
  //     }   
  //     if (!ifs) {
  //       FAIL() << "Failed to open input file.";
  //     }
  //     while(!ifs.eof())
  //     {
  //       char line[100];
  //       ifs.getline(line, sizeof(line), '\n');

  //       ofs << line << std::endl;
  //     }
  //     ifs.close();
  //     ofs.close();
  //   }
    // TEST(CacheTests, test_write_to_file2)
    // {   
    //   using std::string_literals::operator"" s;

    //  // std::ofstream ofs("../../../../HelloWorld/final_cache/exercise/test_output.txt"); 
    //     utilities::run_sequence(local::main, [=](std::istringstream &buffer)
    //                             {
    //                                 //buffer.str(data_in);
    //                                 buffer.clear(); },
    //                             [=](const std::string &output)
    //                             {
    //                                 std::ofstream ofs("../../../../../../modules/HelloWorld/final_cache/exercise/test_output2.txt");
    //                                 if (!ofs) {
    //                                   FAIL() << "Failed to open output file.";
    //                                 }

    //                                 ofs << output << std::endl;
    //                                 ofs.close();
    //                                 std::vector<std::string> data_out = std::vector{""s};
                                   
    //                                 // ASSERT_FALSE(true) << output << std::endl;
    //                             });
    // }
    TEST(CacheTests, step1_test_too_many_items)
    {
      using local::caches::SquareCache;
      {
          SquareCache sc{};
          ASSERT_EQ( sc.get_square(0), 0);
            
          ASSERT_EQ( sc.get_square(1), 1);
             
          EXPECT_THROW( sc.get_square(10000), std::out_of_range);
            
      }
    }
    TEST(CacheTests, step1_test_square_cache)
    {
      using local::caches::SquareCache;
      {
        try {
          SquareCache sc{};
          ASSERT_EQ( sc.get_square(3), 9)
              << "Expected square of 3 to be 9, but got: "
              << sc.get_square(3);
          ASSERT_EQ( sc.get_square(11),121)
              << "Expected square of 11 to be 121, but got: "
              << sc.get_square(11);
        }
        catch (const std::exception &e) {
          std::cerr << "Exception: " << e.what() << std::endl;
        }
      }
    }
    //substringsAppearInOrder
    TEST(CacheTests, step1_test_results)
    {
        using std::string_literals::operator"" s;
        //std::string data_in{"i\nAAA\n123\no\n\ni\nBBB\n234\no\nx"s};
        std::vector data_parts = utilities::split("\nSquare of 3:\n9\nSquare of 12:\n144\nSquare of 3:\n9\n", "\n");
        utilities::run_sequence(local::main, [=](std::istringstream &buffer)
                                {
                                    //buffer.str(data_in);
                                    buffer.clear(); },
                                [=](const std::string &output)
                                {
                                    std::vector<std::string> data_out = std::vector{""s};
                                    for (auto item : data_parts)
                                    {
                                        data_out.push_back(item);
                                    }
                                    ASSERT_TRUE(utilities::substringsAppearInOrder(output, data_out));
                                    //data_out.push_back("exiting");
                                    // for (auto item : data_out)
                                    // {
                                    //     ASSERT_TRUE(utilities::contains_string(output, item))
                                    //          << "Program output should contain the item:\n"
                                    //          << item << "\n" << "Actual output:\n"
                                    //          << output;
                                    // }
                                    // ASSERT_FALSE(true) << output << std::endl;
                                });
  }
  TEST(CacheTests, final_cache) {
   std::string program_path = "hello_world";
   std::string output = getStdoutFromCommand(program_path);

  // char cwd[PATH_MAX];
  // if (getcwd(cwd, sizeof(cwd)) != NULL) {
  //   std::cout << "Current working directory: " << cwd << std::endl;
  // } else {
  //   perror("getcwd() error");
  // }
  ASSERT_TRUE(trim(output).find("Square of 3: 9") != -1);
  
  // ASSERT_EQ(trim(output), "Square of 3: 9")
  //     << "Program output should contain 'Square of 3: 9'. Actual output:\n"
  //     << output;
  // ASSERT_EQ(1,2);
  }
} // namespace Test
