#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image.h"

void clamp(uint16_t integer) {
    if (integer > 255) { integer = 255; };
}

int main(int argc, char** argv) {
    Image png;
    png.width = 512;
    png.height = 512;
    png.gamma = 2.2;
    png.filename = argc > 1 ? argv[1] : "test.png";
    png.image = malloc(png.width * png.height * 4);

    /*generate some image*/
    uint8_t color[4];
    uint32_t x, y;
    for(y = 0; y < png.height; y++) {
        for(x = 0; x < png.width; x++) {

            color[0] = (uint8_t) (255 * !(x & y));
            color[1] = (uint8_t) (x ^ y);
            color[2] = (uint8_t) (x | y);
            color[3] = (uint8_t) 255;

            clamp((uint8_t)color[0]);
            clamp((uint8_t)color[1]);
            clamp((uint8_t)color[2]);
            clamp((uint8_t)color[3]);

            printf("%u, %u, %u\n", color[0], color[1], color[2]);
            image_setPixel(x, y, color, png);
        }
    }
    image_write(png);
    free(png.image);
}
