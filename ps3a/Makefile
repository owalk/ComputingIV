all: 
	make NBody

NBody: body.o main.o
	g++ Body.o main.o -o NBody -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Body.hpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

body.o: Body.cpp Body.hpp
	g++ -c Body.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -f *.o NBody *~
