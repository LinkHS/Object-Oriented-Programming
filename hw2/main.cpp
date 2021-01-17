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

void test_sort_vector(void)
{
  size_t counts[10] = {3, 2, 9, 10, 3, 1, 2, 9, 12, 8};

  vector<vector<size_t>> v_counts; // vector_counts
  for (size_t i = 0; i < 10; i++)
  {
    vector<size_t> v = {counts[i], i};
    v_counts.push_back(v);
  }

  sort(v_counts.begin(), v_counts.end());

  for (int i = 0; i < 10; i++)
    cout << v_counts[i][0] << " ";
  cout << endl;
  for (int i = 0; i < 10; i++)
    cout << v_counts[i][1] << " ";
}

int main()
{
  test_operator_add();
  test_operator_square_bracket();

  return 0;
}