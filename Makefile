CC = gcc
AR = ar
FLAGS = -Wall -g
EXECUTABLES = StrList

.PHONY: all clean

all: $(EXECUTABLES)
StrList: Main.o StrList.a
	$(CC) $(FLAGS) -o $@ $^

StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c $<

Main.o: Main.c StrList.o StrList.h
	$(CC) $(FLAGS) -c $<

StrList.a: StrList.o
	$(AR) -rcs $@ $^

clean: 
	rm -f *.o *.a *.so $(EXECUTABLES)