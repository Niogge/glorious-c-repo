#include <stdlib.h>
#include <time.h>

static int first_time = 0;
unsigned int my_rand(){
    if(first_time == 0){
        srand((unsigned int) time(NULL));
        first_time++;
    }
    return rand();
}

#define true my_rand() %2 == 1
#define false my_rand() %2 == 0
