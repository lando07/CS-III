#include "util.h"
#include <cstddef>
#include <string>

struct digit {
  int num;
  digit *next;
};

void gigantimasaurousLongDivision(digit *head, bool leading, int carry,
                                  int divisor) {
  if (head == NULL) {
    cout << endl;
  } else {
    int tmpDividend = carry + head->num;
    if (divisor > tmpDividend) {
      if (!leading) {
        cout << 0;
      }
      gigantimasaurousLongDivision(head->next, false, tmpDividend * 10,
                                   divisor);
    } else {
      cout << tmpDividend / divisor;
      gigantimasaurousLongDivision(head->next, false,
                                   (tmpDividend % divisor) * 10, divisor);
    }
  }
}

void printList(digit *head) {
  if (head == NULL) {
    cout << endl;
    return;
  }
  cout << head->num;
  printList(head->next);
}

digit *makeList(string num) {
  digit *head = new digit{num[num.size() - 1] - '0', NULL};
  for (int i = num.size() - 2; i > -1; i--) {
    digit *newHead = new digit{num[i] - '0', head};
    head = newHead;
    // cout << head->num << endl;
  }
  return head;
}

void gigaDivide(string dividend, int divisor) {
  digit *head = makeList(dividend);
  // printList(head);
  gigantimasaurousLongDivision(head, true, 0, divisor);
}

int main() {
  string dividend = readLine(
      "Please enter a gigantamasaurous heckin mega chonker dividend: ");
  int divisor = readInt("Please enter an integer divisor: ");
  cout << "Solution: ";
  gigaDivide(dividend, divisor);
}
