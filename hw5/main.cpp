// Starter file for CSCI 60 Homework 5; due Tuesday 2/9/21
// List any collaborators and write your name here

#include <iostream>
#include "rational.h"
#include <vector>
using namespace std;

template <typename T>
// Part 1: overload << for vector
ostream &operator<<(ostream &o, vector<T> r)
{
  for (int i = 0; i < r.size(); i++)
  {
    o << r[i] << ", ";
  }
  return o;
}

// Part 2: design and implement the HetPair class
template <typename T, typename U>
class HetPair
{
public:
  HetPair(T tempx, U tempy)
  {
    x = tempx;
    y = tempy;
  }

  HetPair()
  {
    x = T();
    y = U();
  }

  const T getX()
  {
    return x;
  }
  const U getY()
  {
    return y;
  }
  HetPair operator+(const HetPair &rhs) const
  {
    HetPair sum;
    sum.x = this->x + rhs.x;
    sum.y = this->y + rhs.y;
    return sum;
  }
  friend ostream &operator<<(ostream &o, const HetPair<T, U> r)
  {
    o << "(" << r.x << ", " << r.y << ")";
    return o;
  }

private:
  T x;
  U y;
};

// Part 3: write test code
int main()
{
  vector<int> intVec;
  intVec.push_back(2);
  intVec.push_back(4);
  intVec.push_back(4);
  intVec.push_back(-1);
  cout << intVec << endl;
  
  vector<Rational> ratVec;
  ratVec.push_back(Rational(3, 11));
  ratVec.push_back(Rational(-1, 2));
  ratVec.push_back(Rational(2, 1));
  cout << ratVec << endl;

  HetPair<int, double> HetPairA(1, 0.6);
  HetPair<int, double> HetPairB(4, 0.8);
  HetPair<int, double> HetPairC;
  HetPairC = HetPairA + HetPairB;
  cout << HetPairC << endl;

  int numerator;
  int denominator;
  vector< HetPair<string, double> > output;

  while (true)
  {
    cout << "Enter numerator and denominator (0 denom to quit): ";
    cin >> numerator;
    cin >> denominator;
    Rational result(numerator, denominator);

    output.push_back( HetPair<string, double>(result.toString(), result.getVal()));
    if (denominator == 0)
    {
      break;
    }
    return 0;
  }
  cout << output;
}