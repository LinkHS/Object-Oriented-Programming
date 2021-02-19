// Goal: Learn how to declare and define a template function
// Sara Krehbiel, 2/1/21 (M Week 5, file 2/2)

#include <iostream>
using namespace std;

// a class that stores a fraction as an integer numerator and denominator
class Rational {
public:
  Rational(int num, int denom) : n(num), d(denom) {}
  Rational() : Rational(0,1) {}

  double getVal() const { return 1.0*n/d; }
  bool operator <(const Rational& rhs) const { return (getVal()<rhs.getVal()); }

  string toString() const { return to_string(n)+"/"+to_string(d); }
private:
  const int n;
  const int d;
};

ostream& operator <<(ostream& o, const Rational& r) { return o<<r.toString(); }

// a function that returns a ref to the larger of the two Rational parameters
const Rational& biggerRational(const Rational& a, const Rational& b) {
  if (a<b) return b;
  return a;
}
// another function that is the same except for types
// note: works the same with int in place of const int&
const int& biggerInt(const int& a, const int& b) {
  if (a<b) return b;
  return a;
}

// a templatized function that replaces the need for the two above functions
template <typename T> // declares T as a typename for the signature+body of fn
const T& bigger(const T& a, const T& b) {
  if (a<b) return b; // imposes requirement for T
  return a;
}

// templatized function can declare two typenames
template <typename T, typename U>
bool isBigger(const T& a, const U& b) {
  if (a<b) return false; // imposes requirement for T, U
  return true;
}// ^ compiles but should only be called when a<b is defined for T a and U b

int main() {
  Rational r(1,3), s(1,4);
  cout << "Which burger should I get?\n";
  Rational betterDeal = bigger(r,s);
  cout << "Get the " << betterDeal << "-pounder\n";
  cout << "Weird because " << bigger(3,4) << " is a bigger denominator...\n";

  bool rIsBigger = isBigger(r,s); // Note: this DOESN'T work with isBigger(r,1)
  cout << r << (rIsBigger?" > ":" <= ") << s << endl;
  return 0;
}
