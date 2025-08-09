enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

set(KDEMANGLE_UNIT_TESTS)
list(APPEND KDEMANGLE_UNIT_TESTS "complex_demangle_ut")
list(APPEND KDEMANGLE_UNIT_TESTS "functional_demangle_ut")
list(APPEND KDEMANGLE_UNIT_TESTS "primitives_demangle_ut")
list(APPEND KDEMANGLE_UNIT_TESTS "stl_demangle_ut")

foreach(UT ${KDEMANGLE_UNIT_TESTS})
    add_executable(${UT} ${UT}.cpp)
    target_link_libraries(${UT} ${PROJECT_NAME})
    target_link_libraries(${UT} GTest::gtest_main)

    gtest_discover_tests(${UT})
endforeach()
