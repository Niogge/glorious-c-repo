#include "filler_algo.h"
#include "stacki.h"
#include <stdlib.h>
//static == exists only inside filler_algo.c, not copied.

bool pixel_is_visitable(int x, int y, bool* pixel_visited, int w, int h){
    if(x<0 || x>= w) return false;
    if(y<0 || y>= h) return false;
    int index = (y*w+x);
    return pixel_visited[index]==false;
}
static void img_filler_algo_recurs(cbyte* data, int  width, int height, int channel, int pixel_x, int pixel_y, color* new_color, color* sample_color, bool* pixel_visited){
    // if(pixel_x<0 || pixel_x>= width) return;
    // if(pixel_y<0 || pixel_y>= height) return;

        int pixel_index = pixel_y*width + pixel_x;
        pixel_visited[pixel_index] = true;
        
        int data_pixel_index = pixel_index*channel;
        
        color* current_color = (color*)(&data[data_pixel_index]);//MIND. BLOWN. if there's no padding we're good to go.

        if(!color_equals(current_color, sample_color))return;
        //try with memset;
        data[data_pixel_index] = new_color->r;
        data[data_pixel_index+1] = new_color->g;
        data[data_pixel_index+2] = new_color->b;
        data[data_pixel_index+3] = new_color->a;



        if(pixel_is_visitable(pixel_x+1,pixel_y+0, pixel_visited, width,height))
            img_filler_algo_recurs(data, width,  height,  channel,  pixel_x+1,  pixel_y+0,  new_color,  sample_color,pixel_visited );//r
        if(pixel_is_visitable(pixel_x-1,pixel_y+0, pixel_visited, width,height))
            img_filler_algo_recurs(data, width,  height,  channel,  pixel_x-1,  pixel_y+0,  new_color,  sample_color,pixel_visited );//l
        if(pixel_is_visitable(pixel_x+0,pixel_y-1, pixel_visited, width,height))
            img_filler_algo_recurs(data, width,  height,  channel,  pixel_x+0,  pixel_y-1,  new_color,  sample_color,pixel_visited );//u
        if(pixel_is_visitable(pixel_x+0,pixel_y+1, pixel_visited, width,height))
            img_filler_algo_recurs(data, width,  height,  channel,  pixel_x+0,  pixel_y+1,  new_color,  sample_color,pixel_visited );//d

        
    

}
static void img_filler_algo_iter(cbyte* data, int  width, int height, int channel, color* new_color, color* sample_color, bool* pixel_visited, stacki* pixel_stack ){
    // if(pixel_x<0 || pixel_x>= width) return;
    // if(pixel_y<0 || pixel_y>= height) return;

    while(!stacki_is_empty(pixel_stack)){

        int pixel_index = stacki_pop(pixel_stack);
        pixel_visited[pixel_index] = true;
        
        int data_pixel_index = pixel_index*channel;
        
        color* current_color = (color*)(&data[data_pixel_index]);//MIND. BLOWN. if there's no padding we're good to go.

        if(!color_equals(current_color, sample_color))continue;
        //try with memset;
        data[data_pixel_index] = new_color->r;
        data[data_pixel_index+1] = new_color->g;
        data[data_pixel_index+2] = new_color->b;
        data[data_pixel_index+3] = new_color->a;

        int pixel_x = pixel_index%width;
        int pixel_y = pixel_index/width;
        if(pixel_is_visitable(pixel_x+1,pixel_y+0, pixel_visited, width,height)){
            int next_index= (pixel_y+0)*width + pixel_x+1;
            pixel_visited[next_index] = true;
            stacki_push(pixel_stack, next_index );
        }
        if(pixel_is_visitable(pixel_x-1,pixel_y+0, pixel_visited, width,height)){
            int next_index= (pixel_y+0)*width + pixel_x-1;
            pixel_visited[next_index] = true;

            stacki_push(pixel_stack, next_index );
        }
        if(pixel_is_visitable(pixel_x+0,pixel_y-1, pixel_visited, width,height)){
            int next_index= (pixel_y-1)*width + pixel_x;
            pixel_visited[next_index] = true;
            stacki_push(pixel_stack, next_index );
        }
        if(pixel_is_visitable(pixel_x+0,pixel_y+1, pixel_visited, width,height)){
            int next_index= (pixel_y+1)*width + pixel_x;
            pixel_visited[next_index] = true;
            stacki_push(pixel_stack, next_index );
        }

        
    }

}

void img_filler_algo(cbyte* data, int  width, int height, int channel, int pixel_x, int pixel_y, color new_color ){

    if(channel != 4) return;
    
   
    color sample_color; 
    int pixel_index = (pixel_y*width+pixel_x)*channel;
    sample_color.r = data[pixel_index];
    sample_color.g = data[pixel_index+1];
    sample_color.b = data[pixel_index+2];
    sample_color.a = data[pixel_index+3];

    bool* pixel_visited =(bool*)calloc(width*height,sizeof(bool));
    stacki* pixel_stack = stacki_new(width*height);

    // data[pixel_index +0 ]= new_color.r;
    // data[pixel_index +1 ]= new_color.g;
    // data[pixel_index +2 ]= new_color.b;

    stacki_push(pixel_stack, pixel_index);

        img_filler_algo_iter(data, width,  height,  channel,  &new_color,  &sample_color, pixel_visited, pixel_stack);
}
//Librerie:
//statiche: .lib
//dinamiche: .dll(.lib .def)