#include "util.h"

void printCombos(int numDigits, string soFar) {
  // Base Case

  // Recursive call
}

// Set up function to call the initial recursive function
void printBinary(int numDigits) { printCombos(numDigits, ""); }

int main() {
  int digits = readInt(1, 10, "Select the number of digits (1 to 10): ");
  printBinary(digits);

  return 0;
}
