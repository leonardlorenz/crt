LIBRARIES=lib/lodepng.h lib/lodepng.c
CFLAGS=-lm

compile:
	gcc main.c \
		image.h image.c \
		$(LIBRARIES) $(CFLAGS) \
		-o out

run:
	./out

clean:
	rm out *.png
