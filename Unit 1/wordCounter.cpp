#include "util.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>

int main() {
  string ans = readLine("Please enter the file name: ");
  ifstream in;
  in.open(ans);
  if (in.fail()) {
    Error("Bad file name or does not exist");
  }
  map<string, int> words;
  while (true) {
    string tmpLine;
    getline(in, tmpLine);
    vector<string> line = splitLine(tmpLine);
    for (string &str : line) {
      words[str]++;
    }
  }
  for(pair<string, bool> word: words){
    
  }
}