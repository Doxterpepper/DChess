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
  void ChessBoard::move(Coordinate source, Coordinate dest) {
    COORD computedSource = source.y * xdim + source.x;
    COORD computedDest = dest.y * xdim + dest.x;

    assert((long unsigned int)computedSource < board.size());
    assert((long unsigned int)computedDest < board.size());
    
    board[computedDest] = board[computedSource];
    board[computedSource] = nullptr;
  }

  /**
   * Get a chess piece at a given coordinate.
   */
  Piece* ChessBoard::at(Coordinate coordinate) {
    COORD position = coordinate.y * xdim + coordinate.x;
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
