CC=gcc
CFLAGS=-I.

all: proc_fan testsim

proc_fan: proc_fan.o
	$(CC) -o proc_fan proc_fan.o

testsim: testsim.o
	$(CC) -o testsim testsim.o

clean:
	rm proc_fan.o testsim.o
