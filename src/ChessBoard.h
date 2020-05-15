#ifndef __DCHESS_CHESS_BOARD
#define __DCHESS_CHESS_BOARD

#include <vector>
#include <string>

#include "Pieces.h"
#include "Colors.h"
#include "Board.h"

namespace DChess { 
  /**
   * Chess board class providing naive board functionality.
   */
  class ChessBoard : public Board {
    private:
      std::vector<Piece*> board;
      const unsigned short xdim = 8;
      const unsigned short ydim = 8;

    public:
      /**
       * Constructor for the chess board. Creates an 8x8 chess board with pointers to each
       * piece. Empty squares represented by nullptr, so be careful.
       */
      ChessBoard();

      /**
       * Destructor, cleans up all pieces
       */
      ~ChessBoard();

      /**
       * Move pieces on the board. Replaces whatever is in the destination with the source piece.
       */
      void move(Coordinate source, Coordinate dest);

      /**
       * Gets the piece at coordinate designated by x and y.
       *
       * x: x coordinate of the board.
       * y: y coordiante of the board.
       */
      Piece* at(Coordinate coordinate);

      /**
       * Converts the game board to a string for printing.
       */
      std::string str();
  };
}
#endif
