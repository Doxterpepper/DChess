#include "Colors.h"

namespace DChess {
  std::string getColorSymbol(Color color) {
    switch(color) {
      case White:
        return "W";
      case Black:
        return "B";
    }

    return "X";
  }
}
