#include "filler.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void img_filler(const char* destination, const char* source, int pixel_x, int pixel_y, color new_color)
{
    int width,height,channels;
    cbyte* data = stbi_load(source,&width, &height, &channels,0);
    if(data ==NULL) return;
    
    img_filler_algo(data, width,height,channels,pixel_x,pixel_y,new_color);
    stbi_write_png(destination,width,height,channels,data,0);
    stbi_image_free(data);
}