#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"
#include "image.h"

/** clears content of string buffer **/
void clear_line(char* line) {
    memset(&line[0], 0, sizeof(line));
}

/** writes line to output file **/
void write_line(char* line, FILE* out_fd) {
    fputs(line, out_fd);
    clear_line(line);
}

void write_rgb_ppm(Image img) {
    FILE* out_fd;
    out_fd = fopen(img.filename, "w");
    if (!out_fd) {
        fprintf(stderr, "Couldn't open file");
        exit(1);
    }

    /** write the image data **/
    // width of the image times the 3 color channels times 12 bytes to store the string values for each color in
    char* line = malloc(img.width * 3 * 12);
    if (!line) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }

    /** write the header **/
    strcpy(line, "P3\n");
    write_line(line, out_fd);
    clear_line(line);

    char* width = malloc(12);
    char* height = malloc(12);
    if (!width || !height) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }
    sprintf(width, "%d", img.width);
    sprintf(height, "%d", img.height);

    // image dimensions
    strcpy(line, strcat(strcat(strcat(width, " "), height), "\n"));
    write_line(line, out_fd);
    clear_line(line);

    free(width);
    free(height);

    // color depth
    strcpy(line, "255\n");
    write_line(line, out_fd);
    clear_line(line);

    /** write actual image data **/
    uint64_t pixel_address;
    for (int y = 0; y < img.height; y++) {
        /** reset line before appending new data **/
        clear_line(line);
        for (int x = 0; x < img.width; x++) {
            pixel_address = 4 * img.width * y  + 4 * x;
            /** Output format: **/
            /** Rval Gval Bval Rval Gval Bval**/
            /** Rval Gval Bval Rval Gval Bval**/
            /** Rval Gval Bval Rval Gval Bval**/

            /** red */
            char red[12];
            sprintf(red, "%d", img.image[pixel_address]);

            /** green */
            char green[12];
            sprintf(green, "%d", img.image[pixel_address + 1]);

            /** blue */
            char blue[12];
            sprintf(blue, "%d", img.image[pixel_address + 2]);

            strcat(line, red);
            strcat(line, " ");
            strcat(line, green);
            strcat(line, " ");
            strcat(line, blue);
            strcat(line, " ");
        }
        strcat(line, "\n");
        write_line(line, out_fd);
    }
    free(line);
    fclose(out_fd);
}
