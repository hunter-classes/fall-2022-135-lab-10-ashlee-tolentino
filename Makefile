main: main.o time.o
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o



time.o: time.cpp time.h Time_class.h

main.o: main.cpp time.h Time_class.h

tests.o: tests.cpp doctest.h time.h Time_class.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main.o time.o tests.o
