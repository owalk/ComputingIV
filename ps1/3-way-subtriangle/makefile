all: fractal

fractal: main.o fractal.o
	g++ main.o fractal.o -o fractal -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp fractal.hpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

fractal.o: fractal.cpp fractal.hpp
	g++ -c fractal.cpp -Wall -Werror -ansi -pedantic

clean:
	rm *.o fractal *~
