#include <gtest/gtest.h>

#include <kimp/demangle.hpp>


TEST(Complex, InnerStructTest) {
    struct S { };

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName<S>().c_str()
        , "Complex_InnerStructTest_Test::TestBody()::S"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName<S>().c_str()
        , "struct `private: virtual void __cdecl Complex_InnerStructTest_Test::TestBody(void) __ptr64'::`2'::S"
    );
#endif //_MSC_VER

}


struct GlobalStruct { };

TEST(Complex, GlobalStructTest) {

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName<GlobalStruct>().c_str()
        , "GlobalStruct"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName<GlobalStruct>().c_str()
        , "struct GlobalStruct"
    );
#endif //_MSC_VER

}


TEST(Complex, InnerClassTest) {
    class C {};

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName<C>().c_str()
        , "Complex_InnerClassTest_Test::TestBody()::C"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName<C>().c_str()
        , "class `private: virtual void __cdecl Complex_InnerClassTest_Test::TestBody(void) __ptr64'::`2'::C"
    );
#endif //_MSC_VER

}


class GlobalClass { };

TEST(Complex, GlobalClassTest) {

#ifdef __GNUC__
    EXPECT_STREQ(
        kimp::TypeName<GlobalClass>().c_str()
        , "GlobalClass"
    );
#endif //__GNUC__

#ifdef _MSC_VER
    EXPECT_STREQ(
        kimp::TypeName<GlobalClass>().c_str()
        , "class GlobalClass"
    );
#endif //_MSC_VER

}
