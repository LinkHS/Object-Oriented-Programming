// Goal: Understand how to use & and * to get and store memory addresses.
// Sara Krehbiel, 1/24/21 (W Week 3, file 1/2)

#include <iostream>

using namespace std;

int main() {
  // ACCESSING THE ADDRESS OF YOUR VARIABLES:
  // & gets the address of a variable

  int a = 2;
  double b = 3.5;
  int c = 4;

  cout << "\nSnapshot 1\n\n";

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

  cout << "&a: " << &a << endl;
  cout << "&b: " << &b << endl;
  cout << "&c: " << &c << endl;

  // DECLARING POINTER VARIABLES:
  // * modifies type when declaring variables; int *p holds an address of an int

  int *aptr = &a;
  double *bptr = &b;
  int *cptr = &c;

  //int* intptr1 = &a, intptr2 = &c; // ERROR: the * type modifier binds to the identifier when declaring multiple vars
  //int* intptr1 = &a, *intptr2 = &c, d = 7; // Allowed (but confusing): can declare int ptrs and ints on the same line

  cout << "\nSnapshot 2\n\n";

  cout << "aptr: " << aptr << endl;
  cout << "bptr: " << bptr << endl;
  cout << "cptr: " << cptr << endl;

  cout << "&aptr: " << &aptr << endl;
  cout << "&bptr: " << &bptr << endl;
  cout << "&cptr: " << &cptr << endl;

  // DEREFERENCING POINTERS:
  // * gets the value of a pointer variable that has already been declared

  cout << "*aptr: " << *aptr << endl;
  cout << "*bptr: " << *bptr << endl;
  cout << "*cptr: " << *cptr << endl;

  // USING ADDRESS AND DEREFERENCING OPERATORS IN ASSIGNMENT

  c = *aptr;
  c++;
  cptr = aptr;
  aptr = &c;

  //bptr = &c; // ERROR: can't assign an address of an int to a double ptr
  //&c = aptr; // ERROR: can't move where the variable c lives

  cout << "\nSnapshot 3\n\n";

  // Note that the addresses of local variables never change
  cout << "&a: " << &a << endl;
  cout << "&b: " << &b << endl;
  cout << "&c: " << &c << endl;
  cout << "&aptr: " << &aptr << endl;
  cout << "&bptr: " << &bptr << endl;
  cout << "&cptr: " << &cptr << endl << endl;

  // But you can update values, including where pointers point
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "aptr: " << aptr << endl;
  cout << "bptr: " << bptr << endl;
  cout << "cptr: " << cptr << endl << endl;

  // And those value updates are reflected when you dereference pointers
  cout << "*aptr: " << *aptr << endl;
  cout << "*bptr: " << *bptr << endl;
  cout << "*cptr: " << *cptr << endl << endl;

  return 0;
}
