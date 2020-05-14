#ifndef __DCHESS_BOARD
#define __DCHESS_BOARD

#include "Pieces.h"

namespace DChess {
  typedef const unsigned short COORD;

  class Board {
    public:
      virtual void move(COORD sourceX, COORD sourceY, COORD destX, COORD destY) = 0;
      virtual Piece* at(COORD x, COORD y) = 0;
      virtual std::string str() = 0;
  };
}
#endif
