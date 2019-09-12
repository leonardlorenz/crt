#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "lib/lodepng.h"
#include "image.h"

/** uint8_t* color: array with 4 elements, r/g/b/a */
void image_setPixel(uint16_t x, uint16_t y, uint8_t* color, Image img) {
    int pixelAddress = 4 * img.width * y  + 4 * x;
    /** red */
    img.image[pixelAddress] = image_gammaCorrect(color[0], img.gamma);
    /** green */
    img.image[pixelAddress + 1] = image_gammaCorrect(color[1], img.gamma);
    /** blue */
    img.image[pixelAddress + 2] = image_gammaCorrect(color[2], img.gamma);
    /** alpha */
    img.image[pixelAddress + 3] = color[3];
    //printf("%u, %u, %u\n", color[0], color[1], color[2]);
}

double image_gammaCorrect(uint8_t val, double gamma) {
    /** value ^ (1/gamma) */
    val = powf(val, 1 / gamma);
    return val;
}

void image_write(Image img) {
    unsigned char* png;
    size_t pngsize;

    /** encode the image to the `png` char array (write png header, meta info) */
    unsigned int error = lodepng_encode32(&png, &pngsize, img.image, img.width, img.height);

    /** try to save the image to disk */
    if (!error) lodepng_save_file(img.image, pngsize, img.filename);
    if (error) printf("error %u: %s\n", error, lodepng_error_text(error));

    /** clear the byte array */
    free(png);
}
