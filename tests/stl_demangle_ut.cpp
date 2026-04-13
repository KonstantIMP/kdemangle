#include <gtest/gtest.h>

#include <kimp/demangle.hpp>

#include <array>
#include <string>
#include <vector>

TEST(STL, StringTest) {
    std::string obj = "";

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::basic_string<char, std::char_traits<char>, std::allocator<char>>"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>"
    );
#endif //_MSC_VER

}

TEST(STL, Array) {
    std::array<int, 5> obj = {};

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::array<int, 5ul>"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "class std::array<int,5>"
    );
#endif //_MSC_VER

}

TEST(STL, Vector) {
    std::vector<std::string> obj = {};

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName(obj).c_str()
        , "class std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>"
    );
#endif //_MSC_VER

}
