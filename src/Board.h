#ifndef __DCHESS_BOARD
#define __DCHESS_BOARD

#include "Coordinates.h"
#include "Pieces.h"

namespace DChess {
  class Board {
    public:
      virtual void move(Coordinate source, Coordinate dest) = 0;
      virtual Piece* at(Coordinate) = 0;
      virtual std::string str() = 0;

      // Virtual destructor.
      virtual ~Board() {}
  };
}
#endif
