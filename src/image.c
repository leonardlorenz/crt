#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "image.h"

/** uint8_t* color: array with 4 elements, r/g/b/a */
void image_set_pixel(uint64_t pixel_address, uint8_t* color, Image img) {

    /** red **/
    img.image[pixel_address] = image_gamma_correct(color[0], img.gamma);
    /** green **/
    img.image[pixel_address + 1] = image_gamma_correct(color[1], img.gamma);
    /** blue **/
    img.image[pixel_address + 2] = image_gamma_correct(color[2], img.gamma);
    /** alpha **/
    img.image[pixel_address + 3] = color[3];
}

double image_gamma_correct(uint8_t val, double gamma) {
    /** value ^ (1/gamma) **/
    //val = (int) powf((double) val, 2.2);
    return val;
}
