#include "util.h"
#include <iostream>
#include <queue>
#include <vector>
// modify this
struct printTask {
  int numPages;
  int arrivalTimeStamp;
  int timeRemainingSec;
};

struct printer {
  const int PAGES_PER_MINUTE = 10;
  bool working = false;
  int secRemaining = 3600;
  printTask currTask;
};

vector<int> waitingTimes;
queue<printTask> printQueue;
printer prtr;

int main() {
  cout << "Printer with " << prtr.PAGES_PER_MINUTE << "per minute."
       << "\n-------------------------" << endl;
  int currSecond = 0;
  while (!printQueue.empty() || prtr.secRemaining != 0) {
    if (randInt(0, 180) == 180 &&
        prtr.secRemaining > 0) { // if print job is created
      printTask p;
      p.numPages = randInt(1, 20);
      p.arrivalTimeStamp = currSecond;
      p.timeRemainingSec = p.numPages * 60 / prtr.PAGES_PER_MINUTE;
      cout << "Printer job recieved with " << p.numPages
           << " pages.\tJobs in queue: " << printQueue.size() << endl;
      printQueue.push(p); // haha pushin p
    }
    if (printQueue.empty()) {
      prtr.secRemaining--;
      continue;
    }
    if (!prtr.working) {
      cout << "Printer getting job.\tTimestamp: " << currSecond
           << "\tWait time: " << currSecond - prtr.currTask.arrivalTimeStamp
           << endl;
      prtr.currTask = printQueue.front();
      printQueue.pop();
      prtr.working = true;
      waitingTimes.push_back(currSecond - prtr.currTask.arrivalTimeStamp);
    } else {
      prtr.currTask.timeRemainingSec--;
      if (prtr.currTask.timeRemainingSec == 0) {
        prtr.working = false;
      }
    }
    prtr.secRemaining--;
    currSecond++;
  }
  
}
