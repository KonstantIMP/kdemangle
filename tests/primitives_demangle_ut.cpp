#include <gtest/gtest.h>

#include <kimp/demangle.hpp>

TEST(Primitives, IntTest) {
    EXPECT_STREQ(
        kimp::TypeName<int>().c_str()
        , "int"
    );
}

TEST(Primitives, LongTest) {
    EXPECT_STREQ(
        kimp::TypeName<long>().c_str()
        , "long"
    );
}

TEST(Primitives, CharTest) {
    EXPECT_STREQ(
        kimp::TypeName<char>().c_str()
        , "char"
    );
}

TEST(Primitives, DoubleTest) {
    EXPECT_STREQ(
        kimp::TypeName<double>().c_str()
        , "double"
    );
}
