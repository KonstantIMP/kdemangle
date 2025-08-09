#include <gtest/gtest.h>

#include <kimp/demangle.hpp>

#include <array>
#include <string>
#include <vector>

TEST(STL, StringTest) {
    std::string obj = "";
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>"
    );
}

TEST(STL, Array) {
    std::array<int, 5> obj = {};
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::__1::array<int, 5ul>"
    );
}

TEST(STL, Vector) {
    std::vector<std::string> obj = {};
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::__1::vector<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>>"
    );
}
