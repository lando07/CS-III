#include "util.h"

bool findSubSeq(string str, string seq);

int main() {
  string str = readLine("Please enter a string: ");
  string subSeq = readLine("Please enter a subsequence to search for: ");
  cout << (findSubSeq(str, subSeq) ? "Subsequence found!"
                                   : "Subsequence not found!")
       << endl;
}

bool findSubSeq(string str, string seq) {
  if (seq.size() == 0) {
    return true;
  } else if (str.find(seq[0]) == string::npos) {
    return false;
  } else {
    return findSubSeq(str.substr(str.find(seq[0]) + 1), seq.substr(1));
  }
}