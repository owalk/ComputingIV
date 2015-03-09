Recursion: main.o Recursion.o
	g++ main.o Recursion.o -o Recursion -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp Recursion.hpp
	g++ -c main.cpp
Recursion.o: Recursion.cpp Recursion.hpp
	g++ -c Recursion.cpp
clean:
	rm *.o Recursion *~
