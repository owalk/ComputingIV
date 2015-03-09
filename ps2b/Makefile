all: 
	make PhotoMagic_extra
	make PhotoMagic

PhotoMagic_extra: extra.o LFSR.o
	g++ LFSR.o extra.o -o PhotoMagic_extra -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system

extra.o: extra.cpp LFSR.o
	g++ -c extra.cpp -Wall -Werror -ansi -pedantic

PhotoMagic: PhotoMagic.o LFSR.o
	g++ LFSR.o PhotoMagic.o -o PhotoMagic -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	g++ -c PhotoMagic.cpp -Wall -Werror -ansi -pedantic

clean:
	rm -f *.o PhotoMagic PhotoMagic_extra *~
