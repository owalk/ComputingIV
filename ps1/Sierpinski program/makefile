all: Sierpinski

Sierpinski: main.o Sierpinski.o
	g++ main.o Sierpinski.o -o Sierpinski -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Sierpinski.hpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

Sierpinski.o: Sierpinski.cpp Sierpinski.hpp
	g++ -c Sierpinski.cpp -Wall -Werror -ansi -pedantic

clean:
	rm *.o Sierpinski *~
