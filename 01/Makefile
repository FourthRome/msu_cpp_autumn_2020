CC=g++
FLAGS=-std=c++17 -O2 -Wall -Werror -pedantic -Wextra -Wno-unused-variable

all: allocator

allocator: allocator.o test.o
	$(CC) $(FLAGS) -o test allocator.o test.o

allocator.o: allocator.cpp allocator.hpp
	$(CC) $(FLAGS) -c allocator.cpp

test.o: test.cpp allocator.hpp
	$(CC) $(FLAGS) -c test.cpp

clean:
	rm rf *.o test

test: allocator
	./test