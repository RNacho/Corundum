SHELL = /bin/sh
CC = gcc
FLG = -Wall -Werror -Wextra -pedantic -pedantic-errors -std=c11 -O2
AR = ar rcs
SRC = $(filter-out sources/main.c, $(wildcard sources/*.c))
HDR = $(patsubst sources/%.c, headers/%.h, $(SRC))
OBJ = $(patsubst sources/%.c, objects/%.o, $(SRC))


all: executableLinux libCorundum.a
library: libCorundum.a


executableLinux: objects/main.o libCorundum.a
	${CC} ${FLG} -o compilation/executableLinux objects/main.o -Lcompilation -lCorundum

main.o: sources/main.c headers/main.h
	${CC} ${FLG} -c main.c -o objects/main.o

objects/%.o: sources/%.c headers/%.h
	$(CC) $(FLG) -c $< -o $@

libCorundum.a: ${OBJ}
	${AR} compilation/libCorundum.a ${OBJ}


clean:
	rm -f objects/*.o headers/*.gch
reset:
	rm -f compilation/* objects/* headers/*.gch
