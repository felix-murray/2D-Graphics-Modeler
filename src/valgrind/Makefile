CC = g++
FLAGS = -std=c++14 -Wall -g

all: vectorTest

vectorTest: valgrind.cpp
	$(CC) $(FLAGS) valgrind.cpp -o valgrind

clean:
	rm *.o valgrind valgrind.scr valgrind.tar
	
tar:
	tar cf valgrind.tar valgrind.scr Makefile valgrind.cpp shape_Vector.h