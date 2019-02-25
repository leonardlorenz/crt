#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/lodepng.h"
#include "image.h"

void image_setPixel(unsigned x, unsigned y, unsigned* color, Image img) {
    int pixelAddress = 4 * img.width * y + 4 * x;
    /** red */
    img.image[pixelAddress] = image_gammaCorrect(color[0], img.gamma);
    /** green */
    img.image[pixelAddress + 1] = image_gammaCorrect(color[1], img.gamma);
    /** blue */
    img.image[pixelAddress + 2] = image_gammaCorrect(color[2], img.gamma);
    /** alpha */
    img.image[pixelAddress + 3] = color[3];
}

double image_gammaCorrect(double val, double gamma) {
    val = powf(val, 1 / gamma);
    return val;
}

/**
 * writes RGBA PNG images
 */
void image_write(Image png) {
    unsigned char* out;
    unsigned error;
    size_t pngsize;

    error = lodepng_encode32(&out, &pngsize, png.image, png.width, png.height);

    if (!error) lodepng_save_file(png.image, pngsize, png.filename);
    if (error) printf("error %u: %s\n", error, lodepng_error_text(error));

    free(png.image);
}
