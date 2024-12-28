CXX = g++
CXXFLAGS = -Wall -pedantic
OBJFILES = board.o stone.o hand.o driver.o

stone.x: $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJFILES)

board.o: board.cpp board.h stone.h hand.h
	$(CXX) $(CXXFLAGS) -c board.cpp

stone.o: stone.cpp stone.h board.h
	$(CXX) $(CXXFLAGS) -c stone.cpp

hand.o: hand.cpp hand.h stone.h board.h
	$(CXX) $(CXXFLAGS) -c hand.cpp

driver.o: driver.cpp board.h stone.h hand.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

.PHONY: clean

clean:
	rm -f *.o stone.x