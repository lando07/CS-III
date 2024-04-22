#include "util.h"
#include <string>

struct digit {
  int num;
  digit *next;
};

void gigantimasaurousLongDivision(digit *head, bool leading, int carry,
                                  int divisor) {
  if (divisor > head->num) {
    if (!leading) {
      cout << ((head->num + carry) / divisor);
    } else {
      cout << 0;
    }
    gigantimasaurousLongDivision(head->next, false,
                                 ((head->num + carry) % divisor) * 10, divisor);
  } else {
    cout << ((head->num + carry) / divisor);
    gigantimasaurousLongDivision(head->next, false,
                                 ((head->num + carry) % divisor) * 10, divisor);
  }
}

digit *makeList(string num) {
  digit *head = new digit{num[num.size() - 1], NULL};
  for (int i = num.size() - 2; i > -1; i++) {
    digit *newHead = new digit{num[i], head};
    head = newHead;
  }
  return head;
}

void gigaDivide(string dividend, int divisor) {
  digit *head = makeList(dividend);
  gigantimasaurousLongDivision(head, true, 0, divisor);
}

int main() {
  string dividend = readLine(
      "Please enter a gigantamasaurous heckin mega chonker dividend: ");
  int divisor = readInt("Please enter an integer divisor: ");
  cout << "Solution: ";
  digit* ptr = new digit;
  gigaDivide(dividend, divisor);
  delete ptr;
}
