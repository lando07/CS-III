#include "util.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

struct movie {
  string title;
  int yearMade;
  vector<string> actors;
  double rating;

  bool operator<(movie const &m) const { return title < m.title; }
};

void addMovie(set<movie> &db);
void listMovies(set<movie> &db);
void getMoviesFromFile(string filename, set<movie> &db);
void searchMovies(set<movie> &db);
void searchByActor(set<movie> &db);
void searchByRating(set<movie> &db);
void searchByTitle(set<movie> &db);
void searchByYear(set<movie> &db);
string movieToStr(movie m);

int main() {
  set<movie> db;
  getMoviesFromFile("movies.txt", db);
  bool addingMovies = true;
  while (addingMovies) {
    char ans =
        readLine("Would you like to (s)earch, (l)ist movies, or (e)xit? ")[0];
    switch (ans) {
    case 's':
      searchMovies(db);
    case 'l':
      listMovies(db);
      break;
    case 'e':
      addingMovies = false;
    default:
      continue;
    }
  }
  return 0;
}

void searchMovies(set<movie> &db) {
  cout << "Search menu:"
       << "\n1. Search by Title"
       << "\n2. Search by Year"
       << "\n3. Search by Actor"
       << "\n4. Search by Rating" << endl;
  int ans = readInt(
      1, 4, "Enter option: ", "Please enter a number between 1 and 4: ");
  switch (ans) {
  case 1:
    searchByTitle(db);
    break;
  case 2:
    searchByYear(db);
    break;
  case 3:
    searchByActor(db);
    break;
  case 4:
    searchByRating(db);
    break;
  }
}

void searchByTitle(set<movie> &db) {
  string ans = readLine("Please enter a title to search for: ");
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.title.find(ans) != string::npos) {
      found = true;
      cout << movieToStr(tmpMovie);
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}

string movieToStr(movie m) {
  string ret;
  ret += "Title: " + m.title + "\n";
  ret += "Year: " + to_string(m.yearMade) + "\n";
  ret += "Actor: ";
  for (string actor : m.actors) {
    ret += actor + "; ";
  }
  ret = ret.substr(0, ret.length() - 2) +
        "\n"; // removes the last semicolon and space
  ret += "Rating: " + to_string(m.rating).substr(0,3) + "\n";
  return ret;
}

void searchByYear(set<movie> &db) {
  int ans = readInt("Please enter a year to search for: ",
                    "Please enter a valid number: ");
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.yearMade == ans) {
      found = true;
      cout << movieToStr(tmpMovie);
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}

void searchByActor(set<movie> &db) {
  string ans = readLine("Please enter an actor to search for(first name or "
                        "last name ONLY, **CASE SENSITIVE**): ");
  bool found = false;
  for (movie tmpMovie : db) {
    for (string actor : tmpMovie.actors) {
      if (actor.find(ans) != string::npos) {
        found = true;
        movieToStr(tmpMovie);
      }
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}

void searchByRating(set<movie> &db) {
  double ans = readDouble(1, 10, "Please enter a rating to search for:",
                          "Not a valid number, try again: ");
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.rating == ans) {
      found = true;
      movieToStr(tmpMovie);
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}

void getMoviesFromFile(string filename, set<movie> &db) {
  ifstream file;
  file.open(filename);
  if(file.fail()){
    cerr << "File not found. Program will exit." << endl;
  }
  while (true) {
    string line;
    getline(file, line);
    if (file.fail()) {
      break;
    }
    vector<string> data = splitLine(line, ';');
    movie tmp;
    tmp.title = data[0];
    tmp.yearMade = stoi(data[1]);
    tmp.actors.push_back(data[2]);
    tmp.rating = stod(data[3]);
    pair<set<movie>::iterator, bool> result = db.insert(tmp);
    if (!result.second) {
      movie mv = *result.first;
      mv.actors.push_back(data[2]);
      db.erase(result.first);
      db.insert(mv);
    }
  }
}

void listMovies(set<movie> &db){
  for(movie m : db){
    cout << movieToStr(m) << endl;
  }
}