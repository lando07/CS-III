#include "util.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

struct person {
  string name;
  vector<person *> connections;
  bool visited;
  person *prev;
  int degreeOfSeparation;
};

map<string, person *> loadGraph();

void shortestPath(person *start) {
  queue<person *> q;
  start->visited = true;
  start->degreeOfSeparation = 0;
  start->prev = NULL;
  q.push(start);

  while (!q.empty()) {
    person *currPerson = q.front();
    q.pop();
    vector<person *> currConn = currPerson->connections;
    for (person *conn : currConn) {
      if (!conn->visited) {
        conn->visited = true;
        conn->degreeOfSeparation = currPerson->degreeOfSeparation + 1;
        conn->prev = currPerson;
        q.push(conn);
      }
    }
  }
}

void printPath(person *p, person *end) {
  if (p != NULL) {
    printPath(p->prev, end);
    if (p->name != end->name) {
      cout << p->name << " who knows" << endl;
    } else {
      cout << p->name << endl;
    }
  }
}

void findRoute(person *start, person *end, map<string, person *> net) {
  shortestPath(start);
  cout << start->name << " is " << end->degreeOfSeparation
       << " degrees of separation from " << end->name << endl;
  printPath(end, end);
}

void calcRoute(map<string, person *> &net) {
  string start;
  while (true) {
    start = readLine("Enter the starting person's name ('list' to list all): ");
    if (start == "list") {
      for (pair<string, person *> p : net) {
        cout << p.first << endl;
      }
      continue;
    } else if (net.find(start) == net.end()) {
      cout << "That person was not found" << endl;
    } else {
      break;
    }
  }
  string end;
  while (true) {
    end = readLine("Enter the ending person's name ('list' to list all): ");
    if (end == "list") {
      for (pair<string, person *> p : net) {
        cout << p.first << endl;
      }
    } else if (net.find(end) == net.end()) {
      cout << "That person was not found" << endl;
    } else {
      break;
    }
  }
  findRoute(net[start], net[end], net);
}

void addPerson(map<string, person *> &net) {
  string newP = readLine("Please enter the new person's name: ");
  net[newP] = new person{newP, {}, false, NULL, 0};
  while (true) {
    cout << "Please enter a person " << newP << " knows." << endl;
    string conn = readLine("('list' to list all; 'exit' when finished): ");
    if (conn == "list") {
      for (pair<string, person *> p : net) {
        cout << p.first << endl;
      }
    } else if (net.find(conn) == net.end()) {
      cout << "That person was not found" << endl;
    } else if (conn == "exit") {
      cout << newP << endl;
      for (person *p : net[newP]->connections) {
        cout << p->name << endl;
      }
      return;
    } else {
      net[newP]->connections.push_back(net[conn]);
      net[conn]->connections.push_back(net[newP]);
    }
  }
}

int main() {
  map<string, person *> net = loadGraph();
  while (true) {
    cout << "Please select an option: \n1 - Find person\n2 - Add person to "
            "the network\n3 - Exit\n ";
    int ans = readInt(1, 3, ">> ");
    switch (ans) {
    case 1:
      calcRoute(net);
      break;
    case 2:
      addPerson(net);
      break;
    case 3:
      return 0;
    }
  }
}

/* This function loads people from the text input
 * file and returns each person in a map with the
 * person's name as a key. The people's connections are
 * stored in the struct.
 */
map<string, person *> loadGraph() {
  /* We will use these vectors as intermediate
   * steps as we read from the input file
   */
  vector<person *> people;
  vector<vector<string>> allConn;

  map<string, person *> net;

  ifstream in;
  in.open("initial.txt");
  string line;

  while (true) {
    getline(in, line);
    if (in.fail())
      break;
    vector<string> input = splitLine(line, ':');
    string personName = input[0];
    vector<string> personConn = splitLine(input[1], ',');

    // Create the node and add to map
    person *newP = new person;
    newP->name = personName;
    newP->visited = false;
    net[personName] = newP;

    // Put city name and connections for next step
    people.push_back(newP);
    allConn.push_back(personConn);
  }

  /* Iterate through all cities and add
   * cities connections into the nodes
   */

  // Loop through all cities
  for (int i = 0; i < people.size(); i++) {
    // Loop through all city connection
    for (int j = 0; j < allConn[i].size(); j++) {
      people[i]->connections.push_back(net[allConn[i][j]]);
    }
  }

  return net;
}
