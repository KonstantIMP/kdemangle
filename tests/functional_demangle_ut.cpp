#include <gtest/gtest.h>

#include <kimp/demangle.hpp>


TEST(Functional, LambdaTest) {
    auto f = []() {};
    EXPECT_STREQ(
        kimp::TypeName(f).c_str()
        , "Functional_LambdaTest_Test::TestBody()::$_0"
    );
}


void GlobaFunction() {}

TEST(Functional, GlobalFunctionTest) {
    EXPECT_STREQ(
        kimp::TypeName(GlobaFunction).c_str()
        , "void ()"
    );
}


void GlobalFunctionWithArgs(int a, long b) {}

TEST(Functional, GlobalFunctionWithArgsTest) {
    EXPECT_STREQ(
        kimp::TypeName(GlobalFunctionWithArgs).c_str()
        , "void (int, long)"
    );
}
