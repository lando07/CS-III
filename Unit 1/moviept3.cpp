#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

void addMovie();
void listMovies();
vector<string> splitLn(string input, char delimeter = ' ');
void getMoviesFromFile(string filename);
void searchMovies();
void searchByActor();
void searchByRating();
void searchByTitle();
void searchByYear();

struct movie {
  string title;
  int yearMade;
  string actor;
  double rating;
};

vector<movie> db;

int main() {
  // Enter Your Code Here
  getMoviesFromFile("movies.txt");
  bool addingMovies = true;
  while (addingMovies) {
    cout << "Would you like to (s)earch, (l)ist movies, or (e)xit? ";
    char ans;
    cin >> ans;
    cin.ignore();
    switch (ans) {
    case 's':
      searchMovies();
    case 'l':
      listMovies();
      break;
    case 'e':
      addingMovies = false;
    default:
      continue;
    }
  }
  return 0;
}

void searchMovies() {
  int ans;
  while (true) {
    cout << "Search menu:"
         << "\n1. Search by Title"
         << "\n2. Search by Year"
         << "\n3. Search by Actor"
         << "\n4. Search by Rating"
         << "\nEnter option: ";
    string line;
    try {
      getline(cin, line);
      ans = stoi(line);
      if (ans < 1 || ans > 4) {
        throw ans;
      }
    } catch (invalid_argument) {
      cout << "Not a valid number, please try again.";
    } catch (int ans) {
      cout << "Please enter a number between 1 and 4";
    }
  }
  switch (ans) {
  case 1:
    searchByTitle();
    break;
  case 2:
    searchByYear();
    break;
  case 3:
    searchByActor();
    break;
  case 4:
    searchByRating();
    break;
  }
}

void searchByTitle() {
  cout << "Please enter a title to search for: ";
  string line;
  getline(cin, line);
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.title == line) {
      found = true;
      cout << "Title " << tmpMovie.title << endl
           << "Year: " << tmpMovie.yearMade << endl
           << "Actor: " << tmpMovie.actor << endl
           << "Rating: " << tmpMovie.rating << endl
           << endl;
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}
void searchByYear() {
  int ans;
  while (true) {
    cout << "Please enter a year to search for: ";
    string line;
    try {
      ans = stoi(line);
      break;
    } catch (invalid_argument) {
      cout << "Not a valid number, try again" << endl;
    }
  }
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.yearMade == ans) {
      found = true;
      cout << "Title " << tmpMovie.title << endl
           << "Year: " << tmpMovie.yearMade << endl
           << "Actor: " << tmpMovie.actor << endl
           << "Rating: " << tmpMovie.rating << endl
           << endl;
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}
void searchByActor() {
  cout << "Please enter an actor to search for: ";
  string line;
  getline(cin, line);
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.actor == line) {
      found = true;
      cout << "Title " << tmpMovie.title << endl
           << "Year: " << tmpMovie.yearMade << endl
           << "Actor: " << tmpMovie.actor << endl
           << "Rating: " << tmpMovie.rating << endl
           << endl;
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}

void searchByRating() {
  double ans;
  while (true) {
    cout << "Please enter a rating to search for: ";
    string line;
    try {
      ans = stod(line);
      break;
    } catch (invalid_argument) {
      cout << "Not a valid number, try again" << endl;
    }
  }
  bool found = false;
  for (movie tmpMovie : db) {
    if (tmpMovie.yearMade == ans) {
      found = true;
      cout << "Title " << tmpMovie.title << endl
           << "Year: " << tmpMovie.yearMade << endl
           << "Actor: " << tmpMovie.actor << endl
           << "Rating: " << tmpMovie.rating << endl
           << endl;
    }
  }
  if (!found) {
    cout << "Not found." << endl;
  }
}

void getMoviesFromFile(string filename) {
  ifstream file;
  file.open(filename);
  while (true) {
    string line;
    getline(file, line);
    if (file.fail())
      break;
    vector<string> data = splitLn(line, ';');
    movie tmp;
    tmp.title = data[0];
    tmp.yearMade = stoi(data[1]);
    tmp.actor = data[2];
    tmp.rating = stod(data[3]);
    db.push_back(tmp);
  }
}

void listMovies() {
  for (movie tmpMovie : db) {
    cout << "Title " << tmpMovie.title << endl
         << "Year: " << tmpMovie.yearMade << endl
         << "Actor: " << tmpMovie.actor << endl
         << "Rating: " << tmpMovie.rating << endl
         << endl;
  }
}

vector<string> splitLn(string input,
                       char delimeter) { // pulled straight from 2.2.4

  vector<string> output;
  // This line turns a string into an input stream
  istringstream stream(input);
  string token;

  /* Now that the string is a stream, we can use
   * getline on it. This is the 3 parameter
   * version that can take only one item at a time,
   * split based on the delimeter. That item gets
   * added to a vector, then returned.
   */

  while (getline(stream, token, delimeter)) {
    // token holds the new value as we loop
    output.push_back(token);
  }
  return output;
}