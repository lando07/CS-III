#include "util.h"
#include <cmath>
#include <fstream>
#include <map>
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
  unsigned int totalPoints = 0;
  unsigned int matchesPlayed = 0;

  double calcPointAvg() const { return (double)totalPoints / matchesPlayed; }

  bool operator<(team const &t) const {
    if (calcPointAvg() != t.calcPointAvg())
      return calcPointAvg() > t.calcPointAvg();
    else {
      return teamNum < t.teamNum;
    }
  }
};

void importMatches(queue<match> &matches);
void printRound(queue<match> &matches, int round);
void recordRound(queue<match> &matches, map<unsigned int, team> &teams);
void printStandings(map<unsigned int, team> &teams);

int main() {
  queue<match> matches;
  map<unsigned int, team> teams;
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
      printStandings(teams);
      break;
    case 3:
      return 0;
    }
  }
}

void printStandings(map<unsigned int, team> &teams) {
  set<team> sortedTeams;
  for (pair<unsigned int, team> t : teams) {
    sortedTeams.insert(t.second);
  }
  int i = 1;
  for (set<team>::iterator itr = sortedTeams.begin(); itr != sortedTeams.end(); itr++) {
    cout << i << ". " << itr->teamNum << ": "
         << (round(itr->calcPointAvg() * 10) / 10) << endl;
  }
}
void recordRound(queue<match> &matches, map<unsigned int, team> &teams) {
  unsigned int redPoints =
      readInt(0, 4, "Enter the Red Team's ranking points: ",
              "Ranking points should be from 0 to 4: ");
  unsigned int bluePoints =
      readInt(0, 4, "Enter the Blue Team's ranking points: ",
              "Ranking points should be from 0 to 4: ");
  for (int i = 0; i < 3; i++) { // BRO WHAT IS THIS CARNAGE 🤮🤮🤮
    teams[matches.front().redTeam[i]].matchesPlayed++;
    teams[matches.front().redTeam[i]].teamNum = matches.front().redTeam[i];
    teams[matches.front().redTeam[i]].totalPoints += redPoints;
    teams[matches.front().blueTeam[i]].matchesPlayed++;
    teams[matches.front().blueTeam[i]].teamNum = matches.front().blueTeam[i];
    teams[matches.front().blueTeam[i]].totalPoints += bluePoints;
  }
  matches.pop();
}

void printRound(queue<match> &matches, int round) {
  cout << "*** Match " << round << " ***" << endl;
  cout << "Red Alliance:\t";
  for (unsigned int teamNum : matches.front().redTeam) {
    cout << teamNum << ' ';
  }

  cout << "\nBlue Alliance:\t";
  for (unsigned int teamNum : matches.front().blueTeam) {
    cout << teamNum << ' ';
  }
  cout << endl;
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