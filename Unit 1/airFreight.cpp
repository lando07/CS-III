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
bool findIncluded(vector<item> &items, int currWeight, int currValue) {
  if (currValue > BEST_VALUE) {
    return true;
  }

  for (int i = 0; i < items.size(); i++) {
    if (items[i].weight + currWeight <= MAX_WEIGHT && !items[i].included) {
      items[i].included = true;
      currWeight += items[i].weight;
      currValue += items[i].value;
      if (findIncluded(items, currWeight, currValue)) {
        return true;
      }
      items[i].included = false;
      currWeight -= items[i].weight;
      currValue -= items[i].value;
    }
  }
  return false;
}

// Use this function to kick off your recursive call
void airFreight(vector<item> &items) {
  // Call your recursive function from here
  findIncluded(items, 0, 0);
}

int main() {

  vector<item> items = readContents();

  // Call your recursive function
  airFreight(items);

  // Print out the results
  int totalWeight = 0;
  int totalValue = 0;
  for (item i : items) {
    if (i.included) {
      totalWeight += i.weight;
      totalValue += i.value;
      printItem(i);
    }
  }
  cout << "Total weight: " << totalWeight << endl;
  cout << "Total value: " << totalValue << endl;
  return 0;
}
