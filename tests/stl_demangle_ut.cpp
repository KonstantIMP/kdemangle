#include <gtest/gtest.h>

#include <kimp/demangle.hpp>

#include <array>
#include <string>
#include <vector>

TEST(STL, StringTest) {
    std::string obj = "";
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::basic_string<char, std::char_traits<char>, std::allocator<char>>"
    );
}

TEST(STL, Array) {
    std::array<int, 5> obj = {};
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::array<int, 5ul>"
    );
}

TEST(STL, Vector) {
    std::vector<std::string> obj = {};
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>"
    );
}
