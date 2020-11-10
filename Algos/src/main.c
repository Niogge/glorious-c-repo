#include <stdio.h>
#include <stdlib.h>
typedef unsigned long ulong;
//bottom up recursion (parte da un valore noto e continua)
ulong fact(int n){ //O(N)
    if(n<0){
        return -1;
    }
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}
//iterativo
ulong fact_no_r(int n){//O(N)
    int res = 1;
    for (int i = 0; i < n-1; i++)
    {
        res*=(n-i);
    }
    return res;
}

//recursion top down
ulong fib_rec(ulong index){//O(2^N)
    if(index ==0) return 0;
    if(index ==1) return 1;
    return fib_rec(index - 1 ) + fib_rec(index-2);
}


ulong fib_rec_bis_internal(ulong index, ulong* cache){
    if(index ==0) return 0;
    if(index ==1) return 1;
    if(cache[index] == 0){
        cache[index] = fib_rec_bis_internal(index - 1, cache ) + fib_rec_bis_internal(index-2,cache);
    }
    return cache[index];
}
//memoization 
ulong fib_rec_bis(ulong index){// Nel tempo: O(2^N) caso peggiore // Nello spazio O(N+1) -> O(N)

    ulong* cache= (ulong*)calloc(index+1, sizeof(ulong));

    ulong res = fib_rec_bis_internal(index - 1, cache ) + fib_rec_bis_internal(index-2,cache);
    free(cache);
    return res;
}

ulong fib_iter(ulong n){

    if(n==0) return 0;
    if(n==1) return 1;
    ulong minus_two = 0;
    ulong minus_one = 1;
    ulong res = 0;
    for (ulong i = 0; i < n -1 ; i++)
    {
        res = minus_two+minus_one;
        minus_two = minus_one;
        minus_one = res;
    }
    return res;
    
}

int main(){
    //1=>1
    //2=>3
    //3=>6  123.132.213.231.321.312
    //3! = 3*2! = 3*2*1! = 3*2*1 = 6   
    printf("%lu\n", fact_no_r(3) );
    printf("%lu\n", fact_no_r(0) );
    printf("%lu\n", fact_no_r(0) );

    puts("");
    ulong val = fib_iter(2000000);
    printf("%lu\n", val);
}