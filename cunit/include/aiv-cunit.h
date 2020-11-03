#ifndef AIV_CUNIT_H
#define AIV_CUNIT_H
#include <stdio.h>
#include <string.h>

int __fail = 0;
#define __REL_PATH__ strstr(__FILE__, "\\src/") // c'e` poco controllo 

const char * __cunit_rel_src(const char* path) //const ci consente di passare un letterale 
{
   const char* subPath = strstr(path, "\\src/");
   if(subPath == NULL) subPath = strstr(path, "\\tests/");
   if(subPath == NULL)  return path;

   return subPath + 1;
}

#define CUNIT_TEST(name) void name()

#define CUNIT_INT_EQ(exp, res) if( exp != res ){\
   printf("[FAIL] %s: expected '%d' but was '%d' \t [%s @ %d]\n",__FUNCTION__, exp, res, __cunit_rel_src(__FILE__),__LINE__);\
   __fail++;\
   return;\
}

#define CUNIT_IS_TRUE(exp) if( exp == 0 ){\
   printf("[FAIL] %s: expected '%s' but was '%s' \t [%s @ %d]\n",__FUNCTION__, "true", "false", __cunit_rel_src(__FILE__),__LINE__);\
   __fail++;\
   return;\
}

#define CUNIT_NOT_NULL(exp) if(exp == NULL){\
   printf("[FAIL] %s: expected '%s' but was '%s' \t [%s @ %d]\n",__FUNCTION__,"NOT NULL", "NULL", __cunit_rel_src(__FILE__),__LINE__);\
   __fail++;\
}

#define CUNIT_NULL(exp) if(exp != NULL){\
   printf("[FAIL] %s: expected '%s' but was '%s' \t [%s @ %d]\n",__FUNCTION__,"NULL", "NOT NULL", __cunit_rel_src(__FILE__),__LINE__);\
   __fail++;\
}

#define CUNIT_PTR_EQ(exp, res) if(exp != res){\
    printf("[FAIL] %s: expected '0x%p' but was '0x%p' \t [%s @ %d]\n",__FUNCTION__,exp, res, __cunit_rel_src(__FILE__),__LINE__);\
   __fail++;\
}

#define CUNIT_RUNNER(...) int main(int argc, char* args[]) {\
\
void (*func_ptr[])() = {__VA_ARGS__};\
int func_ptr_size = sizeof(func_ptr)/sizeof(void(*)());\
for (int i = 0; i < func_ptr_size ; i++)\
{\
   func_ptr[i]();\
}\
   printf("Total: %d\tPassed:%d\tFailed:%d\n",func_ptr_size, func_ptr_size-__fail, __fail);\
return 0;\
}

#endif