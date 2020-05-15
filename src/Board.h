#ifndef __DCHESS_BOARD
#define __DCHESS_BOARD

#include "Pieces.h"

namespace DChess {
  typedef const unsigned short COORD;

  typedef struct {
    COORD x;
    COORD y;
  } Coordinate;

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
