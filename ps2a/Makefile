all: 
	make ps2a

ps2a:  	test.o LFSR.o
	g++ LFSR.o test.o -o ps2a -lboost_unit_test_framework 

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic

test.o: test.cpp LFSR.hpp
	g++ -c test.cpp

clean:
	rm -f *.o ps2a *~
