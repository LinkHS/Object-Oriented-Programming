// Starter file for CSCI 60 Homework 1, Program 1; due Sunday 1/10/21
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include <fstream>
using namespace std;

void writeLineOfStars(int rolls[], int nRolls, int val, ostream &out)
{
  int num = 0;
  for (int i = 0; i < nRolls; i++)
  {
    if (rolls[i] == val)
      num++;
  }
  cout << val << ": " << num << endl;
}

int main(int argc, char *argv[])
{
  // check that user provided enough args and store them in local variables
  if (argc < 4)
  {
    cout << "This program requires at least 3 arguments\n";
    return 1;
  }

  int nRolls = stoi(argv[1]);
  string datafile = argv[2], histfile = argv[3]; // 2 filenames from args list

  /* TODO: Produce a histogram of the data and write it to the hist file */

  ifstream myfile(datafile);
  if (!myfile.is_open())
  {
    cout << "Open " << datafile << " failed." << endl;
    return -1;
  }

  int LEN_ROLLS = 12 - 2 + 1;
  int rolls_hist[LEN_ROLLS] = {0};

  string temp;
  while (getline(myfile, temp))
  {
    int val = stoi(temp); // 2, 2
    cout << val << endl;
    rolls_hist[val - 2]++; // 1, 2
  }

  for (int i = 0; i < LEN_ROLLS; i++)
  {
    cout << *right << i + 2 << ": " << string(rolls_hist[i], "*1") << endl;
  }

  return 0;
}
