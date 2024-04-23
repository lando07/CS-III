#include "util.h"
// we emulatin a doubly linked list
struct song {
  string name;
  song *prev;
  song *next;
};

int main() {
  while (true) {
    int ans =
        readInt("Please select an option:\n1 - Print the previous song\n2 - "
                "Add a new song\n3 - Print the next song\n4 - Quit\n>>");
    switch (ans) {
    case 1:
    case 2:
    case 3:
    case 4:
      return 0;
    }
  }
}