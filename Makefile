all: battleship

CXXFLAGS=-g -Wall

Ship.o: Ship.cpp Ship.h
Board.o: Board.cpp Board.h Ship.h
battleship.o: battleship.cpp Ship.h Board.h

battleship: battleship.o Board.o Ship.o
	$(CXX) -o $@ $^  $(LDFLAGS)

clean:
	rm -f *.o battleship
