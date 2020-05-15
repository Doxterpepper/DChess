#ifndef __DCHESS_GAME_ENGINE
#define __DCHESS_GAME_ENGINE

#include <string>
#include <vector>
#include "Board.h"
#include "Colors.h"
#include "Pieces.h"

namespace DChess {
  class GameEngine {
    private:
      Board* gameBoard;
      std::vector<Piece> whiteTakenPieces;
      std::vector<Piece> blackTakenPieces;
      Color currentPlayer;

      void flipCurrentPlayer();

    public:
      GameEngine(Board*);
      ~GameEngine();
      void move(std::string command, Color player);
      std::string str();
  };
}

#endif
