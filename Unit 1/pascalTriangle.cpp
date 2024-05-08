#include "util.h"
#include <vector>

/* This function will print your triangle. Call it
 * from your base case. It should not be altered.
 */

void printTriangle(vector<vector<int>> &t) {
  int size = t.size();
  if (size % 2 == 1) {
    size--;
  }
  for (int i = 0; i < t.size(); i++) {
    for (int j = 0; j < (size - i) / 2; j++) {
      cout << "\t";
    }
    for (int item : t[i]) {
      if (i % 2 == 1) {
        cout << "   ";
      }
      cout << item << "\t";
    }
    cout << endl;
  }
}

/* This will be your recursive function. */
void pascalRec(vector<vector<int>> &t, int remain) {
  if (remain == 0) {
    printTriangle(t);
    return;
  }
  vector<int> tmp;
  for (int i = 0; i < t[t.size() - 1].size() + 1; i++) {
    vector<int> &above = t[t.size() - 1];
    int firstNum = (i - 1) < 0 ? 0 : above[i - 1];
    int secondNum = (i > above.size() - 1) ? 0 : above[i];
    tmp.push_back(firstNum + secondNum);
  }
  t.push_back(tmp);
  remain--;
  pascalRec(t, remain);
}

/* This is your helper function. It is set up
 * to create the first row of the Pascal
 * triangle and then call the recursive function.
 * It should not be altered.
 */
void pascal(int levels) {
  vector<vector<int>> triangle{{1}};
  pascalRec(triangle, levels - 1);
}

int main() {
  int lines = readInt(1, 15, "Please enter the number of lines (1 to 15): ");
  pascal(lines);

  return 0;
}