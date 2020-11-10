#ifndef AIV_COMMON_H
#define AIV_COMMON_H
#define true 1
#define false 0


#ifdef BUILD_DLL
    #ifdef _WIN32
        #define _DLL_EXPORT_ __declspec(dllexport)
    #else
        #define _DLL_EXPORT_
    #endif //win32
#else
    #define _DLL_EXPORT_
#endif //builddll


typedef unsigned int uint;
typedef unsigned char bool;

#endif