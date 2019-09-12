#include <stdint.h>

#ifndef IMAGE
#define IMAGE

typedef struct Image Image;

struct Image {
    uint16_t width;
    uint16_t height;
    double gamma;
    char* filename;
    unsigned char* image;
};

/**
 * sets a colour for a pixel at a specified address using an RGB value
 * parameters:
 * x_pos
 * y_pos
 * color
 * image
 */
void image_setPixel(uint16_t, uint16_t, uint8_t*, Image);

/**
 * takes a colour value and applies gamma correction
 * parameters:
 * red / green / blue value (0-255)
 * gamma correction factor
 */
double image_gammaCorrect(uint8_t, double);

/**
 * writes an image in 32bit float PNG format
 * parameters:
 * image
 */
void image_write(Image png);

#endif
