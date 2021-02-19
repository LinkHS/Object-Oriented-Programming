// Partial static array implementation of Bag.
// Sara Krehbiel + group work, 1/16/21 and 1/29/21 (F Week 4, file 3/3)

#include "bag.h"

// copy constructor deep-copies existing other bag contents into this new bag
Bag::Bag(const Bag& other) {
  size_ = other.size_;
  cap_ = other.cap_;
  data_ = new int[cap_];
  for (size_t i=0; i<size_; i++) {
    data_[i] = other.data_[i];
  }
}

// destructor releases memory and restores default values
Bag::~Bag() {
  delete [] data_;
  data_ = nullptr; // avoid leaving pointers pointing to released memory!
  size_ = cap_ = 0;
}

// assignment deep copies existing rhs contents into existing calling object
Bag& Bag::operator =(const Bag& rhs) {
  if (cap_ != rhs.cap_) { // check if you need a new block of memory
    cap_ = rhs.cap_;
    delete [] data_;
    data_ = new int[cap_];
  }
  size_ = rhs.size_;
  for (size_t i = 0; i<size_; i++) { // copy the contents of rhs into data_
    data_[i] = rhs.data_[i];
  }
  return *this; // return (reference to) updated self
}


// sweep the contents of bag, keeping track of # of occurences of target
size_t Bag::count(int target) const {
  size_t count = 0;
  for (size_t i = 0; i<size_; i++) {
    if (data_[i]==target) count++;
  }
  return count;
}

// add an element to the appropriate slot in the bag array
void Bag::insert(int target) {
  if (size_==cap_) {
    // get a new double-size array
    if (cap_==0) cap_ = 1;
    else cap_ *= 2;
    int *newArr = new int[cap_];
    for (size_t i = 0; i<size_; i++) {
      newArr[i] = data_[i];
    }
    delete [] data_;
    data_ = newArr;
  }
  data_[size_] = target;
  size_++;
}

// sweep data for target, shift everything after target back and decrement size
bool Bag::erase_one(int target) {
  for (size_t i=0; i<size_; i++) {
    if (data_[i]==target) {
      // shift everything after removed elem back one
      for (size_t j=i+1; j<size_; j++) {
        data_[j-1] = data_[j];
      }
      size_--;
      if (size_<=0.25*cap_) { // downsize if we aren't using much of the total capacity
        cap_ /= 2;
        int *newArr = new int[cap_];
        for (size_t i=0; i<size_; i++) {
          newArr[i] = data_[i];
        }
        delete [] data_;
        data_ = newArr;
      }
      return true;
    }
  }
  return false;

}

// call erase_one as many times as it takes to remove all copies of target
size_t Bag::erase(int target) {
  int k = 0;
  while (erase_one(target)) {
    k++;
  }
  return k;
}

// if space, insert everything from rhs into this object
void Bag::operator +=(const Bag & rhs) {
  //if (size_ + rhs.size_ <= CAPACITY) {
    // add contents of rhs to data_
    for (size_t i = 0; i<rhs.size_; i++) {
      // add an element of rhs to this object
      insert(rhs.data_[i]);
    }
//  }
}

// if space, create/populate/return a bag with the combined contents of lhs+rhs
Bag operator +(const Bag & lhs, const Bag & rhs) {
  Bag b; // this is an empty bag to populate and return
  size_t lsize = lhs.size(), rsize = rhs.size();
//  if (lsize + rsize <= Bag::CAPACITY) {
    // insert all contents of lhs
    for (size_t i=0; i<lsize; i++) {
      b.insert(lhs[i]);
    }
    // then insert all contents of rhs
    for (size_t i=0; i<rsize; i++) {
      b.insert(rhs[i]);
    }
//  }
  return b; // empty if lhs+rhs wouldn't have fit
}

// overload insertion operator << to insert bag contents into an ostream
ostream& operator <<(ostream& out, const Bag& b) {
  size_t n = b.size();
  for (size_t i=0; i<n; i++) {
    out << b[i]; // use << for numbers/strings in defining it for a whole bag
    out << " ";
  }
  return out;
}
