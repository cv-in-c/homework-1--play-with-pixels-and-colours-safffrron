#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    //Using the CHW format
    //Assuming im.h gives image height , im.w gives image width and im.c gives total channels 
    //In this fn we only need to return the value of the pixel at column x , row y and channel c 
    //we know that im.data stores the value
    
    //checking bounds 
    if(((x<0||x>=im.w) || (y<0||y>=im.h))|| (c<0||c>=im.c))
    {
        return;
    }    
    
    float *value= im.data + (c * im.w * im.h)+(y * im.w)+ x;
    return *value;
}

void set_pixel(image im, int x, int y, int c, float v)
{
    //So in this function we just need to set the pixel to the given value 
    
    //checking bounds 
    if(((x<0||x>=im.w) || (y<0||y>=im.h))|| (c<0||c>=im.c))
    {
        return;
    }
    
    //setting value
    im.data[(c * im.w * im.h)+(y * im.w)+ x]=v;
    
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    //okay, so we just need to fill the data attribute 
    //we can loop by array 
    
    for(int i=0;i<((im.c)*(im.w)*(im.h));i++)
    {
       copy.data[i]=im.data[i];       
    }
        
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
