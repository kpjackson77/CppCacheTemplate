#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace utilities
{
    // Splits a string based on a string delimiter
    std::vector<std::string> split(const std::string &s, const std::string &delimiter)
    {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end;

        while ((end = s.find(delimiter, start)) != std::string::npos)
        {
            tokens.emplace_back(s.substr(start, end - start));
            start = end + delimiter.length();
        }

        tokens.emplace_back(s.substr(start)); // Add remaining part
        return tokens;
    }
    std::string string_tolower(const std::string &msg)
    {
        std::string data{msg};
        //std::cerr << data << std::endl;
        std::transform(data.begin(), data.end(), data.begin(), [](auto c)
                       { return std::tolower(c); });
        //               std::cerr << data <<std::endl;
        return data;
    }
    bool contains_string(const std::string &output, const std::string &tofind)
    {
        auto output_lower{output};
        auto pos = output.find(tofind);
        return pos != std::string::npos;
    }
    // bool contains_string(const std::string &output, const std::string &tofind)
    // {
    //     auto output_lower{string_tolower(output)};
    //     auto pos = output.find(string_tolower(tofind));
    //     return pos != std::string::npos;
    // }
    bool substringsAppearInOrder(const std::string &text, const std::vector<std::string> &expectedOrder)
    {
        size_t pos = 0;
        for (const auto &substr : expectedOrder)
        {
            pos = text.find(substr, pos);
            if (pos == std::string::npos)
                return false;
            pos += substr.length(); // Move past current match
        }
        return true;
    }
    template <typename MAIN, typename INPUT_SEQ, typename OUTPUT_SEQ>
    void run_sequence(MAIN fun, INPUT_SEQ input, OUTPUT_SEQ asserts)
    {
        std::ostringstream buffer;
        std::istringstream buffer2;
        std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf()); // Redirect cout
        std::streambuf *oldCin = std::cin.rdbuf(buffer2.rdbuf());  // Redirect cin
        input(buffer2);
        fun();
        std::cout.rdbuf(oldCout); // Restore original cout
        std::cin.rdbuf(oldCin);   // Restore original cout
        std::string output = buffer.str();
        asserts(output);
    }
    template <typename F, typename T>
    struct has_signature : std::false_type{};

    template <typename R, typename... Args, typename T>
    struct has_signature<R (*)(Args...), T>
        : std::is_same<decltype(static_cast<R (*)(Args...)>(T{})), R (*)(Args...)>{};

}