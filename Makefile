STD=-std=c++0x

all: test02

test02: test02.o
	g++ $(STD) test02.o -o test02

test02.o: test02.cpp
	g++ $(STD) -c test02.cpp

clean:
	rm -f *.o test02
