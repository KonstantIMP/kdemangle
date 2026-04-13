#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <kimp/demangle.hpp>


TEST(Functional, LambdaTest) {
    auto f = []() {};

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName(f).c_str()
        , "Functional_LambdaTest_Test::TestBody()::$_0"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_THAT(
        kimp::TypeName(f).c_str()
        , testing::AllOf(testing::StartsWith("class <lambda"), testing::EndsWith(">"))
    );
#endif //_MSC_VER

}


void GlobalFunction() {}

TEST(Functional, GlobalFunctionTest) {

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName(GlobalFunction).c_str()
        , "void ()"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName(GlobalFunction).c_str()
        , "void __cdecl(void)"
    );
#endif //_MSC_VER

}


void GlobalFunctionWithArgs(int a, long b) {}

TEST(Functional, GlobalFunctionWithArgsTest) {

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName(GlobalFunctionWithArgs).c_str()
        , "void (int, long)"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName(GlobalFunctionWithArgs).c_str()
        , "void __cdecl(int,long)"
    );
#endif //_MSC_VER

}
