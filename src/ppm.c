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

    char width[12];
    char height[12];
    sprintf(width,"%d", img.width);
    sprintf(height,"%d", img.height);

    char* dimensions = strcat(strcat(width, " "), height);

    write_line(dimensions, out_fd);

    write_line("255", out_fd);

    char* line;
    clear_line(line);

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
}
