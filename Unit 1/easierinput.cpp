#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string inputLine(string prompt);
double inputDouble(string prompt);
double inputDouble(string prompt, double min, double max);
int inputInt(string prompt);
int inputInt(string prompt, int min, int max);

int main() {
  // Enter your code here
  string ans = inputLine("Please enter a string: ");
  cout << "You entered: " << ans << endl;
  double ans3 = inputDouble("Please enter a double: ");
  cout << "You entered: " << ans3 << endl;
  double ans1 = inputDouble("Please enter a double between 0 and 1: ", 0, 1);
  cout << "You entered: " << ans1 << endl;
  int ans4 = inputInt("Please enter an int: ");
  cout << "You entered: " << ans4 << endl;
  int ans5 = inputInt("Please enter an int between 0 and 10: ", 0, 10);
  cout << "You entered: " << ans5;
  return 0;
}

string inputLine(string prompt) {
  cout << prompt;
  string ans;
  getline(cin, ans);
  return ans;
}

double inputDouble(string prompt) {
  cout << prompt;
  double ans;
  cin >> ans;
  return ans;
}

double inputDouble(string prompt, double min, double max) {
  cout << prompt;
  double ans;
  cin >> ans;
  while (ans < min || ans > max) {
    cout << prompt;
    cin >> ans;
  }
  return ans;
}
int inputInt(string prompt) {
  cout << prompt;
  int ans;
  cin >> ans;
  return ans;
}

int inputInt(string prompt, int min, int max) {
  cout << prompt;
  int ans;
  cin >> ans;
  while (ans < min || ans > max) {
    cout << prompt;
    cin >> ans;
  }
  return ans;
}