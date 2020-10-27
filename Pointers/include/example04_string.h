#include <stdio.h>
#include <string.h>

int main(){
    char c = 'a';

    char str1[] = "arr"; // con aggiunta di \0 alla fine 
    char* str = "ptr";

    printf("char[] size: %llu\n", sizeof(str1));
    printf("char* size: %llu\n", sizeof(str));


    printf("char[] len size: %llu\n", strlen(str1));
    printf("char[] len size: %llu\n", strlen(str));

    char str3[] = {'h','e', 'y'};
    printf("hey size: %llu\n", sizeof(str3)); //3
    printf("hey len size: %llu\n", strlen(str3)); //RANDOM.    senza null terminator le funzioni delle stringhe non funzionano.
    
    char str4[] = {'h','e', 'y','\0'};
    printf("hey2 size: %llu\n", sizeof(str4)); //4
    printf("hey2 len size: %llu\n", strlen(str4)); //3

    //comparazione
    if(strcmp("hello","hello")==0){
        puts("so uguali");
    }

    char strcmp1[100] = "hello";
    char* strcmp2 = "hello";
    if(strcmp(strcmp1,strcmp2) == 0){
        puts("so uguali");
    }
    else{
        puts("so diversi");
    }

    //copia di stringhe
    char destination[100];
    
    strcpy_s(destination, sizeof(destination), "Hello copy");
    printf("%s\n", destination);

    //substring
    char* sub_fullstring = "hello world";
    char* strstrd = strstr(sub_fullstring, " wor");
    printf("%s\n", strstrd);

    int indexof = strstrd - sub_fullstring;
    printf("%d\n", indexof);

    char sub_substr[6];
    int sub_count = indexof;
    strncpy_s(sub_substr, sizeof(sub_substr),sub_fullstring,sub_count);
    puts(sub_substr);


    //Concatenazione
    char dest[100]= "Hello";
    strcat_s(dest,sizeof(dest)," world");
    puts(dest);

    //Tokenizzazione
    char tok_full_str[] = "1,2,3,4,5";
    char * tok_remains;
    char* token = strtok_s(tok_full_str,",", &tok_remains);
    while(token){//!= NULL
        printf("Token: %s - Remains: %s\n",token, tok_remains);
        token = strtok_s(NULL, ",", &tok_remains);
    }
    puts(tok_full_str);
    for (int i = 0; i < sizeof tok_full_str; i++)
    {
        tok_full_str[i]?putchar(tok_full_str[i]):fputs("\\0",stdout);
    }
    puts("");
}

// int main(int argc, char* args[]){
//     //app.exe param1 param2 10 15
// }