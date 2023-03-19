#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"

#include <XO.h>

TEST_CASE("Test Player class") {
  Player testPlayer("Messi", 'X');
  SUBCASE("Test getName function") { CHECK(testPlayer.getName() == "Messi"); }

  SUBCASE("Test getSymbol function") { CHECK(testPlayer.getSymbol() == 'X'); }
}

TEST_CASE("Test Game class") {
  Player players[2] = {{"Messi", 'X'}, {"CR7", 'O'}};
  Game g(players);
  SUBCASE("Winner Test") {
    g.makeMove(1, 1);
    g.makeMove(2, 5);
    g.makeMove(1, 3);
    g.makeMove(2, 2);
    g.makeMove(1, 7);
    g.makeMove(2, 8);
    CHECK(g.checkWinner() == players[1].getSymbol());
  }

  SUBCASE("Draw Test") {
    g.makeMove(1, 1);
    g.makeMove(2, 5);
    g.makeMove(1, 3);
    g.makeMove(2, 2);
    g.makeMove(1, 8);
    g.makeMove(2, 7);
    g.makeMove(1, 9);
    g.makeMove(2, 6);
    g.makeMove(1, 4);
    CHECK(g.checkWinner() == '-');
  }

  SUBCASE("Validation Tests") {
    CHECK_THROWS_WITH(g.makeMove(3, 1), "Invalid player !!!");
    CHECK_THROWS_WITH(g.makeMove(0, 1), "Invalid player !!!");
    g.makeMove(1, 2);
    CHECK_THROWS_WITH(g.makeMove(2, 2), "Invalid cell !!!");
    CHECK_THROWS_WITH(g.makeMove(2, 0), "Invalid cell !!!");
    CHECK_THROWS_WITH(g.makeMove(2, 10), "Invalid cell !!!");
  }
}