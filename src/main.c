#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image.h"
#include "ppm.h"

int main(int argc, char** argv) {

    if (argc < 2) {
        fprintf(stderr, "crt <output_path> <img_size");
        exit(1);
    }

    /** convert input parameter string to integer **/
    char* ptr;
    long width;
    width = strtol(argv[2], &ptr, 10);

    /** define image **/
    Image img;
    img.filename = argv[1];
    img.width = width;
    img.height = width;
    img.gamma = 2.2;
    img.image = malloc(img.width * img.height * 4);

    /** generate some image **/
    uint8_t color[4];
    uint16_t x, y;
    uint64_t pixel_address;
    for(y = 0; y < img.height; y++) {
        for(x = 0; x < img.width; x++) {
            pixel_address = 4 * img.width * y  + 4 * x;

            color[0] = clamp(255 * !(x & y));
            color[1] = clamp(x ^ y);
            color[2] = clamp(x | y);
            color[3] = clamp(255);

            image_set_pixel(pixel_address, color, img);
        }
    }
    write_rgb_ppm(img);
    free(img.image);
}
