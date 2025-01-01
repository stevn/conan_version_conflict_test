#include <iostream>
#include "file_mux.h"
#include "file_io.h"
#include "file_types.h"



void file_mux(){
    file_io();
    file_types();


    #ifdef NDEBUG
    std::cout << "file_mux/8.0.1@stevn/feature: Hello World Release!\n";
    #else
    std::cout << "file_mux/8.0.1@stevn/feature: Hello World Debug!\n";
    #endif

    // ARCHITECTURES
    #ifdef _M_X64
    std::cout << "  file_mux/8.0.1@stevn/feature: _M_X64 defined\n";
    #endif

    #ifdef _M_IX86
    std::cout << "  file_mux/8.0.1@stevn/feature: _M_IX86 defined\n";
    #endif

    #ifdef _M_ARM64
    std::cout << "  file_mux/8.0.1@stevn/feature: _M_ARM64 defined\n";
    #endif

    #if __i386__
    std::cout << "  file_mux/8.0.1@stevn/feature: __i386__ defined\n";
    #endif

    #if __x86_64__
    std::cout << "  file_mux/8.0.1@stevn/feature: __x86_64__ defined\n";
    #endif

    #if __aarch64__
    std::cout << "  file_mux/8.0.1@stevn/feature: __aarch64__ defined\n";
    #endif

    // Libstdc++
    #if defined _GLIBCXX_USE_CXX11_ABI
    std::cout << "  file_mux/8.0.1@stevn/feature: _GLIBCXX_USE_CXX11_ABI "<< _GLIBCXX_USE_CXX11_ABI << "\n";
    #endif

    // MSVC runtime
    #if defined(_DEBUG)
        #if defined(_MT) && defined(_DLL)
        std::cout << "  file_mux/8.0.1@stevn/feature: MSVC runtime: MultiThreadedDebugDLL\n";
        #elif defined(_MT)
        std::cout << "  file_mux/8.0.1@stevn/feature: MSVC runtime: MultiThreadedDebug\n";
        #endif
    #else
        #if defined(_MT) && defined(_DLL)
        std::cout << "  file_mux/8.0.1@stevn/feature: MSVC runtime: MultiThreadedDLL\n";
        #elif defined(_MT)
        std::cout << "  file_mux/8.0.1@stevn/feature: MSVC runtime: MultiThreaded\n";
        #endif
    #endif

    // COMPILER VERSIONS
    #if _MSC_VER
    std::cout << "  file_mux/8.0.1@stevn/feature: _MSC_VER" << _MSC_VER<< "\n";
    #endif

    #if _MSVC_LANG
    std::cout << "  file_mux/8.0.1@stevn/feature: _MSVC_LANG" << _MSVC_LANG<< "\n";
    #endif

    #if __cplusplus
    std::cout << "  file_mux/8.0.1@stevn/feature: __cplusplus" << __cplusplus<< "\n";
    #endif

    #if __INTEL_COMPILER
    std::cout << "  file_mux/8.0.1@stevn/feature: __INTEL_COMPILER" << __INTEL_COMPILER<< "\n";
    #endif

    #if __GNUC__
    std::cout << "  file_mux/8.0.1@stevn/feature: __GNUC__" << __GNUC__<< "\n";
    #endif

    #if __GNUC_MINOR__
    std::cout << "  file_mux/8.0.1@stevn/feature: __GNUC_MINOR__" << __GNUC_MINOR__<< "\n";
    #endif

    #if __clang_major__
    std::cout << "  file_mux/8.0.1@stevn/feature: __clang_major__" << __clang_major__<< "\n";
    #endif

    #if __clang_minor__
    std::cout << "  file_mux/8.0.1@stevn/feature: __clang_minor__" << __clang_minor__<< "\n";
    #endif

    #if __apple_build_version__
    std::cout << "  file_mux/8.0.1@stevn/feature: __apple_build_version__" << __apple_build_version__<< "\n";
    #endif

    // SUBSYSTEMS

    #if __MSYS__
    std::cout << "  file_mux/8.0.1@stevn/feature: __MSYS__" << __MSYS__<< "\n";
    #endif

    #if __MINGW32__
    std::cout << "  file_mux/8.0.1@stevn/feature: __MINGW32__" << __MINGW32__<< "\n";
    #endif

    #if __MINGW64__
    std::cout << "  file_mux/8.0.1@stevn/feature: __MINGW64__" << __MINGW64__<< "\n";
    #endif

    #if __CYGWIN__
    std::cout << "  file_mux/8.0.1@stevn/feature: __CYGWIN__" << __CYGWIN__<< "\n";
    #endif
}

void file_mux_print_vector(const std::vector<std::string> &strings) {
    for(std::vector<std::string>::const_iterator it = strings.begin(); it != strings.end(); ++it) {
        std::cout << "file_mux/8.0.1@stevn/feature " << *it << std::endl;
    }
}
