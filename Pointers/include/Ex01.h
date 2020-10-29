#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum Exercise{
    echo_params,
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
    char* error;
    for (int i = 2; i < count; i++)
    {
        
        float f = strtof(args[i], &error);
        if(strlen(error)==0){
            finalsum += f;
        }
        else{
            printf("Invalid parameter: %s\t\t\t skipped\n", args[i]);
        }
    }
    printf("%f",finalsum);
}
void user_input(){
    puts("======USER IO======");
    printf("Insert Input: ");
    char userio[30];
    fgets(userio, sizeof(userio), stdin);
    int len = strlen(userio);
    int indexnewline = len -1;
    userio[indexnewline]='\0';
    printf("User Input: %s",userio);
    puts("");
}



int main(int argc, char* args[]){

    puts("");
    printf("Arg count: %d\n", argc);
    printf("Path: %s\n", args[0] );
    char* error[100];
    int pickedEx = strtol(args[1], error,10);
    puts(error[0]);
    printf("Code: %d\n",pickedEx);
    puts("\n");
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
