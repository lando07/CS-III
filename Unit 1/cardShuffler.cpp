#include "util.h"
#include <iterator>
#include <queue>
#include <string>
#include <utility>
#include <vector>

// Create a makeDeck function that takes
// no input and returns a vector of a
// string/char pairs.

// Create a shuffle function that takes
// a vector of string/char pairs and returns
// a queue of string/char pairs

vector<pair<string, char>> makeDeck();
queue<pair<string, char>> shuffle(vector<pair<string, char>>);

int main() {
  // Create the deck
  vector<pair<string, char>> deck = makeDeck();
  // Shuffle the deck
  queue<pair<string, char>> shuffledDeck = shuffle(deck);

  // Deal the first 10 cards
  for(int i = 0; i < 10; i++){
    cout << shuffledDeck.front().first << " - " << shuffledDeck.front().second << endl;
    shuffledDeck.pop();
  }

  return 0;
}

vector<pair<string, char>> makeDeck() {
  vector<pair<string, char>> deck;
  pair<string, char> card;
  for (int i = 2; i < 10; i++) {
    card = {to_string(i), 'D'};
    deck.push_back(card);
  }
  card = {"J", 'D'};
  deck.push_back(card);
  card = {"Q", 'D'};
  deck.push_back(card);
  card = {"K", 'D'};
  deck.push_back(card);
  card = {"A", 'D'};
  deck.push_back(card);
  for (int i = 2; i < 10; i++) {
    card = {to_string(i), 'C'};
    deck.push_back(card);
  }
  card = {"J", 'C'};
  deck.push_back(card);
  card = {"Q", 'C'};
  deck.push_back(card);
  card = {"K", 'C'};
  deck.push_back(card);
  card = {"A", 'C'};
  deck.push_back(card);
  for (int i = 2; i < 10; i++) {
    card = {to_string(i), 'H'};
    deck.push_back(card);
  }
  card = {"J", 'H'};
  deck.push_back(card);
  card = {"Q", 'H'};
  deck.push_back(card);
  card = {"K", 'H'};
  deck.push_back(card);
  card = {"A", 'H'};
  deck.push_back(card);
  for (int i = 2; i < 10; i++) {
    card = {to_string(i), 'S'};
    deck.push_back(card);
  }
  card = {"J", 'S'};
  deck.push_back(card);
  card = {"Q", 'S'};
  deck.push_back(card);
  card = {"K", 'S'};
  deck.push_back(card);
  card = {"A", 'S'};
  deck.push_back(card);
  return deck;
}

queue<pair<string, char>> shuffle(vector<pair<string, char>> deck) {
  queue<pair<string, char>> shuffled;
  while(!deck.empty()){
    shuffled.push(deck[randInt(0,deck.size() - 1)]);
    deck.pop_back();
  }
  return shuffled;
}