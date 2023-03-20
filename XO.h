#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

class Player {
  string name;
  char symbol;

public:
  Player(const string &name, char symbol) : name(name), symbol(symbol) {}
  const string &getName() const { return name; }
  char getSymbol() const { return symbol; }
};

enum class CellRange { start = 1, end = 9 };
enum class PlayerMarker { player1 = 1, player2 };

class Game {
  Player *players;
  string cells;
  char state;

public:
  Game(Player *players) : players(players), cells("---------"), state('-') {
    assert(players[0].getSymbol() != players[1].getSymbol());
  }
  void show_cells() const;
  void makeMove(int playerIndex, int cell);
  char checkWinner();
  void viewResult() const;
};