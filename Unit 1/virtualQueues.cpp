// YOO THIS THE FINAL PROJ

/* This program will manage virtual queues for an
 * ammusement park. The user can add names, take names
 * from the queue, or print the queue out.
 */
#include "util.h"
#include <map>
#include <ostream>

struct virtualQueue;

struct guest {
  string name;
  virtualQueue *currentQueue = nullptr;
  guest *next = nullptr;
  guest *previous = nullptr;
};

struct virtualQueue {
  string ride;
  int length;
  guest *head = nullptr;
  guest *tail = nullptr;
};

/*
 * @param queue - queue to add the guest to
 * @newGuest - Guest to be added
 * This takes a queue and a guest and adds the guest to the queue
 *
 * It also updates the guest by attaching the queue to the guest record
 *
 * It does not check if a guest is already in another queue
 */
void addToQueue(virtualQueue &queue, guest *newGuest) {
  if (queue.length == 0) {
    queue.head = newGuest;
    queue.tail = newGuest;
    newGuest->next = nullptr;
    newGuest->previous = nullptr;
    newGuest->currentQueue = &queue;
  } else {
    newGuest->previous = queue.tail;
    queue.tail->next = newGuest;
    queue.tail = newGuest;
    newGuest->currentQueue = &queue;
  }
}

/*
 * @param - Non-empty queue to print

 * Prints out the current queue with a blank line at the end.
 */
void printQueue(virtualQueue &q) {
  cout << "Queue for " << q.ride << endl;
  guest *g = q.head;
  while (g != nullptr) {
    cout << g->name << endl;
  }
  cout << endl;
}

/*
 * @param virtualQueues - map to add rides to
 * This function is use to set up the program and adds a set of rides
 * to the queue. It uses pass by reference, so it does not need to return
 * a value. The rides can be added to or changed.
 */

void addRides(map<string, virtualQueue> &virtualQueues) {

  virtualQueue rise;
  rise.ride = "Rise of the Resistance";
  rise.length = 0;
  virtualQueues["RISE"] = rise;
  virtualQueue dwarf = {"Seven Dwarfs Mine Ride", 0};
  virtualQueues["SDMR"] = dwarf;
  // Add additional rides to the available rides
}

int main() {

  // Create virtual queue map and add rides with
  // the addRides function

  // Test your addToQueue function by adding
  // at least 3 guests one queue

  // Test your printQueue function

  return 0;
}
