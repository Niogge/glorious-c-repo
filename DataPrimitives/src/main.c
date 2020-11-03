#include <stdio.h>

int main() {
    printf("char: %llu\n", sizeof(char));    
    printf("short int: %llu\n", sizeof(short int));    
    printf("int: %llu\n", sizeof(int));    
    printf("long: %llu\n", sizeof(long));    
    printf("long long: %llu\n", sizeof(long long));    
    printf("float: %llu\n", sizeof(float));    
    printf("double: %llu\n", sizeof(double));    
    printf("long double: %llu\n", sizeof(long double));  
    printf("---------------------\n");

    int nums[10];
    printf("int[10]: %llu\n", sizeof(nums));  
    int count = sizeof(nums)/sizeof(int);
    printf("count int[10]: %d\n", count);  
    for (int i = 0; i < count; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    
    printf("---------------------\n");

    int nums2[] = {1,2,3,4,5};
    int count2 = sizeof(nums2)/sizeof(int);
    printf("count2: %d\n", count2);  
    for (int i = 0; i < count2; i++)
    {
        printf("%d, ", nums2[i]);
    }
    printf("\n");

    int a[] = {1,2,3};
    printf("%d\n", 2[a]); //CRISTO.

}