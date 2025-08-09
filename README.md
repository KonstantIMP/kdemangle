# kDemangle

Header-only C++11 library for demangling (makes compiler created object names as human readable as possible)

It is not suitable for external names decoding, use only for purposes of project you are actually compiling

## Usage

Use `TypeName` template with concrete type or instance to get its name:

```c++
// For concrete type
std::cout << kimp::TypeName<std::string>() << std::endl;

// For concrete instace
std::array<int, 5> obj;
std::cout << kimp::TypeName(obj) << std::endl;
```

## Compatibility

Works with compilers supporting `cxxabi.h` like g++ and clang (checks `_GNUC_` macros)

In other cases behaviour is the same with `typeid(...).name()`

## Todo

- [ ] Replace `std::__1::` with just `std::`
- [ ] `UnDecorateSymbolName` or `__unDName` support for MSVC
- [ ] Support different checks in test (now works only with `_GNUC_`)
