#include <stdint.h>

#ifndef IMAGE_H
#define IMAGE_H

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
void image_set_pixel(uint16_t, uint16_t, uint8_t*, Image);

/**
 * takes a colour value and applies gamma correction
 * parameters:
 * red / green / blue value (0-255)
 * gamma correction factor
 */
double image_gamma_correct(uint8_t, double);

#endif
