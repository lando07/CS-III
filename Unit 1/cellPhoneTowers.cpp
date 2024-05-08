#include "util.h"
#include <cmath> // used for the sqrt function
#include <map>
#include <vector>

// Cell tower struct
struct cellTower {
  int x, y;
};

const int GRID_SIZE = 10;
const double FREQ_DISTANCE = 5.6;
const double TOWER_DISTANCE = 2.1;
//  The FREQ vector  may have more frequencies than needed
const vector<char> FREQ{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// Helper function to print grid
void printGrid(vector<vector<char>> &grid) {
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      cout << grid[row][col] << ' ';
    }
    cout << endl;
  }
}

// Helper function to determine the distance between points.
// x and y should represent the grid coordinates.
double distance(int x1, int y1, int x2, int y2) {
  int a = x2 - x1;
  int b = y2 - y1;
  return sqrt(a * a + b * b);
}
// Helper function to determine if a tower is needed
// Returns true if distance of point is less than TOWER_DISTANCE
bool towerNeeded(vector<vector<char>> &grid, int testRow, int testCol) {
  // Enter your code here
  for (int r = 0; r < GRID_SIZE; r++) {
    for (int c = 0; c < GRID_SIZE; c++) {
      if (grid[r][c] != '.' &&
          distance(c, r, testCol, testRow) < TOWER_DISTANCE) {
        return false;
      }
    }
  }
  return true;
}

// Helper function to find the next valid frequency
// Returns the next frequency to use
char validFreq(vector<vector<char>> &grid, int testRow, int testCol,
               int numFreq) {
  // Enter your code here
  for (int i = 0; i < numFreq; i++) {
    char currFreq = FREQ[i];
    bool valid = true;
    for (int r = 0; r < GRID_SIZE; r++) {
      for (int c = 0; c < GRID_SIZE; c++) {
        if (grid[r][c] == currFreq &&
            distance(c, r, testCol, testRow) < FREQ_DISTANCE) {
          if (grid[r][c] == currFreq) {
            valid = false;
          }
        }
      }
      if (!valid)
        break;
    }
    if (!valid) {
      continue;
    }
    return currFreq;
  }
  return ' ';
}

// Solver recursive function.
bool cellSolver(vector<vector<char>> &grid, int row, int col, int numFreq) {
  // Enter your code here
  if (col == GRID_SIZE) {
    row++;
    col = 0;
  }
  if (row == GRID_SIZE) {
    return true;
  }

  if (!towerNeeded(grid, row, col)) {
    if (cellSolver(grid, row, col + 1, numFreq))
      return true;
  }

  char f = validFreq(grid, row, col, numFreq);

  if (f != ' ') {
    grid[row][col] = f;
    if (cellSolver(grid, row, col + 1, numFreq))
      return true;
    grid[row][col] = '.';
  }

  return false;
}

// Helper function to kick off problem
bool cellProblem(vector<vector<char>> &grid, int numFreq) {
  // Enter your code here
  return cellSolver(grid, 0, 0, numFreq);
}

int main() {
  // Create the empty grid of size GRID_SIZE.
  // Place a '.' in each square
  vector<vector<char>> grid;
  for (int r = 0; r < GRID_SIZE; r++) {
    vector<char> row;
    for (int c = 0; c < GRID_SIZE; c++) {
      row.push_back('.');
    }
    grid.push_back(row);
  }
  // Prompt the user for the number of frequecies
  int testFreqs =
      readInt(1, 10, "Please enter the number of frequences(1-10): ");
  if (cellProblem(grid, testFreqs)) {
    cout << "Solution Found!" << endl;
  } else {
    cout << "No solution found." << endl;
    return 0;
  }

  // Print the results
  printGrid(grid);

  return 0;
}