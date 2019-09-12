CFLAGS=-Wall -Wextra -fsanitize=address

compile:
	clang -o out \
		$(CFLAGS) \
		src/main.c \
		src/image.c \
		src/ppm.c \

build: compile

run:
	./out

clean:
	rm out *.png
