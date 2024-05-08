#include "util.h"
#include <string>

int recurSum(string numS);

int main() {
  string s = readLine("PLease enter an integer: ");
  cout << "Sum of Digits: " << recurSum(s) << endl;
}

int recurSum(string numS) {
  if (numS.length() == 1) {
    return stoi(numS);
  } else {
    return stoi(numS.substr(0, 1)) + recurSum(numS.substr(1, numS.length() - 1));
  }
}