#include "util.h"
#include <fstream>
#include <stack>
#include <string>

void checkLine(char c, int lineNum);

int main() {
  ifstream in;
  in.open(readLine("Please enter a file to check: "));
  stack<char> symbols;
  int lineNum = 0;
  while (true) {
    string line;
    getline(in,line);
    if (in.fail())
      break;
    lineNum++;
    try {
      for (char c : line) {
        switch (c) {
        case '(':
        case '{':
        case '[':
          symbols.push(c);
          break;
        case ')':
          if ('(' != symbols.top()) {
            throw c;
          } else {
            symbols.pop();
          }
          break;
        case ']':
          if ('[' != symbols.top()) {
            throw c;
          } else {
            symbols.pop();
          }
          break;
        case '}':
          if ('{' != symbols.top()) {
            throw c;
          } else {
            symbols.pop();
          }
          break;
        }
      }
    } catch (char c) {
      switch (symbols.top()) {
      case '(':
        Error("line " + to_string(lineNum) + " expecting ) but got " + c);
        break;
      case '{':
        Error("line " + to_string(lineNum) + " expecting } but got " + c);
        break;
      case '[':
        Error("line " + to_string(lineNum) + " expecting ] but got " + c);
        break;
      }
    }
  }
}