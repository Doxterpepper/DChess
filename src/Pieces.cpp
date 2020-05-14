#include "Pieces.h"

namespace DChess {
  Piece::Piece(PieceType type, Color color) {
    this->type = type;
    this->color = color;
  }

  std::string Piece::str() {
    return getColorSymbol(this->color) + getPieceTypeSymbol(this->type);
  }

  std::string getPieceTypeSymbol(PieceType type) {
    switch (type) {
      case Knight:
        return "N";
      case Bishop:
        return "B";
      case Rook:
        return "R";
      case King:
        return "K";
      case Queen:
        return "Q";
      case Pawn:
        return "P";
    }
  
    return "X";
  }
}
