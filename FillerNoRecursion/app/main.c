#include "filler.h"
//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"



void swap_channels(stbi_uc* buffer, int A, int B, int channels, int pixel_count){

    for (int i = 0; i < pixel_count; i++)
    {
        int index = i* channels;
        char temp = buffer[index+A];
        buffer[index+A] = buffer[index+B];
        buffer[index+B] = temp;
    }

    
}

int example_img(){
    int width;
    int height;
    int channels;
    stbi_uc* data =  stbi_load("assets/red.png", &width, &height, &channels, 0);
    if(!data){
        puts("file non trovato");
        return 0;
    }

    printf("Width>:%d\n", width);
    printf("Height>:%d\n", height);
    printf("Channels>:%d\n", channels);

    printf("Pixel0 0>:%d\n", data[0]);
    printf("Pixel0 1>:%d\n", data[1]);
    printf("Pixel0 2>:%d\n", data[2]);


    swap_channels(data, 0, 1, channels, width*height );
    stbi_write_png("assets/green.png",width,height,channels,data,0);

    //img_filler(destination_file, source_file, pixel_x, pixel_y, r, g,b);


    /*
        1- load image
        2- read pixel x,y 
        3- replace
        4- image_filler_algo(data, init_color, repl_col, x,y);
        5- save image (data)
    */
    stbi_image_free(data);
    return 0;
}

int main(){
    img_filler("./assets/green.png","./assets/test.png", 0,0,color_green());
    puts("ok");
}