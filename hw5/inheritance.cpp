// Task: Introduce the concept of inheritance and related rules/syntax
//       1/ A child class inherits its parents member fields
//       2/ A child can have additional member fields
//       3/ A child can redefine parent functions
//       4/ A child constructor can delegate to the parent
//
// Sara Krehbiel, 2/1/21 (M Week 5, file 1/2)

#include <string>
#include <iostream>
using namespace std;

// has a name; can report name and post to facebook
class Person {
public:
  Person(string name) : name(name) {}
  Person() : Person("-") {}
  string getName() { return name; }
  void postToFB(string msg) { cout << msg << endl; }
private:
  string name;
};

class Student : public Person {
public:
  Student(int id) : Person(), id(id) {}
private:
  int id;
};

// has a name & an insta handle; can report name, post to FB, & advertise
class Influencer : public Person {
public:
  Influencer() : Person(), handle("user") {}
  Influencer(string name, string handle) : Person(name), handle(handle) {}
  //string getName() { return name; }
  void postToFB(string msg);
  void advertise() { cout << "shop this look! links in bio!!!\n"; }
private:
  //string name;
  string handle;
};

void Influencer::postToFB(string msg) {
  cout << msg << "\nAnd follow me on insta @" << handle << " xoxo :-)\n";
}

int main() {
  Person parent("Dad");
  cout << parent.getName() << "\'s post: ";
  parent.postToFB("HOW DO I ADD PHOTO");

  Influencer child("kiddo","eatpraylove");
  cout << child.getName() << "\'s post: ";
  child.postToFB("a lot of you have been asking about my skincare routine");
  child.advertise();
  return 0;
}
