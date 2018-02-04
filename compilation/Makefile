SHELL = /bin/sh

CC=gcc
FLG=-Wall -Werror -Wextra -pedantic -pedantic-errors -std=c11 -O2
AR=ar rcs
SRC=../sources/
HDR=../headers/


all: executableLinux

executableLinux: main.o libCorundum.a
	${CC} ${FLG} -o executableLinux main.o -L. -lCorundum

main.o: main.c ${HDR}master.h
	${CC} ${FLG} -c main.c ${HDR}master.h

readStdin.o: ${SRC}readStdin.c ${HDR}readStdin.h
	${CC} ${FLG} -c ${SRC}readStdin.c

splitString.o: ${SRC}splitString.c ${HDR}splitString.h
	${CC} ${FLG} -c ${SRC}splitString.c

libCorundum.a: readStdin.o splitString.o
	${AR} libCorundum.a readStdin.o splitString.o

libs: libCorundum.a

clean:
	rm -f *.o
reset:
	rm -f executableLinux *.o *.a
