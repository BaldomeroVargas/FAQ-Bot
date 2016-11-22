all: main.cpp entry.h dbfunctions.h entry.cpp dice.h
	g++ -c entry.cpp
	g++ main.cpp entry.o

cluster: main.cpp entry.h dbfunctions.h entry.cpp dice.h
	g++ -c entry.cpp
	g++ cluster.cpp entry.o

clean:
	rm ./a.out *.o
