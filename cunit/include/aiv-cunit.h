#ifndef AIV_CUNIT_H
#define AIV_CUNIT_H

#include <stdio.h>
#define CUNIT_INT_EQ(exp, res) if( exp != res )\
 printf("Test Fail @ line %d\n",__LINE__) 

#define CUNIT_RUNNER(...) int main() {\
void (*func_ptr[])() = {__VA_ARGS__};\
int func_ptr_size = sizeof(func_ptr)/sizeof(void(*)());\
for (int i = 0; i < func_ptr_size ; i++)\
{\
   func_ptr[i]();\
}\
\
return 0;\
}

#endif