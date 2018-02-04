SHELL = /bin/sh
CC = gcc
FLG = -Wall -Werror -Wextra -pedantic -pedantic-errors -std=c11 -O2
AR = ar rcs
SRC = $(filter-out sources/main.c, $(wildcard sources/*.c))
HDR = $(patsubst sources/%.c, headers/%.h, $(SRC))
OBJ = $(patsubst sources/%.c, objects/%.o, $(SRC))


all: compilation/executableLinux compilation/libCorundum.a
library: libCorundum.a


compilation/executableLinux: objects/main.o compilation/libCorundum.a
	${CC} ${FLG} -o compilation/executableLinux objects/main.o -Lcompilation -lCorundum

objects/main.o: sources/main.c headers/Corundum.h
	${CC} ${FLG} -c sources/main.c -o objects/main.o

objects/%.o: sources/%.c headers/%.h
	$(CC) $(FLG) -c $< -o $@

compilation/libCorundum.a: ${OBJ}
	${AR} compilation/libCorundum.a ${OBJ}


clean:
	rm -f objects/*.o headers/*.gch
reset:
	rm -f compilation/* objects/* headers/*.gch
