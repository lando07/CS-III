#include "util.h"
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
  // Enter your code here
  stack<int> operands;
  while (true) {
    string ans = readLine("> ");
    if (ans == "exit") {
      return 0;
    }
    try {
      int num = stoi(ans);
      operands.push(num);
    } catch (invalid_argument) {
      char c = ans[0];
      if (operands.size() >= 2) {
        int second = operands.top();
        operands.pop();
        int first = operands.top();
        operands.pop();
        switch (c) {
        case '+':
          cout << first + second << endl;
          operands.push(first + second);
          break;
        case '-':
          cout << first - second << endl;
          operands.push(first - second);
          break;
        case '/':
          cout << first / second << endl;
          operands.push(first / second);
          break;
        case '*':
          cout << first * second << endl;
          operands.push(first * second);
          break;
        }
      } else {
        cout << "Error - Not enough numbers in stack" << endl;
      }
    }
  }
  return 0;
}