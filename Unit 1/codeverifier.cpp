#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int emp = 686;
  int com = 1248;
  int keypairs;
  int matches = 0;
  cout << "How many keypairs would you like to compare? ";
  cin >> keypairs;

  for (int i = 0; i < keypairs; i++) {
    emp *= 692;
    com *= 483;
    emp %= 308947;
    com %= 308947;

    string empBin = bitset<32>(emp).to_string();
    string comBin = bitset<32>(com).to_string();
    cout << empBin << '\n' << comBin << '\n';
    empBin = empBin.substr(empBin.length() - 12);
    comBin = comBin.substr(comBin.length() - 12);
    if (empBin == comBin) {
      cout << "Code matches!" << '\n' << '\n';
      matches++;
    }
    cout << endl;
  }
  cout << "Total matches: " << matches << endl;
  return 0;
}