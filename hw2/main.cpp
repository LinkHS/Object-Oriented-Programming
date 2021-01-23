// Test program starter file for CSCI 60 Homework 2; due Sunday 1/17/21
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include "histogram.h"
#include <cassert>

#include <vector>
#include <algorithm> // std::sort

using namespace std;

void test_operator_add(void)
{
  cout << endl
       << "testing operator add" << endl;
  Histogram histogram1("./data.txt");
  Histogram histogram2("./data.txt");
  histogram1 += histogram2;

  assert(histogram1.size() == histogram2.size() * 2);
}

void test_operator_square_bracket(void)
{
  cout << endl
       << "testing operator square bracket" << endl;
  Histogram histogram("./data.txt");

  assert(histogram[0] == 0);
  assert(histogram[9] == 2);
}

void test_operator_ostream(void)
{
  Histogram histogram("./data.txt");
  cout << histogram;
}

void test_variance(void)
{
  Histogram histogram("./data.txt");
  histogram.variance();
}

int main()
{
  //test_operator_add();
  //test_operator_square_bracket();

  //test_operator_ostream();

  //test_variance();

  return 0;
}