#pragma once


#include <cstddef>
#include <cstdlib>
#include <string>
#include <typeindex>
#include <typeinfo>


#ifdef __GNUC__
    #include <cxxabi.h>
#endif // __GNUC__


namespace kimp {


namespace _private {

inline std::string Normalize(std::string demangled) {

#ifdef __GNUC__
    for (std::string::size_type pos; (pos = demangled.find("::__1")) != std::string::npos;) {
        demangled.erase(pos, 5);
    }
#endif // __GNUC__

#ifdef _MSC_VER
    for (std::string::size_type pos; (pos = demangled.find(" >")) != std::string::npos;) {
        demangled.erase(pos, 1);
    }
#endif // _MSC_VER

    return demangled;
}

} // namespace _private


inline std::string Demangle(const char* mangled);

#ifdef __GNUC__

inline std::string Demangle(const char* mangled) {
    char* demangled_name;
    std::size_t demangled_name_length;
    int demangle_status;

    demangled_name = abi::__cxa_demangle(
        mangled
        , nullptr
        , &demangled_name_length
        , &demangle_status
    );

    std::string result { mangled };

    if (demangle_status == 0) {
        result = std::string { demangled_name, demangled_name_length };
    }

    if (demangled_name) {
        free(demangled_name);
    }

    return _private::Normalize(result);
}

#else

inline std::string Demangle(const char* mangled) {
    return _private::Normalize(std::string { mangled });
}

#endif // __GNUC__


inline std::string Demangle(const std::string& mangled) {
    return Demangle(mangled.c_str());
}

inline std::string TypeName(const std::type_info& ti) {
    return Demangle(ti.name());
}

inline std::string TypeName(const std::type_index& ti) {
    return Demangle(ti.name());
}

template <class T>
inline std::string TypeName() {
    return TypeName(typeid(T));
}

template <class T>
inline std::string TypeName(const T& t) {
    return TypeName(typeid(t));
}


} // namespace kimp
