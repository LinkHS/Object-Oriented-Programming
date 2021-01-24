// Goal: Learn how to declare and use memory on the heap.
// Sara Krehbiel, 1/22/21 (F Week 3, file 1/1)

#include <iostream>

using namespace std;

void recap();
void sumAndIncrementArray(double& , double [], int);
double* incrementedArray(double* arr, int size);
double doubleDoubleOnStack(double d);
double* doubleDoubleOnHeap(double d);

int main() {
  // On Wed, we saw how to declare a pointer and use the & and * operators

  recap();

  // You'd already been using pointers with arrays and pass-by-reference...

  double total = 0, arr[3] = {1.5,3,4}; // slightly confusing, but okay
  sumAndIncrementArray(total, arr, 3);
  cout << "total = " << total << "\narray = "; // cout function return value
  for (double elem : arr) cout << elem << ", "; // & array w/ range-based loop
  cout << endl;

  // and now you can use pointers to return arrays!

  double *p = incrementedArray(arr,3);
  cout << "p = ";
  for (int i=0; i<3; i++) cout << *(p+i) << ", ";
  cout << endl;

  // You can also declare non-arrays on the heap.

  double value = 5;
  double twice = doubleDoubleOnStack(value);
  p = doubleDoubleOnHeap(twice); // Warning: orphaned memory!
  cout << "doubling: " << value << ", " << twice << ", " << *p << endl;
  return 0;
}

// illustrate some basic uses of new pointer syntax
void recap() {
  int a = 42; // declare and initialize an int
  int *p; // declare an int pointer
  p = &a; // assign an int pointer the address of an int
  cout << *p << endl; // dereference a pointer to access the value it points to
  *p = 5; // dereference a pointer on the lhs of an assignment statement
          // to change the value it points to
}

// increment each value in the array AFTER adding initial value to running total
// using pass-by-reference and array parameters
void sumAndIncrementArray(double& sum, double * a, int size) {
  double temp = 0;
  for (int i=0; i<size; i++) { // try using range-based for loop
    temp += a[i]++; // try replacing a[i] with *(a+i)

  }
  sum = temp;
}

// create and populate a new array on the heap and return a pointer to it
double* incrementedArray(double* arr, int size) {
  double *p = new double[size];
  for (int i=0; i<size; i++) {
    p[i]=arr[i]+1;
  }
  return p;
}

// a basic function without any references or pointers
double doubleDoubleOnStack(double d) {
  double temp = 2*d;
  return temp;
}

// a function that allocates memory and returns a pointer
double* doubleDoubleOnHeap(double d) {
  double *ptr = new double;
  *ptr = 2*d;
  return ptr;
}
