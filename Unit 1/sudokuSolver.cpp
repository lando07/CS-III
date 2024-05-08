#include "util.h"
#include <string>
#include <vector>

bool nextEmpty(vector<vector<char>> &puzzle, int &row, int &col);
bool isValid(vector<vector<char>> &puzzle, int row, int col, char testNum);
void printPuzzle(vector<vector<char>> &puzzle);

bool sudokuSolver(vector<vector<char>> &puzzle, int r, int c) {

  if (!nextEmpty(puzzle, r, c)) {
    return true;
  }
  for (char i = '1'; i <= '9'; i++) {
    if (isValid(puzzle, r, c, i)) {
      puzzle[r][c] = i;
      if (sudokuSolver(puzzle, r, c)) {
        return true;
      }
      puzzle[r][c] = ' ';
    }
  }
  return false;
}

bool nextEmpty(vector<vector<char>> &puzzle, int &row, int &col) {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      if (puzzle[r][c] == ' ') {
        row = r;
        col = c;
        return true;
      }
    }
  }
  return false;
}

bool isValid(vector<vector<char>> &puzzle, int row, int col, char testNum) {
  if (puzzle[row][col] != ' ') {
    return false;
  }
  for (int c = 0; c < 9; c++) {
    if (c == col) {
      continue;
    }
    if (puzzle[row][c] == testNum) {
      return false;
    }
  }
  for (int r = 0; r < 9; r++) {
    if (r == row) {
      continue;
    }
    if (puzzle[r][col] == testNum) {
      return false;
    }
  }

  int currBoxR = row - (row % 3);
  int currBoxC = col - (col % 3);
  for (int r = currBoxR; r < currBoxR + 3; r++) {
    for (int c = currBoxC; c < currBoxC + 3; c++) {
      if (r == row && c == col) {
        continue;
      }
      if (puzzle[r][c] == testNum) {
        return false;
      }
    }
  }

  return true;
}

void printPuzzle(vector<vector<char>> &puzzle) {
  // Enter your code here
  for (int r = 0; r < 9; r++) {
    if (r % 3 == 0) {
      cout << "|-----|-----|-----|" << endl;
    }
    for (int c = 0; c < 8; c++) {
      if (c % 3 == 0) {
        cout << "|" << puzzle[r][c] << ' ';
      } else if (c == 2 || c == 5) {
        cout << puzzle[r][c];
      } else {
        cout << puzzle[r][c] << ' ';
      }
    }
    cout << puzzle[r][8] << '|' << endl;
  }
  cout << "|-----|-----|-----|" << endl;
}

int main() {
  vector<vector<char>> puzzle = {
      {'3', ' ', '6', '5', ' ', '8', '4', ' ', ' '},
      {'5', '2', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', '7', ' ', ' ', ' ', ' ', '3', '1'},

      {' ', ' ', '3', ' ', '1', ' ', ' ', '8', ' '},
      {'9', ' ', ' ', '8', '6', '3', ' ', ' ', '5'},
      {' ', '5', ' ', ' ', '9', ' ', '6', ' ', ' '},

      {'1', '3', ' ', ' ', ' ', ' ', '2', '5', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', '7', '4'},
      {' ', ' ', '5', '2', ' ', '6', '3', ' ', ' '},
  };

  printPuzzle(puzzle);
  cout << "Solving..." << endl;
  if (sudokuSolver(puzzle, 0, 0)) {
    cout << "Found solution!" << endl;
    printPuzzle(puzzle);
  } else {
    cout << "No solution found. :/" << endl;
  }
  return 0;
}