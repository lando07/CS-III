#include <iostream>

using namespace std;

int main() {
  int orig1, orig2;
  cout << "Please enter two digits seperated by a space: ";
  // Notice how we can read two values in one line
  cin >> orig1 >> orig2;
  int tmp1 = orig1, tmp2 = orig2;
  int steps = 0;
  cout << tmp1 << ' ' << tmp2 << ' ';
  do {
    int tmp3 = tmp1 + tmp2;
    tmp3 %= 10;
    cout << tmp3 << ' ';
    tmp1 = tmp2;
    tmp2 = tmp3;
    steps++;
  } while (tmp1 != orig1 || tmp2 != orig2);
  cout << '\n' << "Total Steps: " << steps << endl;

  return 0;
}