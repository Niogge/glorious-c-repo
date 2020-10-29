#include <stdio.h>

void hello(){
    printf("Hello\n");
}
void fucku(){
    printf("Fuck you!\n");
}
int sum(int a, int b){
    return a+b;
}

void say(void(*sayFunc)()){
    sayFunc();
}


int main(){

    void(*fHello)()= hello;
    int (*fTwoInt)(int,int) = sum;
    for (int i = 0; i < 10; i++)
    {
        if(i%3==0){
            say(fHello);
        }
        else{
            say(fucku);
        }
    }
    
  
}