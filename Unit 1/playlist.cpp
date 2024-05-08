#include "util.h"
#include <cstddef>
// we emulatin a doubly linked list
struct song {
  string name;
  song *prev;
  song *next;
};

void addSong(song *&head, string songName) {
  if (head->name == "") {
    head->name = songName;
    return;
  }
  song *newSong = new song{songName, head, NULL};
  head->next = newSong;
  head = newSong;
}

void printPrev(song *&currSong) {
  if (currSong->name == "") {
    cout << "Your playlist is empty." << endl;
  } else if (currSong->prev == NULL) {
    cout << "No previous song has played" << endl;
  } else {
    cout << currSong->prev->name << endl;
    currSong = currSong->prev;
  }
}

void printNext(song *&currSong) {
  if (currSong->name == "") {
    cout << "Your playlist is empty." << endl;
  } else if (currSong->next == NULL) {
    cout << "No more songs are in the queue" << endl;
  } else {
    cout << currSong->next->name << endl;
    currSong = currSong->next;
  }
}
int main() {
  song *head = new song{"", NULL, NULL};
  song *currSong = head;
  while (true) {
    int ans =
        readInt("\nPlease select an option:\n1 - Print the previous song\n2 - "
                "Add a new song\n3 - Print the next song\n4 - Quit\n>>");
    switch (ans) {
    case 1:
      printPrev(currSong);
      break;
    case 2:
      addSong(head, readLine("What's the song name? >> "));
      break;
    case 3:
      printNext(currSong);
      break;
    case 4:
      return 0;
    }
    cout << "Current song: " << currSong->name << endl;
  }
}