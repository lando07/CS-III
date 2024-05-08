#include "util.h"

void printCombos(int numDigits, string soFar) {
  // Base Case
  if (numDigits == soFar.size() + 1) {
    cout << "0" + soFar << endl;
    cout << "1" + soFar << endl;
  } else {
    printCombos(numDigits, "0" + soFar);
    printCombos(numDigits, "1" + soFar);
  }
  // Recursive call
}

// Set up function to call the initial recursive function
void printBinary(int numDigits) { printCombos(numDigits, ""); }

int main() {
  int digits = readInt(1, 10, "Select the number of digits (1 to 10): ");
  printBinary(digits);

  return 0;
}
