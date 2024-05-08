#include "util.h"
#include <map>

struct stonk {
  string name;
  double price;
};

stonk *addStock(string name, double price) { return new stonk{name, price}; }

int main() {
  // Enter your code here
  map<stonk *, int> karel;
  map<stonk *, int> tracy;
  stonk *tsla = addStock("Tesla", 700.32);
  stonk *rblx = addStock("Roblox", 76.45);
  stonk *aapl = addStock("Apple", 125.94);
  karel[tsla] = 5;
  karel[rblx] = 3;
  tracy[tsla] = 3;
  tracy[aapl] = 8;
  cout << "**Karel's Portfolio**\nTesla: $" << karel[tsla] * tsla->price
       << "\nRoblox: $" << karel[rblx] * rblx->price << "\nTotal Value: $"
       << karel[tsla] * tsla->price + karel[rblx] * rblx->price << endl << endl;

  cout << "**Tracy's Portfolio**\nTesla: $" << tracy[tsla] * tsla->price
       << "\nApple: $" << karel[aapl] * aapl->price << "\nTotal Value: $"
       << tracy[tsla] * tsla->price + tracy[aapl] * aapl->price << endl << endl;

  cout << "\nUpdating Tesla...";
  tsla->price = 100.32;
  cout << "**Karel's Portfolio**\nTesla: $" << karel[tsla] * tsla->price
       << "\nRoblox: $" << karel[rblx] * rblx->price << "\nTotal Value: $"
       << karel[tsla] * tsla->price + karel[rblx] * rblx->price << endl << endl;

  cout << "**Tracy's Portfolio**\nTesla: $" << tracy[tsla] * tsla->price
       << "\nApple: $" << karel[aapl] * aapl->price << "\nTotal Value: $"
       << tracy[tsla] * tsla->price + tracy[aapl] * aapl->price << endl;

  return 0;
}
