// Driver program that uses the Bag class to keep track of a several integers,
// possibly with repetition. Shows how to add to a bag, query size, and cout.
//
// Sara Krehbiel, 1/29/21 (F Week 4, file 1/3)

#include <iostream>
#include "bag.h"

using namespace std;

void dynamicBagTests();

int main() {
  dynamicBagTests();
  cout << "Goodbye!\n";
}

// construct a bag, report size before and after inserting some elements
void dynamicBagTests() {
  Bag b;
  cout << "Initial bag size: " << b.size() << endl;
  size_t n = 10;
  cout << "Adding " << n << " 1s to a capacity " << b.cap() << " bag\n";
  for (int i=0; i<n; i++) {
    b.insert(1);
  }
  cout << "Current bag (size = " << b.size() << ", cap = " << b.cap() << ") " << b << endl;

  // test erase_one
  cout << "Erasing 6 copies of 1\n";
  for (int i=0; i<6; i++) {
    b.erase_one(1);
  }
  cout << "Current bag (size = " << b.size() << ", cap = " << b.cap() << ") " << b << endl;

  // testing =
  Bag b2;
  b2 = b;
  // if you want to do this (not that you would) you must return *this from =
  b = b2 = b;
}
