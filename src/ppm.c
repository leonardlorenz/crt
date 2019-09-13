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

void write_rgb_ppm(Image img) {
    FILE* out_fd;
    out_fd = fopen(img.filename, "w");
    if (!out_fd) {
        fprintf(stderr, "Couldn't open file");
        exit(1);
    }

    /** write the image data **/
    char* line = malloc(1024);
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

    strcpy(line, strcat(strcat(strcat(width, " "), height), "\n"));
    write_line(line, out_fd);
    clear_line(line);

    free(width);
    free(height);

    strcpy(line, "255\n");
    write_line(line, out_fd);
    clear_line(line);

    for (int y = 0; y < img.height; y++) {
        /** reset line before appending new data **/
        clear_line(line);
        for (int x = 0; x < img.height; x++) {
            int pixelAddress = 4 * img.width * y  + 4 * x;
            /** Output format: **/
            /** Rval Gval Bval **/
            /** Rval Gval Bval **/
            /** Rval Gval Bval **/

            /** red */
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
            strcat(line, " ");

        }
        strcat(line, "\n");
        write_line(line, out_fd);
    }
    free(line);
    fclose(out_fd);
}
