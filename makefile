CC=gcc
CFLAGS=-I.

proc_fan: proc_fan.o
     $(CC) -o proc_fan proc_fan.o
