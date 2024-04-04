#include "util.h"
#include <fstream>
#include <vector>

const int BEST_VALUE = 700;
const int MAX_WEIGHT = 50;

struct item {
  string name;
  int value, weight;
  bool included;
};

vector<item> readContents() {

  vector<item> output;
  ifstream in;
  in.open("contents.txt");
  if (in.fail())
    cout << "File didn't open" << endl;

  string line;
  while (true) {
    getline(in, line);
    if (in.fail())
      break; // will fail at end of file

    vector<string> split = splitLine(line);
    item newItem;
    newItem.name = split[0];
    newItem.value = stoi(split[1]);
    newItem.weight = stoi(split[2]);
    newItem.included = false;
    output.push_back(newItem);
  }
  return output;
}

void printItem(item i) {
  cout << i.name << endl;
  cout << "Value: " << i.value << endl;
  cout << "Weight: " << i.weight << endl;
  cout << endl;
}

// Enter your recursive function here

// Use this function to kick off your recursive call
void airFreight(vector<item> &items) {
  // Call your recursive function from here
}

int main() {

  vector<item> items = readContents();

  // Call your recursive function

  // Print out the results
  return 0;
}
