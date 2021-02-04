#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "src/image.h"

void printCurrentTime() {
    time_t now;
    time(&now); // time() returns the current time of the system as a time_t value
    printf("Today is : %s\n", ctime(&now));
}
/*
char *getName(char* filename) {
    char *s1 = strrchr(filename, '\\') + 1; //lena.jpg
    char *s2 = strrchr(filename, '.');      //.jpg
    //printf("%s\n", s1);
    //printf("%s\n", s2);
    char name[30];
    memset(name, '\0', sizeof(name));
    strncpy(name, s1, (strlen(s1)-strlen(s2)));//lena
    printf("%s\n", name);
    return name;
}*/

int main(int argc, char** argv) {
    printCurrentTime();
    
    if(argc != 2) {
        printf("usage: %s image_path\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *filename = argv[1];
    //printf("%s\n", argv[1]);
    
    char name[256];
    memset(name, '\0', sizeof(name));
    //printf("%s\n", argv[1]);
    {
        char *s1 = strrchr(filename, '/') + 1; //lena.jpg
        //printf("%s\n", argv[1]);
        char *s2 = strrchr(filename, '.');      //.jpg
        printf("%s\n", argv[1]);
        strncpy(name, s1, (strlen(s1)-strlen(s2)));
        
        //printf("%s\n", name);
    }
    
    
    //getName(filename);
    
    
    //char *filename = "F:\\2020\\Project2333\\lena.jpg";
    
    image im = load_image_color(filename, 0, 0);
    char output_name[256];
    
    printf("Croping image\n"); 
    image crop_im = random_crop_image(im, (im.w/2), (im.h/2));
    sprintf(output_name, "./outputs/%s-crop", name);
    save_image(crop_im, output_name);
    printf("image crop Done!\n\n");
    
    printf("Converting color-to-gray\n");    
    image gray_im = grayscale_image(im);
    sprintf(output_name, "./outputs/%s-gray", name);
    save_image(gray_im, output_name);
    printf("color-to-gray Done!\n\n");
    //printf("w: %d, h: %d, c: %d\n", gray_im.w, gray_im.h, gray_im.c);   
    
    printf("Sobel Edge Detecting\n");    
    image edge = sobel_edge_detection(im);
    sprintf(output_name, "./outputs/%s-sobel-edge", name);
    save_image(edge, output_name);
    printf("Sobel Edge Detect Done!\n\n");    

    printf("Converting RGB-to-BGR\n");    
    rgbgr_image(im);
    sprintf(output_name, "./outputs/%s-BGR", name);
    save_image(im, output_name);  
    printf("RGB-to-BGR Done!\n");      
    
    free_image(crop_im);
    free_image(gray_im);
    free_image(im);

    return EXIT_SUCCESS;
}
