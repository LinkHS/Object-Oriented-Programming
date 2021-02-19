// Implementation starter file for CSCI 60 Homework 4; due Tuesday 2/2/21
// List any collaborators and write your name here

#include "parity.h" // Don't add any additional libraries/namespaces!



// couts two lines of text representing the even and odd values, respectively
void Parity::printAll() const {
  std::cout << "Evens: ";
  for (size_t i=0; i<nEven_; i++) std::cout << evens_[i] << ", ";
  std::cout << "\nOdds:  ";
  for (size_t i=0; i<nOdd_; i++) std::cout << odds_[i] << ", ";
  std::cout << std::endl;
}

void Parity::insert(int val)
{
}