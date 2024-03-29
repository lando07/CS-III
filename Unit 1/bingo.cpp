#include "util.h"
#include <iterator>
#include <set>
#include <string>
#include <vector>

struct player {
  string name;
  vector<set<int>> card;
};

void generateCard(player &p);
void printBlankCard(player &p);
void printMarkedCard(set<int> &numbers, player &p);
void playTurn(set<int> &numbers, vector<player> &players);
bool checkWinner(set<int> &numbers, player &p);
void autoPlay(set<int> &numbers, vector<player> &players);
int main() {

  vector<player> players;
  set<int> numsDrawn;
  while (true) {
    cout << "Would you like to:" << endl;
    cout << "1) Play one turn" << endl;
    cout << "2) Print player cards" << endl;
    cout << "3) Add a player" << endl;
    cout << "4) Auto play to win" << endl;
    cout << "5) Reset with same players" << endl;
    cout << "6) Exit" << endl;
    switch (readInt(1, 6, "> ", "Please enter a value between 1 and 6: ")) {
    case 1:
      playTurn(numsDrawn, players);
      break;
    case 2:
      for (player &p : players) {
        printBlankCard(p);
        cout << endl;
      }
      break;
    case 3: {
      player p;
      p.name = readLine("Please enter the player's name: ");
      generateCard(p);
      players.push_back(p);
    } break;
    case 4:
      autoPlay(numsDrawn, players);
      break;
    case 5:
      for (player &p : players) {
        generateCard(p);
      }
      break;
    case 6:
      cout << "Thanks for playing!" << endl;
      return 0;
    }
  }
}

void autoPlay(set<int> &numbers, vector<player> &players) {
  while (true) {
    playTurn(numbers, players);
    for (player &p : players) {
      if (checkWinner(numbers, p)) {
        cout << "We have a winner! " << p.name << " Won!" << endl;
        return;
      }
    }
  }
}

void generateCard(player &p) {
  p.card.clear();
  for (int c = 0; c < 5; c++) {
    set<int> col;
    while (col.size() < 5) {
      const int low = c * 15 + 1;
      const int high = (c + 1) * 15;
      col.insert(randInt(low, high));
    }
    p.card.push_back(col);
  }
}

void printBlankCard(player &p) {
  cout << "******* " << p.name << "'s *******" << endl;
  for (int r = 0; r < 5; r++) {
    for (set<int> col : p.card) {
      set<int>::iterator itr = col.begin();
      advance(itr, r);
      cout << *itr << '\t';
    }
    cout << endl;
  }
}

void printMarkedCard(set<int> &numbers, player &p) {
  cout << "******* " << p.name << "'s *******" << endl;
  for (int r = 0; r < 5; r++) {
    for (set<int> col : p.card) {
      set<int>::iterator itr = col.begin();
      advance(itr, r);
      if (numbers.find(*itr) != numbers.end()) { // aka the number in the column
                                                 // is inside our drawn nums
        cout << 'X' << '\t';
      } else {
        cout << *itr << '\t';
      }
    }
    cout << endl;
  }
}

void playTurn(set<int> &numbers, vector<player> &players) {
  if (players.size() == 0) {
    cout << "No players are registered, add players before playing a round"
         << endl;
    return;
  }
  int drawnNum = randInt(1, 75);
  while (!numbers.insert(drawnNum).second) {
    drawnNum = randInt(1, 75);
  }
  cout << "You pulled a " << drawnNum << endl;
  for (player &p : players) {
    printMarkedCard(numbers, p);
  }
}

bool checkDiagUpRight(set<int> &numbers, player p) {
  for (int r = 0; r < 5; r++) {
    set<int>::iterator itr = p.card[4 - r].begin();
    advance(itr, r);
    if (numbers.find(*itr) ==
        numbers.end()) { // if theres not a space for up/right diagonal
      return false;
    }
  }
  return true;
}

bool checkDiagDownRight(set<int> &numbers, player p) {
  for (int r = 0; r < 5; r++) {
    set<int>::iterator itr = p.card[r].begin();
    advance(itr, r);
    if (numbers.find(*itr) == numbers.end()) { // if theres not a blotted out
                                               // space for up/right diagonal
      return false;
    }
  }
  return true;
}

bool checkCols(set<int> &numbers, player p) {
  for (set<int> col : p.card) {
    int counter = 0;
    for (int i : col) {
      if (numbers.find(i) == numbers.end()) {
        break;
      }
      counter++;
    }
    if (counter == 5) {
      return true;
    }
  }
  return false;
}

bool checkRows(set<int> &numbers, player p) {
  for (int r = 0; r < 5; r++) {
    int counter = 0;
    for (set<int> col : p.card) {
      set<int>::iterator itr = col.begin();
      advance(itr, r);
      if (numbers.find(*itr) == numbers.end()) {
        break;
      }
      counter++;
    }
    if (counter == 5) {
      return true;
    }
  }
  return false;
}

bool checkWinner(set<int> &numbers, player &p) {
  return checkCols(numbers, p) || checkRows(numbers, p) ||
         checkDiagDownRight(numbers, p) || checkDiagUpRight(numbers, p);
}