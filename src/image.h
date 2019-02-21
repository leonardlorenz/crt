#ifndef IMAGE
#define IMAGE

typedef struct Image Image;

struct Image {
    unsigned width;
    unsigned height;
    double gamma;
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
void image_setPixel(unsigned, unsigned, unsigned*, Image);

/**
 * takes a colour value and applies gamma correction
 */
double image_gammaCorrect(double, double);

/**
 * writes an image in 32bit float PNG format
 */
void image_write(unsigned, unsigned, const unsigned char*, const char*);

#endif
