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

int main() {
  map<string, city *> cities = loadGraph();
  findRoute(cities["San Fransisco"], cities["Miami"]);
  return 0;
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
