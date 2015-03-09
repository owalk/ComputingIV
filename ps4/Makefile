all:
	make editDistance

editDistance: ED.o main.o
	g++ ED.o main.o -o editDistance -lsfml-graphics -lsfml-window -lsfml-system

ED.o: ED.cpp ED.hpp
	g++ -c ED.cpp -Wall -Werror -ansi -pedantic

main.o: main.cpp ED.hpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -rf *.o editDistance *~
