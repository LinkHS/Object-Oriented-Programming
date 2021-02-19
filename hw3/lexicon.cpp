// Implementation starter file for CSCI 60 Homework 3; due Sunday 1/24/21
// List any collaborators and write your name here

#include "lexicon.h"
#include <cstring>

using namespace std;

Lexicon::Lexicon(string filename)
{
  memset(data_, 0, sizeof(data_));

  ifstream is_file(filename.data());
  if (!is_file.is_open())
  {
    cout << "Open " << filename << " failed." << endl;
    return;
  }

  cout << "Loading " << filename << "..." << endl;

  size_ = 0;
  std::string word;
  while ((is_file >> word) && (size_ < CAPACITY))
  {
    if (contains(word))
      continue;
    data_[size_++] = word;
  }
}

bool Lexicon::contains(string word) const
{
  for (int i = 0; i < size_; i++)
  {
    if (strcmp(word.data(), data_[i].data()) == 0)
    {
      return true;
    }
  }
  return false;
}

Lexicon Lexicon::operator | (const Lexicon& rhs) const
{
}

// Inserts contents of lex in out in order, separated by spaces
ostream &operator<<(ostream &out, const Lexicon &lex)
{
  size_t n = lex.size();
  for (size_t i = 0; i < n; i++)
  {
    out << lex[i] << " ";
  }
  return out;
}
