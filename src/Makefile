CC = g++
FLAGS = -std=c++14 -Wall -g

all: vectorTest

vectorTest: vectorTest.cpp
	$(CC) $(FLAGS) vectorTest.cpp -o vectorTest

clean:
	rm *.o vectorTest vectorTest.scr vectorTest.tar
	
tar:
	tar cf vectorTest.tar vectorTest.scr Makefile vectorTest.cpp vector.h