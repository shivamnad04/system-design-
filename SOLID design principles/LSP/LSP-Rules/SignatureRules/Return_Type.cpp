#include <bits/stdc++.h>
using namespace std;

/*Signature Rules for LSP - Return Type*/
/* It states that a subclass should be able to return the same or a more specific type as its parent class. */

// example -> if a parent class method returns an integer, the subclass method should also return an list or a more specific type like a ArrayList, but not a more generic.

class Parent
{
public:
  virtual vector<int> getValue()
  {
    return {42};
  }
};

class Child : public Parent
{
public:
  vector<int> getValue() override
  {
    return {100};
  }
};

int main()
{
  Parent *parentPtr = new Child();
  vector<int> value = parentPtr->getValue(); // This will call the Child's getValue method, demonstrating that we can substitute Parent with Child without any issues.
  cout << "Value from Child: " << value[0] << endl;
  delete parentPtr;
  return 0;
}