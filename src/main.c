#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main(int argc, char** argv) {
    Image png;
    png.width = 512;
    png.height = 512;
    png.gamma = 2.2;
    png.filename = argc > 1 ? argv[1] : "test.png";
    png.image = malloc(png.width * png.height * 4);

    /*generate some image*/
    unsigned* color = malloc(4);
    unsigned x, y;
    for(y = 0; y < png.height; y++)
    for(x = 0; x < png.width; x++) {
        color[0] = 255 * !(x & y);
        color[1] = x ^ y;
        color[2] = x | y;
        color[3] = 255;
        image_setPixel(x, y, color, png);
    }
    free(color);
    image_write(png);
}
