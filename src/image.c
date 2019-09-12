#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "image.h"

/** uint8_t* color: array with 4 elements, r/g/b/a */
void image_set_pixel(uint16_t x, uint16_t y, uint8_t* color, Image img) {
    int pixelAddress = 4 * img.width * y  + 4 * x;
    /** red */
    img.image[pixelAddress] = image_gamma_correct(color[0], img.gamma);
    /** green */
    img.image[pixelAddress + 1] = image_gamma_correct(color[1], img.gamma);
    /** blue */
    img.image[pixelAddress + 2] = image_gamma_correct(color[2], img.gamma);
    /** alpha */
    img.image[pixelAddress + 3] = color[3];
    //printf("%u, %u, %u\n", color[0], color[1], color[2]);
}

double image_gamma_correct(uint8_t val, double gamma) {
    /** value ^ (1/gamma) */
    val = powf(val, 1 / gamma);
    return val;
}
