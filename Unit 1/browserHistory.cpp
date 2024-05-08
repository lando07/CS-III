#include <stack>
#include <string>
#include "util.h"

void goBack();
void goToNewSite();
void goForward();

stack<string> historyForward;
stack<string> historyBack;

int main() {
  // Enter your code here
  while (true) {
    int ans = readInt(1, 4,
                      "Would you like to:\n1 - Go to a new site\n2 - Go "
                      "Back\n3 - Go Forward\n4 - Exit\n>> ",
                      ">> ");
    switch (ans) {
    case 1:
      goToNewSite();
      break;
    case 2:
      goBack();
      break;
    case 3:
      goForward();
      break;
    case 4:
      return 0;
    }
    cout << "You are currently browsing " << historyBack.top() << endl << endl;
  }
  return 0;
}

void goToNewSite() {
  historyForward = stack<string>();
  string ans = readLine("Enter the new site to browse: ");
  historyBack.push(ans);
}

void goBack() {
  string site = historyBack.top();
  historyBack.pop();
  historyForward.push(site);
}

void goForward() {
  if (historyForward.empty()) {
    cout << "You cannot go forward." << endl;
  } else {
    string site = historyForward.top();
    historyForward.pop();
    historyBack.push(site);
  }
}