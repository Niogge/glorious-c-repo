#ifndef MYLIB_H
#define MYLIB_H


#ifdef BUILD_DLL
    #ifdef _WIN32
        #define _DLL_EXPORT_ __declspec(dllexport)
    #else
        #define _DLL_EXPORT_
    #endif //win32
#else
    #define _DLL_EXPORT_
#endif //builddll

enum boolean_enum{true = 1, false =0};
typedef unsigned char bool;


typedef unsigned char cbyte; 
typedef struct{
    cbyte r;
    cbyte g;
    cbyte b;
    cbyte a;
}color; 

static color color_green(){
    color col;
    col.r = 0;
    col.g = 255;
    col.b = 0;
    col.a = 255;
    return col;
}
static bool color_equals(color* color_a, color* color_b){
    if(color_a->r != color_b->r) return false;
    if(color_a->g != color_b->g) return false;
    if(color_a->b != color_b->b) return false;
    if(color_a->a != color_b->a) return false;
    return true;
}
void img_filler_algo(cbyte* data, int  width, int height, int channel, int pixel_x, int pixel_y, color color );

#endif //MYLIB_H