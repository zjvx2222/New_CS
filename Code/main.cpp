#include <iostream>
// 检测编译器类型和版本
#if defined(__GNUC__)
#    define COMPILER "GCC"
#elif defined(_MSC_VER)
#    define COMPILER "MSVC"
#elif defined(__clang__)
#    define COMPILER "Clang"
#else
#    define COMPILER "Unknown"
#endif

// 检测编译器版本
#if defined(__GNUC__)
#    define COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#elif defined(_MSC_VER)
#    define COMPILER_VERSION _MSC_VER
#elif defined(__clang__)
#    define COMPILER_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#else
#    define COMPILER_VERSION 0
#endif
int main()
{
    std::cout << "Compiler: " << COMPILER << std::endl;
    std::cout << "Version: " << COMPILER_VERSION << std::endl;
    return 0;
}
