#include <bits/stdc++.h>
using namespace std;

/*Signature Rules for LSP - Method Arguments*/
/* It states that a subclass should be able to accept the same or more wider(generic) arguments as its parent class. */

// example -> if a parent class method accepts an integer argument, the subclass method should also accept an integer or a more generic type like a float or double, but not a more specific type like a char or string.

class Parent
{
public:
  virtual void display(int value)
  {
    cout << "Parent class method with int argument: " << value << endl;
  }
  ~Parent()
  {
    cout << "Parent destructor called" << endl;
  }
};
class Child : public Parent
{
  // This class follows LSP because it accepts the same type of argument (int) as the parent class method. We can replace a Parent object with a Child object without breaking the application logic.
public:
  void display(int value) override
  {
    cout << "Child class method with int argument: " << value << endl;
  }
  ~Child()
  {
    cout << "Child destructor called" << endl;
  }
};

int main()
{
  Parent *parentPtr = new Child();
  parentPtr->display(42); // This will call the Child's display method, demonstrating that we can substitute Parent with Child without any issues.
  delete parentPtr;
  return 0;
}