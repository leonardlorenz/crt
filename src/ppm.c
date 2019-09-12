#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"
#include "image.h"

void clear_line(char* line) {
    memset(&line[0], 0, sizeof(line));
}

void write_line(char* line, FILE* out_fd) {
    if (sizeof(line) < 256) {
        fputs(line, out_fd);
        clear_line(line);
    } else {
        fprintf(stderr, "The line to output was longer than 256 bytes.");
        exit(1);
    }
}

void write_ppm(Image img) {
    FILE* out_fd;
    out_fd = fopen(img.filename, "w");
    if (!out_fd) {
        fprintf(stderr, "Couldn't open file");
        exit(1);
    }

    /** write the header **/
    write_line("P3", out_fd);

    char* width = malloc(32);
    char* height = malloc(32);
    if (!width || !height) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }
    sprintf(width,"%d", img.width);
    sprintf(height,"%d", img.height);

    char* dimensions = malloc(128);
    if (!dimensions) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }
    strcpy(dimensions, strcat(strcat(width, " "), height));
    free(width);
    free(height);

    write_line(dimensions, out_fd);

    write_line("255", out_fd);

    char* line = malloc(1024);
    if (!line) {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.height; x++) {
            int pixelAddress = 4 * img.width * y  + 4 * x;
            /** Output format: **/
            /** Rval Gval Bval **/
            /** Rval Gval Bval **/
            /** Rval Gval Bval **/

            /** red */
            sprintf(width,"%d", img.width);
            char red[12];
            sprintf(red, "%d", img.image[pixelAddress]);

            /** green */
            char green[12];
            sprintf(green, "%d", img.image[pixelAddress + 1]);

            /** blue */
            char blue[12];
            sprintf(blue, "%d", img.image[pixelAddress + 2]);

            strcat(line, red);
            strcat(line, " ");
            strcat(line, green);
            strcat(line, " ");
            strcat(line, blue);

            write_line(line, out_fd);
        }
    }
    free(line);
    fclose(out_fd);
}
