LIBRARIES=lib/lodepng.c
CFLAGS=-Wall -Wextra -fsanitize=address

compile:
	clang -o out \
		$(LIBRARIES) $(CFLAGS) \
		main.c \
		image.c \

run:
	./out

clean:
	rm out *.png
