all: grocery

grocery: main.o items.o fruits.o vegetables.o
	g++ main.o items.o fruits.o vegetables.o -o grocery

main.o: main.cpp
	g++ -c main.cpp

items.o: items.cpp
	g++ -c items.cpp

fruits.o: fruits.cpp
	g++ -c fruits.cpp

vegetables.o: vegetables.cpp
	g++ -c vegetables.cpp

clean:
	rm -f *o grocery
