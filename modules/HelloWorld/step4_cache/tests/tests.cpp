#include <algorithm>
#include <cctype>
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <memory>
// #include <sys/resource.h>

#include "../../../include/utilities.h"
namespace local
{
#include "../exercise/main.cpp"
}
std::string getStdoutFromCommand(const std::string &command) {
        std::string result = "";

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

    TEST(CacheTests, step4_test_too_many_items)
    {
      using local::caches::SquareCache;
      {
          SquareCache<int> sc{};
          ASSERT_EQ( sc.get_square(0), 0);
            
          ASSERT_EQ( sc.get_square(1), 1);
             
          EXPECT_THROW( sc.get_square(10000), std::out_of_range); 
      }
    }
    TEST(CacheTests, step4_test_size_for_shared_ptr)
    {
      using local::caches::MemoryPool;
      using local::caches::SquareCache;
      {
          SquareCache<int,1> sc{};
          ASSERT_EQ( sizeof(sc), sizeof(std::shared_ptr<int>{nullptr})+sizeof(MemoryPool<int, sizeof(int)>));
      }
    }
    TEST(CacheTests, step4_test_memory_cache)
    {
      using local::caches::MemoryPool;
      {
          MemoryPool<int> mp{};

          long ptr1 = reinterpret_cast<long>(mp.get_next());
          long ptr2 = reinterpret_cast<long>(mp.get_next());
          ASSERT_EQ( ptr2-ptr1, sizeof(int));            
      }
      {
          MemoryPool<long long> mp{};

          long ptr1 = reinterpret_cast<long>(mp.get_next());
          long ptr2 = reinterpret_cast<long>(mp.get_next());
          ASSERT_EQ( ptr2-ptr1, sizeof(long long));            
      }
    }
    TEST(CacheTests, step4_test_square_cache)
    {
      using local::caches::SquareCache;
      {
        try {
          SquareCache<int> sc{};
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
    TEST(CacheTests, step4_test_results)
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

} // namespace Test
