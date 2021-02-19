// Interface for *dynamic* array implementation of a container called Bag,
// which doubles and halves in size as necessary to holds ints
//
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran
// 1/29/21 (F Week 4, file 2/3)

#ifndef BAG_H
#define BAG_H

#include <ostream>

// avoid using the whole std namespace
using std::size_t;
using std::ostream;

class Bag {
public:
  // STATIC CONSTANT
  //static const size_t CAPACITY = 6;

  // CONSTRUCTORS AND DYNAMIC MEMORY MANAGEMENT FUNCTIONS
  Bag() : data_(nullptr), size_(0), cap_(0) {} // create an empty bag
  Bag(const Bag& other);// copy constructor
  ~Bag(); // destructor
  Bag& operator =(const Bag& rhs); // assignment

  // CONSTANT ACCESSOR MEMBER FUNCTIONS
  size_t size() const { return size_; }
  size_t cap() const { return cap_; }
  size_t count(int target) const; // #copies of target
  int operator [](size_t pos) const { return data_[pos]; }

  // MUTATOR MEMBER FUNCTIONS
  void insert(int target); // add a copy of target, doubling cap if needed
  bool erase_one(int target); // remove a copy of target, halving cap if needed
  size_t erase(int target); // remove all k copies of target and return k
  void operator +=(const Bag & rhs); // add rhs contents

private:
  int *data_; // the address of the bag on the heap
  size_t size_; // the number of elements in the bag
  size_t cap_; // the number of cells allocated to the data array (on the heap)

  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements
  //             cap_ elems are allocated on the heap, addressed by data_,
  //             where cap_ is a power of two with cap_/4<=size_<=cap_
};

Bag operator +(const Bag & lhs, const Bag & rhs); // combine contents of 2 bags

ostream& operator <<(ostream& out, const Bag& b); // output contents to ostream

#endif
