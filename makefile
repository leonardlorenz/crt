CFLAGS=-Wall -Wextra -fsanitize=address
SRC=./src/*.c

compile:
	clang -o ./bin/crt.bin \
		$(CFLAGS) \
		$(SRC)

debug:
	clang -g -v -o ./bin/debug.bin \
		$(CFLAGS) \
		$(SRC)

run:
	./bin/crt.bin

build: compile

rebuild: compile run

clean:
	rm ./bin/*
