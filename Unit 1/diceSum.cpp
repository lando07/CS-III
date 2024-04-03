#include "util.h"
#include <vector>

void printNums(vector<int> &chosen) {
  for (int num : chosen) {
    cout << num << " "; // base case
  }
  cout << endl;
}

void diceSumHelper(int dice, int sum, int desiredSum, vector<int> &chosen) {
  // Enter your code here
}

void diceSum(int dice, int desiredSum) {
  vector<int> chosen;
  diceSumHelper(dice, 0, desiredSum, chosen);
}

int main() {
  int dice = readInt(1, 10, "Select the number of dice to use (1 to 10): ");
  int maxNumber = dice * 6;
  int target = readInt(dice, dice * 6,
                       "Enter a target between " + to_string(dice) + " and " +
                           to_string(dice * 6) + ": ");
  diceSum(dice, target);

  return 0;
}