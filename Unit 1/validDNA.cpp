#include "util.h"
#include <string>
#include <vector>

int findValidPairs(string seq1, string seq2);

int main() {
  string seq1 = readLine("Please enter the first sequence: ");
  string seq2 = readLine("Please enter the second sequence: ");
  cout << "Valid pairs: " << findValidPairs(seq1, seq2) << endl;
}

int findValidPairs(string seq1, string seq2) {
  if(seq1.size() == 0 || seq2.size() == 0){
    return 0;
  }
  switch (seq1[0]) {
  case 'A':
    if (seq2[0] == 'T')
      return 1 + findValidPairs(seq1.substr(1), seq2.substr(1));
    else
      return findValidPairs(seq1.substr(1), seq2.substr(1));
    break;
  case 'C':
    if (seq2[0] == 'G')
      return 1 + findValidPairs(seq1.substr(1), seq2.substr(1));
    else
      return findValidPairs(seq1.substr(1), seq2.substr(1));
    break;
  case 'T':
    if (seq2[0] == 'A')
      return 1 + findValidPairs(seq1.substr(1), seq2.substr(1));
    else
      return findValidPairs(seq1.substr(1), seq2.substr(1));
    break;
  case 'G':
    if (seq2[0] == 'C')
      return 1 + findValidPairs(seq1.substr(1), seq2.substr(1));
    else
      return findValidPairs(seq1.substr(1), seq2.substr(1));
    break;
  default:
    return findValidPairs(seq1.substr(1), seq2.substr(1));
  }
}