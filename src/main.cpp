#include <iostream>
#include "ChessBoard.h"

int main () {
  DChess::ChessBoard board;
  board.move(4,6, 4,4);
  std::cout << board.str() << std::endl;
}
