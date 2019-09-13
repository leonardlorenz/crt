CFLAGS=-Wall -Wextra -fsanitize=address
SRC=./src/*.c

create_dirs:
	test -d ./bin || mkdir ./bin
	test -d ./out || mkdir ./out

compile: create_dirs
	clang -o ./bin/crt.bin \
		$(CFLAGS) \
		$(SRC)

debug: create_dirs
	clang -g -v -o ./bin/debug.bin \
		$(CFLAGS) \
		$(SRC)

run:
	./bin/crt.bin ./out/image.ppm 256

build: compile

rebuild: compile run

clean:
	rm ./bin/*
