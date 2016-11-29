all: main.cpp entry.h dbfunctions.h entry.cpp dice.h
	g++ -c entry.cpp
	g++ main.cpp entry.o -o FAQBOT.exe
	mkdir -p bin
	mv entry.o bin
	mv FAQBOT.exe bin

cluster.exe: main.cpp entry.h dbfunctions.h entry.cpp dice.h
	g++ -c entry.cpp
	g++ cluster.cpp entry.o -o CLUSTER.exe
	mkdir -p bin
	mv entry.o bin
	mv CLUSTER.exe bin

cluster:
	./bin/CLUSTER.exe database.txt

run:
	./bin/FAQBOT.exe database.txt

clean:
	rm -rf bin
