#include "util.h"
// we emulatin a doubly linked list
struct song {
  string name;
  song *prev;
  song *next;
};

void addSong(song *head, string songName) {}

void printPrev(song *head) {}

void printNext(song *head) {}
int main() {
  song *head = new song{"", NULL, NULL};
  song *tail = head;
  while (true) {
    int ans =
        readInt("Please select an option:\n1 - Print the previous song\n2 - "
                "Add a new song\n3 - Print the next song\n4 - Quit\n>>");
    switch (ans) {
    case 1:
      printPrev(head);
    case 2:
      addSong(head, readLine("What's the song name? >> "));
    case 3:
      printNext(head);
    case 4:
      return 0;
    }
  }
}