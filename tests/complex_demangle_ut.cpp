#include <gtest/gtest.h>

#include <kimp/demangle.hpp>


TEST(Complex, InnerStructTest) {
    struct S { };

    EXPECT_STREQ(
        kimp::TypeName<S>().c_str()
        , "Complex_InnerStructTest_Test::TestBody()::S"
    );
}


struct GlobalStruc { };

TEST(Complex, GlobalStructTest) {
    EXPECT_STREQ(
        kimp::TypeName<GlobalStruc>().c_str()
        , "GlobalStruc"
    );
}


TEST(Complex, InnerClassTest) {
    class C {};
    EXPECT_STREQ(
        kimp::TypeName<C>().c_str()
        , "Complex_InnerClassTest_Test::TestBody()::C"
    );
}


class GlobalClass { };

TEST(Complex, GlobalClassTest) {
    EXPECT_STREQ(
        kimp::TypeName<GlobalClass>().c_str()
        , "GlobalClass"
    );
}
