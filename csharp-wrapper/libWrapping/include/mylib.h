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

typedef struct {
    int a;
    int b;
}Pair;

_DLL_EXPORT_ void hello();
_DLL_EXPORT_ void helloint(int val);
_DLL_EXPORT_ void hellostr(const char* val);
_DLL_EXPORT_ int sum(int v[], int size);
_DLL_EXPORT_ int sumPair(Pair P);
_DLL_EXPORT_ int sumPairPtr(Pair *P);
_DLL_EXPORT_ void sum_out(int a, int b, int * r);
_DLL_EXPORT_ char* fixed_str();

#endif //MYLIB_H