#include "util.h"
#include <map>
#include <string>

struct car {
  string make;
  string model;
  string color;
  unsigned int year;
};

void registerCar(map<string, car> &db);
void search(map<string, car> &db);

int main() {
  map<string, car> db;
  while (true) {
    cout << "Please select an option:\n"
         << "1. Register Car\n"
         << "2. Search for a car\n"
         << "3. Exit\n";
    switch (readInt(">> ", ">> ")) {
    case 1:
      registerCar(db);
      break;
    case 2:
      search(db);
      break;
    case 3:
      return 0;
    }
  }
}

void registerCar(map<string, car> &db) {
  string lp = readLine("Enter the new license plate number: ");
  string make = readLine("Enter the make of the car: ");
  string model = readLine("Enter the model of the car: ");
  string color = readLine("Enter the color of the car: ");
  unsigned int year = readInt("Enter the year of the car (YYYY): ");
  if (db.find(lp) != db.end()) {
    cout << "A car with that license plate is already registered." << endl;
    return;
  }
  db[lp] = car{make, model, color, year};
}

void search(map<string, car> &db) {
  string lp = readLine("Enter the license plate to search for: ");
  map<string, car>::iterator itr = db.find(lp);
  if (itr != db.end()) {
    cout << "Year: " + to_string(itr->second.year) + '\n'
         << "Make: " + itr->second.make + '\n'
         << "Model: " + itr->second.model + '\n'
         << "Color: " + itr->second.color + '\n';
  } else {
    cout << "No car is registered with that plate number";
  }
}