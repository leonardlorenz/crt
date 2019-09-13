#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image.h"
#include "ppm.h"

int clamp(uint32_t integer) {
    if (integer > 255) { integer = 255; };
    if (integer < 0) { integer = 0; };
    return integer;
}

int main(int argc, char** argv) {
    Image img;
    img.width = 1024;
    img.height = 1024;
    img.gamma = 2.2;
    img.filename = argc > 1 ? argv[1] : "test.ppm";
    img.image = malloc(img.width * img.height * 4);

    /** generate some image **/
    uint8_t color[4];
    uint16_t x, y;
    uint64_t pixel_address;
    for(y = 0; y < img.height; y++) {
        for(x = 0; x < img.width; x++) {
            pixel_address = 4 * img.width * y  + 4 * x;

            color[0] = (uint8_t) clamp(255 * !(x & y));
            color[1] = (uint8_t) clamp(x ^ y);
            color[2] = (uint8_t) clamp(x | y);
            color[3] = (uint8_t) clamp(255);

            image_set_pixel(pixel_address, color, img);
        }
    }
    write_rgb_ppm(img);
    free(img.image);
}
