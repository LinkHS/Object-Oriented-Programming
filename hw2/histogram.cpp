// Implementation starter file for CSCI 60 Homework 2; due Sunday 1/17/21
// List any collaborators and write your name here

#include "histogram.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

Histogram::Histogram(string filename)
{
    memset(counts, 0, sizeof(counts));

    ifstream is_file(filename);
    if (!is_file.is_open())
    {
        cout << "Open " << filename << " failed." << endl;
        return;
    }

    cout << "Loading" << filename << "..." << endl;
    string temp;
    while (getline(is_file, temp))
    {
        int val = stoi(temp);
        counts[val]++;
    }
}

Histogram::Histogram()
{
    memset(counts, 0, sizeof(counts));
}

size_t Histogram::size() const
{
    //const size_t *p = counts;
    int sum = 0;
    for (size_t i = 0; i <= MAX; i++)
    {
        sum += counts[i] * i; // sum += *p++;
    }

    return sum;
}

size_t Histogram::min() const
{
    return 0;
}

size_t Histogram::median() const
{ // (the average of) the middle value(s)

}

double Histogram::mean() const
{ // arithmetic average of the values
}

void Histogram::operator+=(const Histogram &rhs)
{
    for (size_t i = 0; i <= MAX; i++)
    {
        counts[i] += rhs.counts[i];
    }
}

size_t Histogram::operator[](size_t val) const
{
    /* @return: times value occurs */
    assert((val >= 0) && (val <= MAX));
    return counts[val];
}