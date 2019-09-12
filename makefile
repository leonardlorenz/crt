LIBRARIES=src/lib/lodepng.c
CFLAGS=-Wall -Wextra -fsanitize=address

compile:
	clang -o out \
		$(LIBRARIES) $(CFLAGS) \
		src/main.c \
		src/image.c \

run:
	./out

clean:
	rm out *.png
