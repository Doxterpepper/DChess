#include "GameEngine.h"

namespace DChess {
  GameEngine::GameEngine(Board* gameBoard) {
    this->gameBoard = gameBoard;
  }

  void GameEngine::move(std::string command, Color player) {
    if (player != currentPlayer) {
      // Eventually want to throw an exception, I think.
      return;
    }

    this->flipCurrentPlayer();
  }

  void GameEngine::flipCurrentPlayer() {
    currentPlayer = currentPlayer == Black ? White : Black;
  }

  GameEngine::~GameEngine() {
    delete this->gameBoard;
  }
}
