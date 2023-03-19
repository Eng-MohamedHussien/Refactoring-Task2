#include <clocale>
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

class Game {
  Player *players;
  char cells[10];
  char state;

public:
  Game(Player *players) : players(players), cells("---------"), state('-') {}
  void show_cells() const;
  void makeMove(int playerIndex, int cell);
  char checkWinner();
  void viewResult() const;
};