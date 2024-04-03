#include "util.h"
#include <fstream>
#include <set>
#include <string>
#include <vector>

set<string> words;

vector<vector<char>> letters{{},
                             {},
                             {'A', 'B', 'C'},
                             {'D', 'E', 'F'},
                             {'G', 'H', 'I'},
                             {'J', 'K', 'L'},
                             {'M', 'N', 'O'},
                             {'P', 'Q', 'R', 'S'},
                             {'T', 'U', 'V'},
                             {'W', 'X', 'Y', 'Z'}};

void loadDict() {
  ifstream in;
  in.open("words.txt");
  string word;
  while (true) {
    getline(in, word);
    if (in.fail())
      break;
    words.insert(word);
  }
}

// depth first search
void searchPNumber(string number, string word) {
  if (number.size() == 0 || word.size() > 7) {
    if (words.find(word) != words.end()) {
      cout << word << endl;
    }
    return;
  }
  // cout << "Number parsed: " << number.substr(0, 1) << endl;
  // cout << "Word: " << word << endl;
  for (char c : letters[stoi(number.substr(0, 1))]) {
    string newWord = word + c;
    searchPNumber(number.substr(1), newWord);
  }
}

int main() {
  loadDict();
  string number = readLine("Please enter a phone number: ");
  searchPNumber(number, "");
  cout << "End of List" << endl;

  return 0;
}