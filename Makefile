test02: test02.o
	g++ test02.o -o test02

test02.o: test02.cpp
	g++ -c test02.cpp

clean:
	rm -f *.o test02
