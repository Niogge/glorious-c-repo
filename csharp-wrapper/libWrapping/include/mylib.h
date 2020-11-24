#ifndef MYLIB_H
#define MYLIB_H

#ifdef BUILD_DLL
    #ifdef _WIN32
        #define _DLL_EXPORT_ __declspec(dllexport)
    #else
        #define _DLL_EXPORT_
    #endif //win32
#else
    #define _DLL_EXPORT_
#endif //builddll


_DLL_EXPORT_ void hello();
_DLL_EXPORT_ void helloint(int val);

#endif //MYLIB_H