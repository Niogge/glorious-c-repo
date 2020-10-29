#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum Exercise{
    echo_params =0,
    sum,
    user_io
};

typedef enum Exercise exercise;

void echo_params_method(int count, char* args[]){
    puts("======ECHO PARAMS======");
    for (int i = 2; i < count; i++)
    {
        printf("Param%d: %s\n",(i-1),args[i]);
    }
}
void print_sum(int count, char* args[]){
    puts("======SUM PARAMS======");
    float finalsum =0;
    for (int i = 2; i < count; i++)
    {
        finalsum += atof(args[i]);
    }
    printf("%f",finalsum);
}
void user_input(){
    puts("======USER IO======");
    printf("Insert Input: ");
    char userio[30];
    fgets(userio, 30, stdin);
    puts("");
    printf("User Input: %s",userio);
}



int main(int argc, char* args[]){

   
    int pickedEx = atoi(args[1]);
    switch (pickedEx)
    {
    case echo_params:
        echo_params_method(argc, args);
        return 0;
    case sum:
        print_sum(argc, args);
        return 0;
    case user_io:
        user_input();
        return 0;
    default:
        puts("invalid code");
        return 1;
    }
  

   
    
}
