// Goal: Understand how arrays are based on pointers.
// Sara Krehbiel, 1/24/21 (W Week 3, file 2/2)

#include <iostream>

using namespace std;

int main() {

  double a[3] = {1.5, 2.5, 3.5};

  cout << "a: " << a << endl;
  cout << "&a: " << &a << endl;

  double *p = a;
  cout << "p: " << p << endl;
  cout << "&p: " << &p << endl;

  double *last = a+2;
  cout << "last: " << last << endl;
  cout << "*last: " << *last << endl;

  cout << "Array contents printed with subscript operator:\n";
  for (int i=0; i<3; i++) {
    cout << a[i] << " ";
  }

  cout << "Array contents printed with pointer arithmetic:\n";
  for (int i=0; i<3; i++) {
    cout << *(a+i) << " ";
  }

}
