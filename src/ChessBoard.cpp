#include "ChessBoard.h"
#include <assert.h>

namespace DChess {
  /**
   * Construct a new chessboard. Constructs an 8x8 board with white and black pieces.
   */
  ChessBoard::ChessBoard() {
    // Initialize black pieces.
    board.push_back(new Piece(Rook, Black));
    board.push_back(new Piece(Knight, Black));
    board.push_back(new Piece(Bishop, Black));
    board.push_back(new Piece(Queen, Black));
    board.push_back(new Piece(King, Black));
    board.push_back(new Piece(Bishop, Black));
    board.push_back(new Piece(Knight, Black));
    board.push_back(new Piece(Rook, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));
    board.push_back(new Piece(Pawn, Black));

    // Fill empty spaces in the middle.
    for (int i = 0; i < 4 * 8; i++) {
      board.push_back(nullptr);
    }

    // Initialize White pieces.
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Pawn, White));
    board.push_back(new Piece(Rook, White));
    board.push_back(new Piece(Knight, White));
    board.push_back(new Piece(Bishop, White));
    board.push_back(new Piece(Queen, White));
    board.push_back(new Piece(King, White));
    board.push_back(new Piece(Bishop, White));
    board.push_back(new Piece(Knight, White));
    board.push_back(new Piece(Rook, White));

    assert(board.size() == xdim*ydim);
  }

  /**
   * Move a chess piece from source to destination. Coordinates must be within the 8x8 board.
   */
  void ChessBoard::move(COORD sourcex, COORD sourcey, COORD destx, COORD desty) {
    COORD source = sourcey * xdim + sourcex;
    COORD dest = desty * xdim + sourcex;

    assert((long unsigned int)source < board.size());
    assert((long unsigned int)dest < board.size());
    
    board[dest] = board[source];
    board[source] = nullptr;
  }

  /**
   * Get a chess piece at a given coordinate.
   */
  Piece* ChessBoard::at(COORD x, COORD y) {
    COORD position = y * xdim + x;
    assert((long unsigned int)(position) < board.size());
    return board[position];
  }

  /**
   * Convert board to a string for visualization.
   */
  std::string ChessBoard::str() {
    std::string boardString = "";

    for (int i = 0; i < ydim; i++) {
      for (int j = 0; j < xdim; j++) {
        Piece* square = this->board[xdim * i + j];

        if (square == nullptr) {
          boardString += ". ";
        } else {
          boardString += square->str();
        }

        if (j < xdim-1) {
          boardString += " ";
        }
      }

      if (i < ydim-1) {
        boardString += "\n";
      }
    }

    return boardString;
  }

  ChessBoard::~ChessBoard() {
    for (unsigned long int i = 0; i < this->board.size(); i++) {
      if (board[i] != nullptr) {
        delete this->board[i];
      }
    }
  }
}
