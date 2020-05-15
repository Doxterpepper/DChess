
#define CATCH_CONFIG_MAIN

#include "catch.hpp" 
#include <ChessBoard.h>
#include <Colors.h>
#include <Pieces.h>
#include <string>

TEST_CASE("Construct and print board", "[game-board]") {
  std::string expectedString = "BR BN BB BQ BK BB BN BR\n\
BP BP BP BP BP BP BP BP\n\
.  .  .  .  .  .  .  . \n\
.  .  .  .  .  .  .  . \n\
.  .  .  .  .  .  .  . \n\
.  .  .  .  .  .  .  . \n\
WP WP WP WP WP WP WP WP\n\
WR WN WB WQ WK WB WN WR";
  DChess::ChessBoard board;
  REQUIRE(board.str() == expectedString);
}

TEST_CASE("Should be able to get chess piece on the board", "[game-board]") {
  DChess::ChessBoard board;

  DChess::Piece* piece = board.at({0, 0});
  REQUIRE(piece->color == DChess::Black);
  REQUIRE(piece->type == DChess::Rook);

  piece = board.at({4, 4});
  REQUIRE(piece == nullptr);

  piece = board.at({7, 7});
  REQUIRE(piece->color == DChess::White);
  REQUIRE(piece->type == DChess::Rook);
}

TEST_CASE("Should be able to move chess pieces on board", "[game-board]") {
  DChess::ChessBoard board;

  // Sanity check.
  // Destination square should be empty.
  REQUIRE(board.at({4, 4}) == nullptr);
  // Source square should not be empty.
  REQUIRE(board.at({4, 6}) != nullptr);
  REQUIRE(board.at({4, 6}) != nullptr);

  // move white kings pawn forward one.
  board.move({4, 6}, {4, 4});

  // Make sure the piece at 4, 4 is actually the pawn.
  DChess::Piece* piece = board.at({4, 4});
  REQUIRE(piece != nullptr);
  REQUIRE(board.at({4, 6}) == nullptr);
  REQUIRE(piece->color == DChess::White);
  REQUIRE(piece->type == DChess::Pawn);
}
