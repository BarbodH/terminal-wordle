CC=gcc
CFLAGS=-Wall

all: yorkle

yorkle: yorkle.o main.o

clean:
	-rm -rf yorkle.o main.o yorkle
tidy: clean
	-rm -rf *~

.PHONY: all clean tidy

