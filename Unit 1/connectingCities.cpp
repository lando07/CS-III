#include "util.h"
#include <fstream>
#include <map>
#include <queue>
#include <vector>

struct city {
  string name;
  vector<city *> connections;
  bool visited;
  city *prev;
  int distance;
};

map<string, city *> loadGraph();

/* Similar to the previous example, this calculates
 * a path from the starting city to all other cities
 */
void shortestPath(city *start) {
  queue<city *> q;
  start->visited = true;
  start->distance = 0;
  start->prev = NULL;
  q.push(start);

  while (!q.empty()) {
    city *currNode = q.front();
    q.pop();
    vector<city *> currConn = currNode->connections;
    for (city *conn : currConn) {
      if (!conn->visited) {
        conn->visited = true;
        conn->distance = currNode->distance + 1;
        conn->prev = currNode;
        q.push(conn);
      }
    }
  }
}

/* This takes a ending point twice. The first
 * is used in the recursive call and the second
 * is used purely for formatting the output.
 */
void printPath(city *n, city *end) {
  if (n != NULL) {
    printPath(n->prev, end);
    if (n->name != end->name) {
      cout << n->name << " to " << endl;
    } else {
      cout << n->name << endl;
    }
  }
}

/* This function is used to kick off the recursive
 * print path method
 */
void findRoute(city *start, city *end) {
  shortestPath(start);
  cout << "Trip from " << start->name;
  cout << " to " << end->name << endl;
  printPath(end, end);
}

void calcRoute(map<string, city *> &cities) {
  string start;
  while (true) {
    start = readLine("Enter a starting city name ('list' to list all): ");
    if (start == "list") {
      for (pair<string, city *> p : cities) {
        cout << p.first << endl;
      }
      continue;
    } else if (cities.find(start) == cities.end()) {
      cout << "That city was not found" << endl;
    } else {
      break;
    }
  }
  string end;
  while (true) {
    end = readLine("Enter a ending city name ('list' to list all): ");
    if (end == "list") {
      for (pair<string, city *> p : cities) {
        cout << p.first << endl;
      }
    } else if (cities.find(end) == cities.end()) {
      cout << "That city was not found" << endl;
    } else {
      break;
    }
  }
  findRoute(cities[start], cities[end]);
}

void addCity(map<string, city *> &cities) {
  string ct = readLine("Please enter the new city name: ");
  cities[ct] = new city{ct, {}, false, NULL, 0};
  while (true) {
    cout << "Please enter a city " << ct << " is connected to." << endl;
    string conn = readLine("('list' to list all; 'exit' when finished): ");
    if (conn == "list") {
      for (pair<string, city *> p : cities) {
        cout << p.first << endl;
      }
    } else if (cities.find(conn) == cities.end()) {
      cout << "That city was not found" << endl;
    } else if (conn == "exit") {
      // cities[ct] = tmp;
      // cout << "exiting" << endl;

      cout << ct << endl;
      for (city *c : cities[ct]->connections) {
        cout << c->name << endl;
      }

      return;
    } else {

      cities[ct]->connections.push_back(cities[conn]);
      cities[conn]->connections.push_back(cities[ct]);
      // cout << (cities[ct]->connections).size();
      //  for (city *c : cities[ct]->connections) {
      //    cout << c->name << endl;
      //  }
    }
  }
}

int main() {
  map<string, city *> cities = loadGraph();
  while (true) {
    cout << "Please select an option: \n1 - Calculate route\n2 - Add City to "
            "the Graph\n3 - Exit\n ";
    int ans = readInt(1, 3, ">> ");
    switch (ans) {
    case 1:
      calcRoute(cities);
      break;
    case 2:
      addCity(cities);
      break;
    case 3:
      return 0;
    }
  }
}

/* This function loads cities from the text input
 * file and returns each city in a map with the
 * citie name as a key. The city connections are
 * stored in the struct.
 */
map<string, city *> loadGraph() {
  /* We will use these vectors as intermediate
   * steps as we read from the input file
   */
  vector<city *> cities;
  vector<vector<string>> allConn;

  map<string, city *> cityNodes;

  ifstream in;
  in.open("cities.txt");
  string line;

  while (true) {
    getline(in, line);
    if (in.fail())
      break;
    vector<string> input = splitLine(line, ':');
    string cityName = input[0];
    vector<string> cityConn = splitLine(input[1], ',');

    // Create the node and add to map
    city *newCity = new city;
    newCity->name = cityName;
    newCity->visited = false;
    cityNodes[cityName] = newCity;

    // Put city name and connections for next step
    cities.push_back(newCity);
    allConn.push_back(cityConn);
  }

  /* Iterate through all cities and add
   * cities connections into the nodes
   */

  // Loop through all cities
  for (int i = 0; i < cities.size(); i++) {
    // Loop through all city connection
    for (int j = 0; j < allConn[i].size(); j++) {
      cities[i]->connections.push_back(cityNodes[allConn[i][j]]);
    }
  }

  return cityNodes;
}
