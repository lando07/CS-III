#include "util.h"
#include <vector>

void printNums(vector<int> &chosen) {
  for (int num : chosen) {
    cout << num << " "; // base case
  }
  cout << endl;
}

void diceSumHelper(int dice, int desiredSum, vector<int> &chosen) {
  if(chosen.size() > dice){
    return;
  }
  int sum = 0;
  for(int i : chosen){
    sum += i;
  }
  if(sum == desiredSum){
    printNums(chosen);
    return;
  }
  for(int i = 1; i <= 6; i++){
    chosen.push_back(i);
    diceSumHelper(dice, desiredSum, chosen);
    chosen.pop_back();

  }
}

void diceSum(int dice, int desiredSum) {
  vector<int> chosen;
  diceSumHelper(dice, desiredSum, chosen);
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