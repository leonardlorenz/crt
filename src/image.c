#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/lodepng.h"
#include "image.h"

void image_setPixel(unsigned x, unsigned y, unsigned* color, Image img) {
    int pixelAddress = 3 * (y * img.width + x);
    img.image[pixelAddress] = image_gammaCorrect(color[0], img.gamma);
    img.image[pixelAddress + 1] = image_gammaCorrect(color[1], img.gamma);
    img.image[pixelAddress + 2] = image_gammaCorrect(color[2], img.gamma);
}

double image_gammaCorrect(double val, double gamma) {
    val = powf(val, 1 / gamma);
    return val;
}

/**
 * writes RGBA PNG images
 */
void image_write(unsigned height, unsigned width, const unsigned char* img, const char* filename) {
    unsigned error;
    unsigned char* png;
    size_t pngsize;

    error = lodepng_encode32(&png, &pngsize, img, width, height);

    if (!error) lodepng_save_file(png, pngsize, filename);
    if (error) printf("error %u: %s\n", error, lodepng_error_text(error));

    free(png);
}
