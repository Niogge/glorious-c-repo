#include <stdio.h>
#include <stddef.h>

enum Day{ Mon, Tue, Wed, Thu, Fri, Sat, Sun };

enum MyValue { Value1 =1, Value2, Value3};

enum HTTP_ERROR {
    NOT_FOUND = 404, 
    INTERNAL_SERVER_ERROR = 500
};

typedef enum Days day_t;

struct Weapon {
    int damage; //4 byte
    float speed; //4 byte
};
typedef struct Weapon weapon_t;

//altri modi di definire la struct

typedef struct struct2{
    int val;
} mystruct_t;
//o cosi` o anche anonima


struct struct_char
{
    char c1; // 1 byte
             // 3 byte di padding
    int s1;  // 4 byte
};

struct align2{
    short s1;   //2 byte
                //2 padding
    int i1;     //4 byte
    short s2;   //2 byte
                //2 padding
};
struct align3{
    short s1;   //2 byte
    short s2;   //2 byte // NESSUN PADDING NECESSARIO 
    int i1;     //4 byte
};

void upgrade( weapon_t w){
    w.speed *= 2;
}

enum boolean_enum {true, false};
typedef unsigned char bool;
// #define true 1
// #define false 0
#include "crazy_bool.h"

int main() {

    enum Days day = Mon;
    day_t tue = Tue;


    puts("========ENUM=======");
    printf("day: %llu\n", sizeof(day_t));
    printf("day: %llu\n", sizeof(day));

    printf("day first: %d\n", Mon);
    printf("day 2nd: %d\n", Tue);

    printf("Value first: %d\n", Value1);
    printf("Value 2nd: %d\n", Value2);

    puts("========STRUCTS=======");

    struct Weapon knife;
    knife.damage = 2;
    knife.speed = 10;
    printf("Weapon size: %llu\n", sizeof(weapon_t));
    upgrade(knife);
    printf("knife speed: %f\n", knife.speed);

    printf("struct_char size: %llu\n", sizeof(struct struct_char));
    printf("align2 size: %llu\n", sizeof(struct align2));
    printf("align3 size: %llu\n", sizeof(struct align3));

    size_t a =  offsetof(struct align2, i1);
    printf("offset of i1 : %llu\n", a);

    bool value = true;

    if(value){
        puts("TRUE");
    }else{
        puts("FALSE");
    }

    puts("========DEFINE=======");


}
