#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image.h"
#include "ppm.h"

void clamp(uint16_t integer) {
    if (integer > 255) { integer = 255; };
}

int main(int argc, char** argv) {
    Image img;
    img.width = 64;
    img.height = 64;
    img.gamma = 2.2;
    img.filename = argc > 1 ? argv[1] : "test.ppm";
    img.image = malloc(img.width * img.height * 4);

    /** generate some image **/
    uint8_t color[4];
    uint16_t x, y;
    for(y = 0; y < img.height; y++) {
        for(x = 0; x < img.width; x++) {

            color[0] = (uint8_t) (255 * !(x & y));
            color[1] = (uint8_t) (x ^ y);
            color[2] = (uint8_t) (x | y);
            color[3] = (uint8_t) 255;

            clamp(color[0]);
            clamp(color[1]);
            clamp(color[2]);
            clamp(color[3]);

            image_set_pixel(x, y, color, img);
        }
    }
    write_rgb_ppm(img);
    free(img.image);
}
