#ifndef __DCHESS_COLOR
#define __DCHESS_COLOR

#include <string>
namespace DChess{
  enum Color {
    White,
    Black
  };

  std::string getColorSymbol(Color color);
}
#endif
