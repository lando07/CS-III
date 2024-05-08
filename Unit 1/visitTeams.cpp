#include "util.h"
#include <set>

void addTeam(set<int> &teams);
void listTeams(set<int> &teams);

int main() {
  set<int> teams;
  while (true) {
    int ans = readInt("Please select an option:\n1. Add a team\n2. List all "
                      "teams\n3. Exit\n>> ");
    switch (ans) {
    case 1:
      addTeam(teams);
      break;
    case 2:
      listTeams(teams);
      break;
    case 3:
      return 0;
    }
  }
}

void addTeam(set<int> &teams) {
  int teamNum = readInt("Enter a team number: ");
  teams.insert(teamNum);
  cout << "Added team " << teamNum << endl;
}
void listTeams(set<int> &teams) {
    cout << "Teams visited:" << endl;
  for (int i : teams) {
    cout << i << endl;
  }
}