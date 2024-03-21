#include "util.h"
#include <fstream>
#include <queue>
#include <set>
#include <string>
#include <vector>

struct match {
  vector<unsigned int> redTeam;
  vector<unsigned int> blueTeam;
};

struct team {
  unsigned int teamNum;
  unsigned int totalPoints;
  unsigned int matchesPlayed;

  double calcPointAvg() const { return (double)totalPoints / matchesPlayed; }

  bool operator<(team const &t) const {
    if (calcPointAvg() != t.calcPointAvg())
      return calcPointAvg() < t.calcPointAvg();
    else {
      return teamNum < t.teamNum;
    }
  }
};

void importMatches(queue<match> &matches);
void printRound(queue<match> &matches, int round);
void recordRound(queue<match> &matches, set<team> teams);

int main() {
  queue<match> matches;
  set<team> teams;
  importMatches(matches);
  int matchNum = 0;
  while (true) {
    matchNum++;
    int ans = readInt(
        1, 3,
        "Would you like to:\n1) Record a match\n2)Print Results\n3) Exit\n>> ",
        ">>");
    switch (ans) {
    case 1:
      printRound(matches, matchNum);
      recordRound(matches, teams);
      break;
    case 2:
      break;
    case 3:
      return 0;
    }
  }
}

void recordRound(queue<match> &matches, set<team> &teams) {
  unsigned int redPoints = readInt(0, 4, "Enter the Red Team's ranking points: ",
                          "Ranking points should be from 0 to 4: ");
  unsigned int bluePoints = readInt(0, 4, "Enter the Blue Team's ranking points: ",
                           "Ranking points should be from 0 to 4: ");
  for (int i = 0; i < 3; i++) {
    team t{matches.front().redTeam[i], redPoints, 1};
  }
}

void printRound(queue<match> &matches, int round) {
  cout << "*** Match " << round << " ***" << endl;
  cout << "Red Alliance:\t";
  for (unsigned int teamNum : matches.front().redTeam) {
    cout << teamNum << ' ';
  }
  cout << "Blue Alliance:\t";
  for (unsigned int teamNum : matches.front().blueTeam) {
    cout << teamNum << ' ';
  }
}

void importMatches(queue<match> &matches) {
  ifstream in;
  in.open("matches.txt");
  if (in.fail()) {
    Error("matches.txt not found.");
  }
  while (true) {
    string teams;
    getline(in, teams);
    if (in.fail()) {
      break;
    }
    vector<string> tmp = splitLine(teams);
    match m;
    for (int i = 0; i < 3; i++) {
      m.redTeam.push_back(stoi(tmp[i]));
      m.blueTeam.push_back(stoi(tmp[i + 3]));
    }
    matches.push(m);
  }
}