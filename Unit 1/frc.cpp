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

int main() {
  queue<match> matches;
  set<team> teams;
  ifstream in;
  in.open("matches.txt");
  if(in.fail()){
    Error("matches.txt not found.");
  }
  int matchNum;
  while (true) {
    string teams; 
    getline(in,teams);
    vector<string> tmp = splitLine(teams);
    match m;
    for(int i = 0; i < 3; i++){
      m.redTeam.push_back(stoi(tmp[i]));
      m.blueTeam.push_back(stoi(tmp[i+3]));
    }
  }
}