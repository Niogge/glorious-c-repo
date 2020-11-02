#ifndef AIV_CUNIT_H
#define AIV_CUNIT_H
#include <stdio.h>
#include <string.h>

#define __REL_PATH__ strstr(__FILE__, "src/")

#define CUNIT_INT_EQ(exp, res) if( exp != res ){\
 printf("[FAIL] %s @ line %d\t[%s]\n",__FUNCTION__,__LINE__,__REL_PATH__);\
 Fail+=1;}

#define CUNIT_RUNNER(...) int main() {\
Fail = 0;\
Total = 0;\
void (*func_ptr[])() = {__VA_ARGS__};\
int func_ptr_size = sizeof(func_ptr)/sizeof(void(*)());\
for (int i = 0; i < func_ptr_size ; i++)\
{\
   Total+=1;\
   func_ptr[i]();\
}\
AIV_CUNIT_printReport();\
return 0;\
}

static int Total;
static int Fail;

void AIV_CUNIT_printReport(){
   printf("Total: %d\tPassed:%d\tFailed:%d\n",Total, Total-Fail, Fail);
}

#endif