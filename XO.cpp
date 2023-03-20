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

bool checkEmptyCell(const std::string &cells, int index) {
  return cells[index - 1] == '-';
}

bool validPlayerIndex(int index) {
  return index == int(PlayerMarker::player1) ||
         index == int(PlayerMarker::player2);
}

bool validCellIndex(int index) {
  return index <= int(CellRange::end) && index >= int(CellRange::start);
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

bool matchHorizontal(const std::string &cells, int index) {
  return cells[index * 3] == cells[index * 3 + 1] &&
         cells[index * 3 + 1] == cells[index * 3 + 2];
}

bool matchVertical(const std::string &cells, int index) {
  return cells[index] == cells[index + 3] &&
         cells[index + 3] == cells[index + 6];
}

bool matchDiagonal(const std::string &cells, int centerIndex = 5) {
  return (cells[centerIndex] == cells[centerIndex + 4] &&
          cells[centerIndex] == cells[centerIndex - 4]) ||
         (cells[centerIndex] == cells[centerIndex + 2] &&
          cells[centerIndex] == cells[centerIndex - 2]);
}

char Game::checkWinner() {
  for (int i = 0; i < 3; i++) {
    if (matchHorizontal(cells, i))
      state = cells[i];
    if (matchVertical(cells, i))
      state = cells[i];
  }

  if (matchDiagonal(cells)) {
    state = cells[0];
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
  } else {
    cout << "Draw" << endl;
  }
}