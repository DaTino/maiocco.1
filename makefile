CC=gcc
CFLAGS=-I. -std=c99

all: proc_fan testsim

proc_fan: proc_fan.o
	$(CC) -o proc_fan proc_fan.o

testsim: testsim.o
	$(CC) -o testsim testsim.o
