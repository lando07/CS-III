#include "util.h"
#include <vector>

int BOARD_SIZE = 15;
vector<vector<bool>> grid{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void printBoard();
void computeCell(int r, int c);

int main() {
  // Enter your code here
  int active = readInt(
      1, 225, "Please enter number of active cells between 1 and 225: ");
  for (int i = 0; i < active; i++) {
    int x = randInt(0, 14);
    int y = randInt(0, 14);
    grid[x][y] = 1;
  }
  while (true) {
    printBoard();
    string ans;
    cout << "Press enter to continue (exit to quit) ";
    getline(cin, ans);
    if (ans == "exit") {
      break;
    }
    cout << "Computing cells" << endl;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid.size(); c++) {
        computeCell(r, c);
        cout << "Computed cell " << r << ' ' << c << endl;
      }
    }
  }
  return 0;
}

void computeCell(int r, int c) {
  int aliveCells = 0;
  for (int row = r - 1; row <= r + 1; row++) {
    if (row >= grid.size()) {
      break;
    } else if (row < 0) {
      continue;
    }
    for (int col = c - 1; col <= c + 1; col++) {
      if (col >= grid.size()) {
        break;
      } else if (col < 0) {
        continue;
      }
      if (r == row && c == col) {
        continue;
      } else {
        if (grid[row][col]) {
          aliveCells++;
        }
      }
    }
  }
  if (grid[r][c]) {
    if (aliveCells < 2 && aliveCells > 3) {
      grid[r][c] = 0;
      cout << "Cell is now dead" << endl;
    }
  } else {
    if (aliveCells == 3) {
      grid[r][c] = 1;
      cout << "Cell is now alive" << endl;
    }
  }
}

void printBoard() {
  for (vector<bool> &row : grid) {
    for (bool state : row) {
      switch (state) {
      case true:
        cout << 'X';
        break;
      default:
        cout << 'O';
      }
    }
    cout << endl;
  }
}