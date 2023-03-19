#include "XO.h"

void Game::show_cells() const {
  system("cls");
  for (int i = 0; i < 3; i++) {
    cout << "-" << 2 * (i + 1) + 1 << "-"
         << "|"
         << "-" << 2 * (i + 1) + 2 << "-"
         << "|"
         << "-" << 2 * (i + 1) + 3 << "-" << endl;
  }

  cout << "Current state (\"---\" - empty cell):\n" << endl;

  for (int i = 0; i < 3; i++) {
    cout << "-" << cells[2 * i + 1] << "-"
         << "|"
         << "-" << cells[2 * i + 2] << "-"
         << "|"
         << "-" << cells[2 * i + 3] << "-" << endl;
  }
}

bool checkEmptyCell(char *cells, int index) {
  if (cells[index - 1] != 'O' && cells[index - 1] != 'X') {
    return true;
  }
  return false;
}

bool validPlayerIndex(int index) {
  if (index != 1 && index != 2) {
    return false;
  }

  return true;
}

bool validCellIndex(int index) {
  if (index > 9 || index < 1) {
    return false;
  }
  return true;
}

void Game::makeMove(int playerIndex, int cell) {
  if (!validPlayerIndex(playerIndex)) {
    throw "Invalid player !!!";
  }

  if (!validCellIndex(cell) || !checkEmptyCell(cells, cell)) {
    throw "Invalid cell !!!";
  }

  cells[cell - 1] = players[playerIndex - 1].getSymbol();
}

bool matchHorizontal(char *cells, int index) {
  if (cells[index * 3] == cells[index * 3 + 1] &&
      cells[index * 3 + 1] == cells[index * 3 + 2]) {
    return true;
  }

  return false;
}

bool matchVertical(char *cells, int index) {
  if (cells[index] == cells[index + 3] &&
      cells[index + 3] == cells[index + 6]) {
    return true;
  }

  return false;
}

bool matchDiagonal1(char *cells, int index) {
  if (cells[index] == cells[index + 2] &&
      cells[index + 2] == cells[index + 4]) {
    return true;
  }

  return false;
}

bool matchDiagonal2(char *cells, int index) {
  if (cells[index] == cells[index * 2] &&
      cells[index * 2] == cells[index * 4]) {
    return true;
  }

  return false;
}

char Game::checkWinner() {
  for (int i = 0; i < 3; i++) {
    if (matchHorizontal(cells, i))
      state = cells[i];
    if (matchVertical(cells, i))
      state = cells[i];
  }

  if (matchDiagonal1(cells, 0)) {
    state = cells[0];
  }

  if (matchDiagonal2(cells, 2)) {
    state = cells[2];
  }

  return state;
}

void Game::viewResult() const {
  if (state == players[0].getSymbol()) {
    cout << players[0].getName() << "You win! " << players[1].getName()
         << " but you loose..." << endl;
  } else if (state == players[1].getSymbol()) {
    cout << players[1].getName() << "You win!  " << players[0].getName()
         << " but you loose..." << endl;
  }
}