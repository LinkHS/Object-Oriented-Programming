// Driver program for CSCI 60 Homework 4; due Tuesday 2/2/21
//
// The littleDriverProgram partially tests the Parity member functions.
// Note that the class allows clients to insert 0, but this program doesn't
// because 0 is used as a sentinal value. Also note that the program assumes
// the user doesn't enter any ints and will throw an uncaught exception if
// the user provides the wrong input. (Test programs don't have to be robust!)
// See assignment HO for suggested use of this file as you implement Parity.

#include <iostream>
#include "parity.h"

using namespace std;

// void littleDriverProgram();

int main() {
  // littleDriverProgram();

  int a[10];

  int *p = new int[5];
  delete p;
  return 0;
}

// void littleDriverProgram() {
//   Parity lists;
//   cout << "Enter a list of ints, one per line, 0 to end:\n";
//   int val;
//   while (true) {
//     cin >> val;
//     if (val==0) break;
//     lists.insert(val);
//   }
//   lists.printAll();
//   cout << "The max value you entered is " << lists.max() << endl;
//   cout << "The min value you entered is " << lists.min() << endl;
//   cout << "The total of both lists is " << (lists.odd()?"odd\n":"even\n");
// }
