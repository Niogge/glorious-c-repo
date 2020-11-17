
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

stbi_uc* swapChannels(stbi_uc* buffer, int from, int to, int channels, int buffer_size){

    for (int i = 0; i < buffer_size; i++)
    {
        int index = i* channels;
        char temp = buffer[index+to];
        buffer[index+to] = buffer[index+from];
        buffer[index+from] = temp;
    }
    return buffer;
    
}

int main(){
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


    data  = swapChannels(data, 0, 1, channels, width*height );
    stbi_write_png("assets/green.png",width,height,channels,data,4);

    
    stbi_image_free(data);
}