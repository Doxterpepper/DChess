#ifndef __DCHESS_PIECES
#define __DCHESS_PIECES

#include <string>
#include "Colors.h"

namespace DChess {
  enum PieceType {
    Knight,
    Bishop,
    Rook,
    King,
    Queen,
    Pawn
  };

  class Piece {
    public:
      PieceType type;
      Color color;
      Piece(PieceType type, Color color);
      std::string str();
  };

  std::string getPieceTypeSymbol(PieceType type);
}
#endif
