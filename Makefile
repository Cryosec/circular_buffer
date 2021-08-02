CXXFLAGS = -DNDEBUG

cbuffer: main.o person.o
	g++ main.o person.o -o cbuffer

main.o: main.cpp
	g++ $(CXXFLAGS) -std=c++0x -c main.cpp -o main.o

person.o: person.cpp
	g++ $(CXXFLAGS) -std=c++0x -c person.cpp -o person.o

.PHONY: clean

clean:
	rm cbuffer *.o
