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

    return result;
}

#else

inline std::string Demangle(const char* mangled) {
    return std::string { mangled };
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
