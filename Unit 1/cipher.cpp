#include <iostream>

using namespace std;

void cipherEncrypt(string &phrase, int shift);
void cipherDecrypt(string &phrase, int shift);
int main() {
  // Enter your code here
  
    string message;
    char crypt;
    int shift = -1;
    cout << "Enter a phrase: ";
    getline(cin, message);
    for (char &chr : message) {
      chr = toupper(chr);
    }
    while (crypt != 'e' || crypt != 'd') {
      cout << "Would you like to (e)ncrypt or (d)ecrypt? ";
      cin >> crypt;
    }
    crypt = tolower(crypt);
    while (shift < 0 || shift > 26) {
      cout << "How much would you like to shift (1-26)? ";
      cin >> shift;
    }
    switch (crypt) {
    case 'd':
      cipherDecrypt(message, shift);
      break;
    case 'e':
      cipherEncrypt(message, shift);
    }

  return 0;
}

void cipherEncrypt(string &phrase, int shift) {

}

void cipherDecrypt(string &phrase, int shift) {
    
}