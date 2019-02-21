#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main(int argc, char** argv) {
    const char* filename = argc > 1 ? argv[1] : "test.png";

    /*generate some image*/
    unsigned width = 512, height = 512;
    unsigned char* image = malloc(width * height * 4);
    unsigned x, y;
    for(y = 0; y < height; y++)
    for(x = 0; x < width; x++) {
        image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
        image[4 * width * y + 4 * x + 1] = x ^ y;
        image[4 * width * y + 4 * x + 2] = x | y;
        image[4 * width * y + 4 * x + 3] = 255;
    }
    image_write(height, width, image, filename);
}
