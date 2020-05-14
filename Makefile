CXX=g++
CXXFLAGS=-Wall -g -std=c++11

dchess:  ChessBoard.o Pieces.o Colors.o src/main.cpp
	$(CXX) $+ $(CXXFLAGS) -o $@

ChessBoard.o: src/ChessBoard.cpp src/ChessBoard.h
	$(CXX) $(CXXFLAGS) -c $<

Pieces.o: src/Pieces.cpp src/Pieces.h
	$(CXX) $(CXXFLAGS) -c $<

Colors.o: src/Colors.cpp src/Colors.h
	$(CXX) $(CXXFLAGS) -c $<

ChessBoardTests: tests/ChessBoardTests.cpp Pieces.o Colors.o ChessBoard.o
	$(CXX) $(CXXFLAGS) -Isrc $+ -o $@

test: ChessBoardTests
	./$+

clean:
	rm -f *.o dchess ChessBoardTests
